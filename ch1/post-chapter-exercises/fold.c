/* exercise 1-22 from K&R 2nd edition */

/* Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs
 * before the n-th column of input. Make sure your program does
 * something intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column. */

/* Implementation note: it made more sense to me to "fold" each
 * line on a blank character, so that individual words are kept
 * whole */

#include <stdio.h>

#define MAXLINE 1000   /* maximum input line size */
#define FOLD_LENGTH 20 /* max number of characters in a folded line */

int fold(char str[], int fold, int lim);

int main(void) {
  int len;
  char line[MAXLINE];

  while ((len = fold(line, FOLD_LENGTH, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);
  return 0;
}

/* folds long input lines into two or more shorter lines */

/* TODO: for some reason, this doesn't intelligently handle
 * lines that have mixed long words and shorted words with
 * spaces. */
int fold(char str[], int fold, int lim) {
  int c, i, l;
  int lastblank;
  i = l = lastblank = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (c == ' ' || c == '\t')
      lastblank = i;

    str[i++] = c;
    ++l;

    if (l >= fold) {
      if (lastblank > 0) {
        str[lastblank] = '\n';
        l = i - lastblank;
      } else {
        str[i++] = '-';
        str[i++] = '\n';
        l = 0;
      }
    }
  }
  str[i++] = '\n';
  str[i] = '\0';

  return i;
}
