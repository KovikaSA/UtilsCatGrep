#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int ret = 0;
  flg_t flg = {0};
  int line_number = 1;
  int last_char = '\n';

  ret = flg_parser(argc, argv, &flg);

  if (flg.b) {
    flg.n = 0;
  }

  while (optind < argc) {
    ret = read_file(argv[optind], &flg, &line_number, &last_char);
    last_char = '\0';
    optind++;
  }

  return ret;
}