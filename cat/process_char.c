#include <stdio.h>

#include "s21_cat.h"

void process_char(int ch, int *line_number, const flg_t *flg, int last_char) {
  if (last_char == '\n' && ((flg->b && ch != '\n') || flg->n)) {
    printf("%6d\t", (*line_number)++);
  }

  if (flg->t && ch == '\t') {
    printf("^I");
  } else if (flg->e && ch == '\n') {
    printf("$\n");
  } else if (flg->v) {
    if (ch < 32 && ch != '\t' && ch != '\n') {
      printf("^%c", ch + 64);
    } else if (ch == 127) {
      printf("^?");
    } else if (ch >= 128 && ch <= 159) {
      printf("M-^%c", (ch - 128 + 64));
    } else if (ch >= 160) {
      printf("M-%c", ch - 128);
    } else {
      printf("%c", ch);
    }
  } else {
    printf("%c", ch);
  }
}