#include <stdio.h>
#define MAXLINE 1000

int reverse(char str[], int lim);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = reverse(line, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);

  return 0;
}

/* reverses a string of chars */
int reverse(char str[], int lim) {
  int c, i, j, k;
  char temp[MAXLINE];
  i = j = k = 0;
  
  while ((c = getchar()) != EOF && c != '\n') {
    if (j < lim)
      str[j++] = c;
    if (c != ' ' && c != '\t')
      i = j;
  }

  if (c == '\n' && i++ < lim)
    str[i - 1] = '\n';
  str[(i < lim) ? i : lim - 1] = '\0';

  while ((c = str[k]) != '\n') {
    temp[k++] = c;
  }
  temp[k] = c;
  k--;
  i = 0;

  while (k >= 0) {
    str[i++] = temp[k--];
  }
  str[i++] = '\n';
  str[i] = '\0';

  return i;
}
