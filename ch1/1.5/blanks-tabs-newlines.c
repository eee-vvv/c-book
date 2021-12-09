#include <stdio.h>

/* counts blanks, tabs, and newlines */
int main() {
  int c, b, t, nl;

  b = 0;
  t = 0;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++b;
    else if (c == '\t')
      ++t;
    else if (c == '\n')
      ++nl;
  }
  printf("blank: %d\n", b);
  printf("tab: %d\n", t);
  printf("newline: %d\n", nl);
}
