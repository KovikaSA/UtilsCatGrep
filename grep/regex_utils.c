#include "s21_grep.h"

void create_regex(const flg_t *flg, int argc, char **argv) {
  int ret = 0;
  int file_count = argc - optind;
  regex_t reg;
  int cflags = REG_NEWLINE | REG_EXTENDED | (flg->i ? REG_ICASE : 0);

  char pattern[1024];
  if (flg->f) {
    escape_special_chars(flg->pattern, pattern);
  } else {
    snprintf(pattern, sizeof(pattern), "%s", flg->pattern);
  }

  ret = regcomp(&reg, pattern, cflags);
  if (ret != 0) {
    fprintf(stderr, "Error compiling regex\n");
    return;
  }

  for (int i = optind; i < argc; i++) {
    output(flg, argv[i], &reg, file_count);
  }

  regfree(&reg);
}

void escape_special_chars(const char *src, char *dest) {
  char *ptr_dest = dest;
  const char *ptr_src = src;
  while (*ptr_src != '\0') {
    if (*ptr_src == '\\' || *ptr_src == '{' || *ptr_src == '}') {
      *ptr_dest++ = '\\';
    }
    *ptr_dest++ = *ptr_src++;
  }
  *ptr_dest = '\0';
}

bool add_pattern(flg_t *flg, const char *pattern) {
  bool success = true;

  if (pattern == NULL) {
    success = false;
  } else {
    int n = strlen(pattern);
    if (flg->len_pattern == 0) {
      flg->pattern = malloc(1024 * sizeof(char));
      if (flg->pattern == NULL) {
        perror("Failed to allocate memory");
        success = false;
      } else {
        flg->pattern[0] = '\0';
        flg->mem_pattern = 1024;
      }
    }

    if (success && flg->mem_pattern < flg->len_pattern + n + 3) {
      flg->mem_pattern *= 2;
      char *temp = realloc(flg->pattern, flg->mem_pattern);
      if (temp == NULL) {
        perror("Failed to reallocate memory");
        free(flg->pattern);
        flg->pattern = NULL;
        success = false;
      } else {
        flg->pattern = temp;
      }
    }

    if (success) {
      if (flg->len_pattern != 0) {
        strcat(flg->pattern, "|");
        flg->len_pattern++;
      }

      flg->len_pattern +=
          sprintf(flg->pattern + flg->len_pattern, "(%s)", pattern);
    }
  }

  return success;
}

void add_pattern_from_file(flg_t *flg, const char *path) {
  FILE *file = fopen(path, "r");
  if (!file) {
    if (!flg->s) fprintf(stderr, "No such file or directory\n");
    return;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read = getline(&line, &len, file);

  while (read != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    add_pattern(flg, line);
    read = getline(&line, &len, file);
  }

  free(line);
  fclose(file);
}

void output_line(const char *line, int len) {
  fwrite(line, sizeof(char), len, stdout);
  if (line[len - 1] != '\n') putchar('\n');
}