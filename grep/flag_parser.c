#include "s21_grep.h"

int flg_parser(int argc, char *argv[], flg_t *flg) {
  int ret = 0;
  int c;
  for (; (c = getopt(argc, argv, "e:ivclnhsf:o")) != -1;) {
    switch (c) {
      case 'e':
        flg->e = 1;
        add_pattern(flg, optarg);
        break;
      case 'i':
        flg->i = REG_ICASE;
        break;
      case 'v':
        flg->v = 1;
        break;
      case 'c':
        flg->c = 1;
        break;
      case 'l':
        flg->l = 1;
        break;
      case 'n':
        flg->n = 1;
        break;
      case 'h':
        flg->h = 1;
        break;
      case 's':
        flg->s = 1;
        break;
      case 'f':
        flg->f = 1;
        add_pattern_from_file(flg, optarg);
        break;
      case 'o':
        flg->o = 1;
        break;
      default:
        ret = 1;
        break;
    }
  }

  if (flg->len_pattern == 0) add_pattern(flg, argv[optind++]);

  if (argc - optind == 1) flg->h = 1;

  return ret;
}