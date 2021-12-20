#include <stdio.h>
#define MAXLINE 20 /* maximum input line size */

int my_getline(char s[], int lim);
void copy(char to[], char from[]);

/* print longest input line */
int main(void) {
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  char temp[MAXLINE];
  int len, max, prevmax, getmore;

  max = prevmax = getmore = 0;
  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (line[len - 1] != '\n') {
      if (getmore == 0)
        copy(temp, line);
      prevmax += len;
      if (max < prevmax)
        max = prevmax;
      getmore = 1;
    } else {
      if (getmore == 1) {
        if (max < prevmax + len) {
          max = prevmax + len;
          copy(longest, temp);
          longest[MAXLINE - 2] = '\n';
        }
        getmore = 0;
      } else if (max < len) {
        max = len;
        copy(longest, line);
      }
      prevmax = 0;
    }
  }

  if (max > 0) {
    printf("%s", longest);
    printf("len = %d\n", max);
  }

  return 0;
}

/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
