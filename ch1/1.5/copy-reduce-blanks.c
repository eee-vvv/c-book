#include <stdio.h>

/* copies input to output, replacing each string
 * of one or more blanks by a single blank */
int main() {
  int c, last;

  last = 'x';
  while ((c = getchar()) != EOF) {
    if (last == ' ') {
      if (c == ' ') {
        ;
      } else {
        putchar(c);
      }
    } else {
      putchar(c);
    }
    last = c;
  }
}
