#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_ceil(double x) {
  double result = 0;
  union ieee754_double copy_x, x754_full = {0};

  // Create a copy
  copy_x.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Maximum permissible value 1e18
  if (copy_x.d > 1e18) result = copy_x.d;

  // Checking for х = +-inf
  else if ((copy_x.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (copy_x.ieee_nan.mantissa0 == 0))
    result = x;

  else {
    double mod = (double)s21_fmod(copy_x.d, 1.0);
    result = copy_x.d - mod + 1 * (((s21_fabs(mod) > 0) && x > 0));
  }
  return result;
}