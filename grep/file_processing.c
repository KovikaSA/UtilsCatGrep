#include "s21_grep.h"

void output(const flg_t *flg, const char *path, regex_t *reg, int file_count) {
  FILE *file = fopen(path, "r");
  if (!file) {
    if (!flg->s) {
      fprintf(stderr, "No such file or directory\n");
    }
    return;
  }

  int match_count = 0;
  int is_single_file = (file_count == 1);

  process_file(flg, file, reg, path, is_single_file, &match_count);

  fclose(file);

  print_summary(flg, path, match_count, is_single_file);
}

void process_file(const flg_t *flg, FILE *file, regex_t *reg, const char *path,
                  int is_single_file, int *match_count) {
  char *line = NULL;
  size_t len = 0;
  int line_count = 1;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    process_line(flg, line, reg, path, line_count, is_single_file, match_count);
    line_count++;
  }

  free(line);
}

void process_line(const flg_t *flg, const char *line, regex_t *reg,
                  const char *path, int line_count, int is_single_file,
                  int *match_count) {
  int result = regexec(reg, line, 0, NULL, 0);
  bool is_match = (result == 0 && !flg->v) || (flg->v && result != 0);

  if (!is_match) {
    return;
  }

  (*match_count)++;

  if (flg->c || flg->l) {
    return;
  }

  if (flg->o) {
    match_parts(reg, line, flg, path, line_count, is_single_file);
  } else {
    if (!is_single_file && !flg->h) {
      printf("%s:", path);
    }
    if (flg->n) {
      printf("%d:", line_count);
    }
    output_line(line, strlen(line));
  }
}

void print_summary(const flg_t *flg, const char *path, int match_count,
                   int is_single_file) {
  if (flg->c && !flg->l) {
    if (!is_single_file && !flg->h) {
      printf("%s:", path);
    }
    printf("%d\n", match_count);
  }

  if (flg->l && match_count > 0) {
    printf("%s\n", path);
  }
}

void match_parts(regex_t *reg, const char *line, const flg_t *flg,
                 const char *path, int line_number, int is_single_file) {
  regmatch_t match;
  const char *p = line;
  while (regexec(reg, p, 1, &match, 0) == 0) {
    if (!is_single_file && !flg->h) printf("%s:", path);
    if (flg->n) printf("%d:", line_number);
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(p[i]);
    }
    putchar('\n');
    p += match.rm_eo;
  }
}
