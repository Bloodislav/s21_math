#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(test_ceil_zero_pos) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), TEST_EPS);
}
END_TEST

START_TEST(test_ceil_zero_neg) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), TEST_EPS);
}
END_TEST

START_TEST(test_ceil_inf_pos) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_inf_neg) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_nan_pos) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(test_ceil_nan_neg) {
  double x = (double)s21_fabs(S21_NAN);
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(test_inf) {
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_infinite(ceil(S21_INF));
}
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(ceil(S21_NAN));
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(a * i), s21_ceil(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(-a * i), s21_ceil(-a * i), TEST_EPS);
}
END_TEST

START_TEST(test_ceil_dbl_max) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(test_ceil_dbl_min) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

Suite *suite_ceil(void) {
  Suite *s = suite_create("suite_ceil");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, test_ceil_zero_pos);
  tcase_add_test(tc, test_ceil_zero_neg);
  tcase_add_test(tc, test_ceil_inf_pos);
  tcase_add_test(tc, test_ceil_inf_neg);
  tcase_add_test(tc, test_ceil_nan_pos);
  tcase_add_test(tc, test_ceil_nan_neg);
  tcase_add_test(tc, test_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_loop_test(tc, test_tolerance_pos, 0, 100);
  tcase_add_loop_test(tc, test_tolerance_neg, 0, 100);
  tcase_add_test(tc, test_ceil_dbl_max);
  tcase_add_test(tc, test_ceil_dbl_min);
  suite_add_tcase(s, tc);
  return s;
}