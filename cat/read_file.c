#include <stdio.h>

#include "s21_cat.h"

int read_file(const char *filename, const flg_t *flg, int *line_number,
              int *last_char) {
  FILE *file = fopen(filename, "r");
  int ret = 0;
  if (!file) {
    perror("Error opening file");
    ret = 1;
  } else {
    int empty_line_count = 0;
    int ch = fgetc(file);

    while (ch != EOF) {
      if (flg->s && *last_char == '\n' && ch == '\n') {
        if (++empty_line_count > 1) {
          ch = fgetc(file);
          continue;
        }
      } else {
        empty_line_count = 0;
      }

      process_char(ch, line_number, flg, *last_char);
      *last_char = ch;
      ch = fgetc(file);
    }

    fclose(file);
  }

  return ret;
}