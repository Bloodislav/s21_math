#include "s21_math.h"

int s21_abs(int x) {
  int result = x;
  if (x < 0) result = -x;
  return result;
}