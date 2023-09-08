#include "s21_math.h"

long double s21_sqrt(double x) {
  double result = 0;

  // Checking for a negative
  if (x < 0)
    result = -S21_NAN;
  else
    result = (double)s21_pow(x, 0.5);

  return result;
}