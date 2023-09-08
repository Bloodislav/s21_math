#include "s21_math.h"

// This function does not implement checks for nan and inf
// because all the checks are implemented in sin and cos
long double s21_tan(double x) {
  long double present_x = s21_fmod(x, 2 * S21_M_PI);
  long double result = s21_sin((double)present_x) / s21_cos((double)present_x);
  return (double)result;
}