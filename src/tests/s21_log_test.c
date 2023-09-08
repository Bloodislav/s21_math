#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(log_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq(s21_log(x), log(x));
}
END_TEST

START_TEST(log_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq(s21_log(x), log(x));
}
END_TEST

START_TEST(log_test3) {
  double x = -0.0;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(mmyy);
}
END_TEST

START_TEST(log_test4) {
  double x = S21_INF;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_infinite(orig);
  ck_assert_ldouble_infinite(mmyy);
}
END_TEST

START_TEST(log_test5) {
  double x = -S21_INF;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(log_test6) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(log_test7) {
  double x = 4.7;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 6);
}
END_TEST

START_TEST(log_test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 6);
}
END_TEST

START_TEST(log_test9) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq(s21_log(x), log(x));
}
END_TEST

START_TEST(log_test10) {
  double x = -4.7323234567890765;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(log_test11) {
  double x = -4732323456789076.5;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_inf) { ck_assert_ldouble_eq(s21_log(S21_INF), log(S21_INF)); }
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_nan(log(S21_NAN));
}
END_TEST

START_TEST(test_y_zero) { ck_assert_ldouble_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(test_x_inf_y_zero) {
  double x = 8743517471375471154.34143134134134;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 6);
}
END_TEST

START_TEST(test_x_inf_y_zero1) {
  double x = -8743517471375471154.34143134134134;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_zero) { ck_assert_ldouble_eq(log(0), s21_log(0)); }
END_TEST

START_TEST(test_neg) {
  double x = -874351;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(log(1234), s21_log(1234)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(log(1), s21_log(1)); }
END_TEST

START_TEST(test_normal) {
  ck_assert_ldouble_eq_tol(log(1.7), s21_log(1.7), 1e-6);
}
END_TEST

START_TEST(test_normal_negative) {
  double x = -1.7;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_normal_negative_1) {
  double x = -0.7;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq(log(14.7), s21_log(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) { ck_assert_ldouble_eq(log(0.7), s21_log(0.7)); }
END_TEST
START_TEST(test_positive_inf) {
  ck_assert_ldouble_eq(log(S21_INF), s21_log(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
  double x = -S21_INF;
  long double orig = log(x);
  long double mmyy = s21_log(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 3;
  int i = _i;
  ck_assert_ldouble_eq_tol(log(a * i), s21_log(a * i), 1e-06);
}
END_TEST

START_TEST(test_tolerance_neg) {
  double a = -3;
  int i = _i;
  ck_assert_ldouble_eq_tol(log(-a * i), s21_log(-a * i), 1e-06);
}
END_TEST

START_TEST(test_dbl_min) {
  double num = DBL_MIN;
  double orig = log(num);
  double mmyy = (double)s21_log(num);
  ck_assert_ldouble_eq(orig, mmyy);
}
END_TEST

START_TEST(test_dbl_max) {
  double orig = log(DBL_MAX);
  double mmyy = (double)s21_log(DBL_MAX);
  ck_assert_ldouble_eq_tol(orig, mmyy, 1e-6);
}
END_TEST

Suite *suite_log(void) {
  Suite *s = suite_create("suite_log");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, log_test1);
  tcase_add_test(tc, log_test2);
  tcase_add_test(tc, log_test3);
  tcase_add_test(tc, log_test4);
  tcase_add_test(tc, log_test5);
  tcase_add_test(tc, log_test6);
  tcase_add_test(tc, log_test7);
  tcase_add_test(tc, log_test8);
  tcase_add_test(tc, log_test9);
  tcase_add_test(tc, log_test10);
  tcase_add_test(tc, log_test11);
  tcase_add_test(tc, test_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_y_zero);
  tcase_add_test(tc, test_x_inf_y_zero);
  tcase_add_test(tc, test_x_inf_y_zero1);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_negative);
  tcase_add_test(tc, test_normal_negative_1);
  tcase_add_test(tc, test_normal_above_1);
  tcase_add_test(tc, test_negative_inf);
  tcase_add_test(tc, test_lesser_than_1);
  tcase_add_test(tc, test_positive_inf);
  tcase_add_loop_test(tc, test_tolerance_pos, 1, 100);
  tcase_add_loop_test(tc, test_tolerance_neg, 1, 100);
  tcase_add_test(tc, test_dbl_min);
  tcase_add_test(tc, test_dbl_max);
  suite_add_tcase(s, tc);
  return s;
}