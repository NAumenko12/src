#include "s21_grep.h"

int main(int argc, char **argv) {
  Flags flags = parse_flags(argc, argv);
  output(flags, argc, argv);
  return 0;
}