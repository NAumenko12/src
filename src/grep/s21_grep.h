#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_SIZE 4096
#define MAX_FILE_PATH_SIZE 4096
#define MAX_LINE_SIZE 4096

typedef struct Flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char pattern[MAX_PATTERN_SIZE];
  int len_pattern;
} Flags;

void add_pattern(Flags *flags, char *pattern);
void load_patterns_from_file(Flags *flags, char *filepath);
Flags parse_flags(int argc, char *argv[]);
void print_line(char *line, int n);
void print_regex_match(regex_t *re, char *line);
void processFile(Flags flags, char *path, regex_t *reg);
void output(Flags flags, int argc, char **argv);

#endif