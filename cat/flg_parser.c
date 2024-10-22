#include <getopt.h>

#include "s21_cat.h"

int flg_parser(int argc, char *argv[], flg_t *flg) {
  int ret = 0;
  int c;
  static struct option options[] = {{"number-nonblank", 0, 0, 'b'},
                                    {"number", 0, 0, 'n'},
                                    {"squeeze-blank", 0, 0, 's'},
                                    {0, 0, 0, 0}};

  while ((c = getopt_long(argc, argv, "bEnsTvet", options, NULL)) != -1) {
    switch (c) {
      case 'b':
        flg->b = 1;
        break;
      case 'E':
        flg->e = 1;
        break;
      case 'n':
        flg->n = 1;
        break;
      case 's':
        flg->s = 1;
        break;
      case 'T':
        flg->t = 1;
        break;
      case 'v':
        flg->v = 1;
        break;
      case 'e':
        flg->e = 1;
        flg->v = 1;
        break;
      case 't':
        flg->t = 1;
        flg->v = 1;
        break;
      default:
        ret = 1;
        break;
    }
  }

  return ret;
}