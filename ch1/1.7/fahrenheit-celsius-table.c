#include <stdio.h>

void convertFtoC(int l, int u, int s);

/* test convertFtoC */
int main() {
  int lower, upper, step;

  lower = 0;   /* lower limit of temperature table */
  upper = 300; /* lower limit of temperature table */
  step = 20;   /* lower limit of temperature table */

  convertFtoC(lower, upper, step);

  return 0;
}

/* print Fahrenheit-Celius table */
void convertFtoC(int lower, int upper, int step) {
  float fahr, celsius;
  char f, c;

  f = 'F';
  c = 'C';
  printf("%3c %6c\n", f, c);

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
