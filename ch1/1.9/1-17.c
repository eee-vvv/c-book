#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define MINPRINT 80  /* minimum line length to print */

int my_getline(char line[], int maxline);
int append(char to[], char from[], int i);

/* print longest input line */
int main(void) {
  int len;             /* current line length */
  char line[MAXLINE];  /* current input line */

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (len > MINPRINT)
      printf("LINE IS GREATER THAN 80 CHARS:\n%s\n", line);
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
