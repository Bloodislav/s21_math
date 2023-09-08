#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_fabs(double x) {
  union ieee854_long_double x854;
  x854.d = x;
  if (x854.ieee.negative) x854.ieee.negative = 0;
  return x854.d;
}
