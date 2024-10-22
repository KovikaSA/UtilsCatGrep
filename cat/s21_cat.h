#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdio.h>

typedef struct {
  int b, e, n, s, t, v;
} flg_t;

int flg_parser(int argc, char *argv[], flg_t *flg);
void process_char(int ch, int *line_number, const flg_t *flg, int last_char);
int read_file(const char *filename, const flg_t *flg, int *line_number,
              int *last_char);
#endif