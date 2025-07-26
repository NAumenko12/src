#include "s21_grep.h"

void add_pattern(Flags *flags, char *pattern) {
  int n = strlen(pattern);

  if (flags->len_pattern + n + 2 >= MAX_PATTERN_SIZE) {
    fprintf(stderr,
            "Буфер для патерна переполнен. Макс MAX_PATTERN_SIZE.(4096)\n");
    return;
  }
  if (flags->len_pattern != 0) {
    strcat(flags->pattern + flags->len_pattern, "|");
    flags->len_pattern++;
  }
  flags->len_pattern +=
      sprintf(flags->pattern + flags->len_pattern, "(%s)", pattern);
}

void load_patterns_from_file(Flags *flags, char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    if (!flags->s) {
      perror(filepath);
    }
    return;
  }
  char line[MAX_LINE_SIZE];
  while (fgets(line, sizeof(line), f)) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    add_pattern(flags, line);
  }
  fclose(f);
}

Flags parse_flags(int argc, char *argv[]) {
  Flags flags = {0};
  flags.pattern[0] = '\0';
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        flags.e = 1;
        add_pattern(&flags, optarg);
        break;
      case 'i':
        flags.i = REG_ICASE;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        load_patterns_from_file(&flags, optarg);
        break;
      case 'o':
        flags.o = 1;
        break;
      default:
        printf("Usage: 21_grep [-eivclnhsfo] [file..]\n");
        break;
    }
  }
  if (flags.len_pattern == 0) {
    add_pattern(&flags, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    flags.h = 1;
  }
  return flags;
}