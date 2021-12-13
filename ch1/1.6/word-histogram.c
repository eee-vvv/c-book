#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* print a histogram of the lenghts of words in input */
/* CURRENT LIMIT: can only count up to 20 words */
int main() {
  int c, state, count, i, j, wc;
  int words[20];

  state = OUT;
  count = 0;
  wc = 0;
  for (i = 0; i < 20; ++i)
    words[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN)
        words[wc] = count;
      state = OUT;
      count = 0;
    } else if (state == OUT) {
      state = IN;
      count += 1;
      wc += 1;
    } else {
      count += 1;
    }
  }

  printf("\nLength of each word in the input:\n");
  printf("_________________________________\n");
  for (i = 0; i < 20; ++i) {
    if (words[i] > 0) {
      printf("%3d | ", (i));
      for (j = 0; j < words[i]; ++j)
        printf("*");
      printf("\n");
    }
  }
}
