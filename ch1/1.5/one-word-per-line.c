#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() {
  int c, last;

  last = '0';
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t') {
      if (last != ' ' && last != '\t') {
        putchar('\n');
      }
    }
    else {
      putchar(c);
    }
    last = c;
  }
}
