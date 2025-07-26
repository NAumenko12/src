#ifndef SRC_CAT_FLAGS_H_
#define SRC_CAT_FLAGS_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int E;
  int n;
  int s;
  int T;
  int v;
} Flags;

Flags parse_options(int argc, char **argv, int *error_flag);
char char_process_nonprinting(char ch);
void print_line(Flags *flags, char *line, int len);
void process_file(Flags *flags, char **argv);

#endif