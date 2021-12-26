#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define SPACES 4     /* number of spaces to replace tab with */

int entab(char str[], int spaces, int lim);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = entab(line, SPACES, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);
  return 0;
}

/* replaces spaces in input with proper number of tabs */
int entab(char str[], int spaces, int lim) {
  int c, i, s;
  i = s = 0;

  // something still isn't quite right here...
  while ((c = getchar()) != EOF && c != '\n') {
    str[i++] = c;
    if (c == ' ') {
      ++s;
      if (s == spaces) {
        str[i - spaces] = '\t';
        i -= spaces - 1;
        s = 0;
      }
    } else {
      s = 0;
    }
  }
  str[i++] = '\n';
  str[i] = '\0';

  return i;
}
