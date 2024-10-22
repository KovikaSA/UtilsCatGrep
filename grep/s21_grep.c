#include "s21_grep.h"

int main(int argc, char *argv[]) {
  int ret = 0;
  flg_t flg = {0};
  int result = flg_parser(argc, argv, &flg);
  if (result != 0) {
    perror("Error parsing flags.\n");
    ret = 1;
  } else {
    create_regex(&flg, argc, argv);
    free(flg.pattern);
  }

  return ret;
}