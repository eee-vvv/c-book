#include <stdio.h>
#define MAXLINE 1000

int my_getline(char [], int);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len > 1) {
      printf("%s", line);
    }
  }
  return 0;
}

/* my_getline: read a line into s, trimming blank spaces off end and deleting blanks, return length */
int my_getline(char str[], int lim) {
  int c, i, j;

  i = j = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (j < lim)
      str[j++] = c;
    if (c != ' ' && c != '\t')
      i = j;
  }

  if (c == '\n' && i++ < lim)
    str[i - 1] = '\n';
  str[(i < lim) ? i : lim - 1] = '\0';
  return i;
}
