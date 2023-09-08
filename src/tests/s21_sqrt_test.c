#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(sqrt_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test4) {
  double x = S21_INF;
  ck_assert_ldouble_infinite(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt_test5) {
  double x = -S21_INF;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt_test6) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt_test7) {
  double x = 4.7;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test9) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test10) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(sqrt_test11) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 6);
}
END_TEST

START_TEST(test_inf) { ck_assert_ldouble_infinite(s21_sqrt(S21_INF)); }
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(sqrt(S21_NAN));
}
END_TEST

START_TEST(test_y_zero) { ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0)); }
END_TEST

START_TEST(test_zero) { ck_assert_ldouble_eq(sqrt(0), s21_sqrt(0)); }
END_TEST

START_TEST(test_neg) {
  double x = -1234;
  long double orig = sqrt(x);
  long double mmyy = s21_sqrt(x);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

START_TEST(test_pos) {
  ck_assert_ldouble_eq_tol(sqrt(1234), s21_sqrt(1234), 1e-6);
}
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq_tol(sqrt(1), s21_sqrt(1), 1e-6); }
END_TEST

START_TEST(test_normal) {
  ck_assert_ldouble_eq_tol(sqrt(1.7), s21_sqrt(1.7), 1e-6);
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq_tol(sqrt(14.7), s21_sqrt(14.7), 1e-6);
}
END_TEST
START_TEST(test_lesser_than_1) {
  ck_assert_ldouble_eq_tol(sqrt(0.7), s21_sqrt(0.7), 1e-6);
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(sqrt(a * i), s21_sqrt(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_dbl_min) {
  double num = DBL_MIN;
  double orig = sqrt(num);
  double mmyy = (double)s21_sqrt(num);
  ck_assert_ldouble_eq_tol(orig, mmyy, 1e-6);
}
END_TEST

Suite *suite_sqrt(void) {
  Suite *s = suite_create("suite_sqrt");
  TCase *tc = tcase_create("sqrt_tc");

  tcase_add_test(tc, sqrt_test1);
  tcase_add_test(tc, sqrt_test2);
  tcase_add_test(tc, sqrt_test3);
  tcase_add_test(tc, sqrt_test4);
  tcase_add_test(tc, sqrt_test5);
  tcase_add_test(tc, sqrt_test6);
  tcase_add_test(tc, sqrt_test7);
  tcase_add_test(tc, sqrt_test8);
  tcase_add_test(tc, sqrt_test9);
  tcase_add_test(tc, sqrt_test10);
  tcase_add_test(tc, sqrt_test11);
  tcase_add_test(tc, test_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_y_zero);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_above_1);
  tcase_add_test(tc, test_lesser_than_1);
  tcase_add_loop_test(tc, test_tolerance_pos, 21, 120);
  tcase_add_test(tc, test_dbl_min);
  suite_add_tcase(s, tc);
  return s;
}