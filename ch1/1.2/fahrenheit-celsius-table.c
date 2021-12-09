#include <stdio.h>

/* print Fahrenheit-Celius table
 * for fahr-  = 0, 20, ..., 300 */
main()
{
  float fahr, celsius;
  int lower, upper, step;
  char f, c;

  lower = 0;      /* lower limit of temperature table */
  upper = 300;      /* lower limit of temperature table */
  step = 20;      /* lower limit of temperature table */

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
