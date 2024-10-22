#ifndef S21_GREP_H
#define S21_GREP_H
#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e, i, v, c, l, n, h, s, f, o;
  char *pattern;
  int len_pattern;
  int mem_pattern;
} flg_t;

int flg_parser(int argc, char *argv[], flg_t *flg);
void create_regex(const flg_t *flg, int argc, char **argv);
void output(const flg_t *flg, const char *path, regex_t *reg, int file_count);
void process_file(const flg_t *flg, FILE *file, regex_t *reg, const char *path,
                  int is_single_file, int *match_count);
void process_line(const flg_t *flg, const char *line, regex_t *reg,
                  const char *path, int line_count, int is_single_file,
                  int *match_count);
void print_summary(const flg_t *flg, const char *path, int match_count,
                   int is_single_file);
bool add_pattern(flg_t *flg, const char *pattern);
void add_pattern_from_file(flg_t *flg, const char *path);
void escape_special_chars(const char *src, char *dest);
void match_parts(regex_t *reg, const char *line, const flg_t *flg,
                 const char *path, int line_number, int is_single_file);
void output_line(const char *line, int len);

#endif