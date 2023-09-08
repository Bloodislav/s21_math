#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  union ieee754_double x754, x754_full = {0};

  // Create a copy
  x754.d = x;

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Checking for х = +-nan
  if ((x754.ieee_nan.exponent == x754_full.ieee.exponent) &&
      (x754.ieee_nan.quiet_nan))
    result = x;

  // Checking for x = +-inf
  else if ((x754.ieee_nan.exponent == x754_full.ieee.exponent) &&
           (x754.ieee_nan.mantissa0 == 0)) {
    if (x754.ieee_nan.negative)
      result = 0;
    else
      result = S21_INF;
  }

  else {
    // Initialize the necessary variables
    long double temp = 1, prev_result = 0, epsilon = 1e-20, n = 1;
    unsigned short is_neg = 1 * x754.ieee.negative;

    // Remove the sign of the incoming variable
    x754.d = (double)s21_fabs(x754.d);

    while (s21_fabs((double)(result - prev_result)) > epsilon) {
      prev_result = result;
      temp *= x754.d / n++;
      result += temp;
    }

    if (is_neg) result = 1 / result;
  }

  return (double)result;
}
