#include "s21_ieee754.h"
#include "s21_math.h"

long double s21_pow(double base, double exp) {
  double result = 1, mod_exp = (double)s21_fabs((double)s21_fmod(exp, 1.0));
  union ieee754_double copy_base, copy_exp, x754_full = {0};

  // Create a copy
  copy_base.d = base;
  copy_exp.d = (double)s21_fabs(exp);

  // (1 << 11) - 1 = 2047
  x754_full.ieee.exponent = (1 << 11) - 1;

  // Checking for 1 in pow and base
  if ((s21_fabs(copy_exp.d - 1.0) < S21_MIN_VAL) ||
      (base > 0 && s21_fabs(copy_base.d - 1.0) < S21_MIN_VAL)) {
    if (exp > 0)
      result = base;
    else
      result = 1 / base;
  }

  // Checking for exp = 0
  else if (s21_fabs((double)(copy_exp.d - 0)) < S21_MIN_VAL)
    result = 1;

  // Checking for base = +-nan
  else if ((copy_base.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_base.ieee_nan.quiet_nan))
    result = base;

  // Checking for exp = +-nan
  else if ((copy_exp.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_exp.ieee_nan.quiet_nan))
    result = exp;

  // Checking for base = +-inf
  else if ((copy_base.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_base.ieee.mantissa0 == 0)) {
    if (exp > 0)
      result = base;
    else
      result = 0;
  }

  // Checking for exp = +-inf
  else if ((copy_exp.ieee.exponent == x754_full.ieee.exponent) &&
           (copy_exp.ieee.mantissa0 == 0)) {
    // If base = -1
    if (s21_fabs((double)(copy_base.d + 1)) < S21_MIN_VAL)
      result = 1.0;
    else if ((exp < 0 && s21_fabs(base) > 1) || (exp > 0 && s21_fabs(base) < 1))
      result = 0.0;
    else
      result = S21_INF;
  }

  // Checking for base < 0 and exp is not an entire number
  else if ((base < 0) && (mod_exp > 0))
    result = -S21_NAN;

  /*
    After all validations, the result is calculated.
    Calculation method: "Fast erection" of the integer part of exp +
    + multiplication by e^(exp * log(base)) of the fractional part of exp.
  */
  else {
    // We get the integer part of the number
    unsigned long long int exp_round = (unsigned long long int)copy_exp.d;

    // Check if the integer part is equal to 0
    unsigned short int stop = (exp_round == 0);

    /*
      Then depending on the check, there are 2 cases:
        1. If the integer part is 0, then result remains equal to 1 and exp_ask
      = 0.
        2. If the integer part is not equal to 0, then we initialize for
      geom.progression. The geom. progression starts from the second degree
      (i.e. base ^ 2).
    */
    unsigned long long int exp_ask = 2 * !stop;
    result = (copy_base.d * copy_base.d) * !stop + stop;

    double result_temp = 0;
    unsigned long long int exp_temp = 0;

    /*
      Then we make a quick approach to the final result
      by while loops. The methods of calculation, in each of the while loops,
      are described below.

      In each of the while loops, we check the stop condition, which
      signals that we are approaching inf
      (in terms of exceeding the maximal allowed double's
      value).
    */

    // 1. We're multiplying exponentially.
    // (i.e. base ^ exp_ask, where exp_ask will be equal to: 2, 4, 8, 16, 32
    // ...)
    while (!stop && (exp_temp = exp_ask * 2) <= exp_round) {
      result_temp = (double)s21_fabs(result * result);
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // 2. Домножаемся квадратами base
    // (i.e.. base ^ exp_ask, where exp_ask will be equal to: 32, 34, 36, 38, 40
    // ...)
    while (!stop && (exp_temp = exp_ask + 2) <= exp_round) {
      result_temp = (double)s21_fabs((result * (copy_base.d * copy_base.d)));
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // 3. Домножаемся просто base
    // (i.e.. base ^ exp_ask, where exp_ask will be equal to: 40, 41)
    while (!stop && (exp_temp = exp_ask + 1) <= exp_round) {
      result_temp = (double)s21_fabs((result * copy_base.d));
      stop = (result_temp > S21_DBL_MAX);
      exp_ask = exp_temp;
      result = result_temp;
    }

    // If while loops work and stop == 1,
    // then we are close to infinity
    if (exp_ask != 0 && stop) result = S21_INF;

    // We perform multiplication if there is a fractional part of exp
    if (mod_exp > 0)
      result *= (double)s21_exp((mod_exp * (double)s21_log(copy_base.d)));

    // If the degree is negative
    if (exp < 0) result = 1 / result;
  }

  return result;
}
