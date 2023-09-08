#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(cos_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test4) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(cos_test5) {
  double x = -S21_INF;
  ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(cos_test6) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(cos_test7) {
  double x = 4.7;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test9) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test10) {
  double x = -4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(cos_test11) {
  double x = -4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), 6);
}
END_TEST

START_TEST(test_inf) { ck_assert_ldouble_nan(s21_cos(S21_INF)); }
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(cos(S21_NAN));
}
END_TEST

START_TEST(test_y_zero) { ck_assert_ldouble_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(test_zero) { ck_assert_ldouble_eq(cos(0), s21_cos(0)); }
END_TEST

START_TEST(test_neg) {
  ck_assert_ldouble_eq_tol(cos(-1234), s21_cos(-1234), 1e-6);
}
END_TEST

START_TEST(test_pos) {
  ck_assert_ldouble_eq_tol(cos(1234), s21_cos(1234), 1e-6);
}
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), 1e-6); }
END_TEST

START_TEST(test_normal) {
  ck_assert_ldouble_eq_tol(cos(1.7), s21_cos(1.7), 1e-6);
}
END_TEST

START_TEST(test_normal_negative) {
  ck_assert_ldouble_eq_tol(cos(-1.7), s21_cos(-1.7), 1e-6);
}
END_TEST

START_TEST(test_normal_negative_1) {
  ck_assert_ldouble_eq_tol(cos(-0.7), s21_cos(-0.7), 1e-6);
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq_tol(cos(14.7), s21_cos(14.7), 1e-6);
}
END_TEST
START_TEST(test_lesser_than_1) {
  ck_assert_ldouble_eq_tol(cos(0.7), s21_cos(0.7), 1e-6);
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(cos(a * i), s21_cos(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(cos(-a * i), s21_cos(-a * i), TEST_EPS);
}
END_TEST

START_TEST(test_dbl_min) {
  double num = DBL_MIN;
  double orig = cos(num);
  double mmyy = (double)s21_cos(num);
  ck_assert_ldouble_eq(orig, mmyy);
}
END_TEST

Suite *suite_cos(void) {
  Suite *s = suite_create("suite_cos");
  TCase *tc = tcase_create("cos_tc");

  tcase_add_test(tc, cos_test1);
  tcase_add_test(tc, cos_test2);
  tcase_add_test(tc, cos_test3);
  tcase_add_test(tc, cos_test4);
  tcase_add_test(tc, cos_test5);
  tcase_add_test(tc, cos_test6);
  tcase_add_test(tc, cos_test7);
  tcase_add_test(tc, cos_test8);
  tcase_add_test(tc, cos_test9);
  tcase_add_test(tc, cos_test10);
  tcase_add_test(tc, cos_test11);
  tcase_add_test(tc, test_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_y_zero);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_negative);
  tcase_add_test(tc, test_normal_negative_1);
  tcase_add_test(tc, test_normal_above_1);
  tcase_add_test(tc, test_lesser_than_1);
  tcase_add_loop_test(tc, test_tolerance_pos, 0, 100);
  tcase_add_loop_test(tc, test_tolerance_neg, 0, 100);
  tcase_add_test(tc, test_dbl_min);
  suite_add_tcase(s, tc);
  return s;
}