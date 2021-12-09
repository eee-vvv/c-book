#include <stdio.h>

main() {
  float celsius, fahr;
  int lower, upper, step;
  char f, c;

  lower = 0;
  upper = 300;
  step = 20;

  c = 'C';
  f = 'F';
  printf("%3c %6c\n", c, f);

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
