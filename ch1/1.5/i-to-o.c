#include <stdio.h>

/* copy input to output; second version */
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
