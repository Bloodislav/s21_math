#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;

  /*
    The area of the cosine value is found on the interval from -1 to 1
    inclusive, so x must be in that range.

    The most important thing is to check the value area.
    The rest of the validation on +-NAN, +-INF and +-1
    will take place in the s21_asin function.
  */
  if ((x > -1 && x < 1) || (s21_fabs((double)s21_fabs(x) - 1) < S21_MIN_VAL))
    // The basic formula for calculating: acos = pi/2 - atan(x / sqrt(1 - x^2))
    result = S21_M_PI_2 -
             s21_atan(x / (double)s21_sqrt(1.0 - (double)s21_pow(x, 2)));
  else
    result = s21_fabs(S21_NAN);

  return (double)result;
}