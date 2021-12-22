#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define SPACES 4     /* number of spaces to replace tab with */

int detab(char str[], int spaces, int lim);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = detab(line, SPACES, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);

  return 0;
}

/* replaces tabs in input with proper number of blank spaces */
int detab(char str[], int spaces, int lim) {
  int c, i, s;
  i = s = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (c == '\t') {
      for (s = 0; s < spaces; ++s) {
        str[i++] = ' ';
      }
    } else {
      str[i++] = c;
    }
  }
  str[i++] = '\n';
  str[i] = '\0';

  return i;
}
