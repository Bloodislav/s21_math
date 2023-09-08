#include "s21_math_test.h"

START_TEST(pow_test1) {
  double base = 1.01;
  double exp = 0.0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 6);
}
END_TEST

START_TEST(pow_test2) {
  double base = 1.01;
  double exp = -0.0;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test3) {
  double base = 1;
  double exp = 2;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test4) {
  double base = 2;
  double exp = 1;
  ck_assert_ldouble_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(pow_test5) {
  double base = 5;
  double exp = -1;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test6) {
  double base = -1;
  double exp = 2;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test7) {
  double base = 2;
  double exp = 1023;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test8) {
  double base = -3;
  double exp = 0.95;
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test9) {
  double base = 3;
  double exp = 1e200;
  ck_assert_ldouble_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(pow_test_10) {
  double base = S21_NAN;
  double exp = 4;
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_11) {
  double base = 2;
  double exp = S21_NAN;
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_12) {
  double base = -S21_INF;
  double exp = 0.7;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_13) {
  double base = S21_INF;
  double exp = -0.7;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_14) {
  double base = -S21_INF;
  double exp = 3;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(test_exp_inf_pos) {
  double base[] = {-1, 0.23, 5};
  double exp = S21_INF;
  for (int i = 0; i < 3; i++)
    ck_assert_ldouble_eq(s21_pow(base[i], exp), pow(base[i], exp));
}
END_TEST

START_TEST(test_exp_inf_neg) {
  double base[] = {-3, 0.23, 5};
  double exp = -S21_INF;
  for (int i = 0; i < 3; i++)
    ck_assert_ldouble_eq(s21_pow(base[i], exp), pow(base[i], exp));
}
END_TEST

START_TEST(test_dbl_min) {
  double num = DBL_MIN * 2;
  double orig = pow(num, DBL_MIN);
  double mmyy = (double)s21_pow(num, DBL_MIN);
  ck_assert_ldouble_eq(orig, mmyy);
}
END_TEST

START_TEST(test_dbl_max) {
  double orig = pow(DBL_MAX * 2, DBL_MAX);
  double mmyy = (double)s21_pow(DBL_MAX * 2, DBL_MAX);
  ck_assert_ldouble_eq(orig, mmyy);
}
END_TEST

Suite *suite_pow(void) {
  Suite *s = suite_create("suite_pow");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, pow_test1);
  tcase_add_test(tc, pow_test2);
  tcase_add_test(tc, pow_test3);
  tcase_add_test(tc, pow_test4);
  tcase_add_test(tc, pow_test5);
  tcase_add_test(tc, pow_test6);
  tcase_add_test(tc, pow_test7);
  tcase_add_test(tc, pow_test8);
  tcase_add_test(tc, pow_test9);
  tcase_add_test(tc, pow_test_10);
  tcase_add_test(tc, pow_test_11);
  tcase_add_test(tc, pow_test_12);
  tcase_add_test(tc, pow_test_13);
  tcase_add_test(tc, pow_test_14);
  tcase_add_test(tc, test_exp_inf_pos);
  tcase_add_test(tc, test_exp_inf_neg);
  tcase_add_test(tc, test_dbl_min);
  tcase_add_test(tc, test_dbl_max);
  suite_add_tcase(s, tc);
  return s;
}