#include "s21_math_test.h"

START_TEST(test_atan_pos_nan) {
  double x = (double)s21_fabs(S21_NAN);
  ck_assert_ldouble_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_neg_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_pos_inf) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(test_atan_neg_inf) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(test_atan_pos_one) {
  double x = 1.0;
  ck_assert_ldouble_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(test_atan_neg_one) {
  double x = -1.0;
  ck_assert_ldouble_eq(s21_atan(x), atan(x));
}
END_TEST

START_TEST(test_atan_valid_arg) {
  for (double i = -0.9; i < 1; i += 0.2)
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
}
END_TEST

START_TEST(test_atan_no_valid_arg) {
  double i = _i;
  ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), 1e-6);
}
END_TEST

START_TEST(test_atan_dbl_max) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(atan(x), s21_atan(x));
}
END_TEST

START_TEST(test_atan_dbl_min) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

Suite *suite_atan(void) {
  Suite *s = suite_create("suite_atan");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, test_atan_pos_nan);
  tcase_add_test(tc, test_atan_neg_nan);
  tcase_add_test(tc, test_atan_pos_inf);
  tcase_add_test(tc, test_atan_neg_inf);
  tcase_add_test(tc, test_atan_pos_one);
  tcase_add_test(tc, test_atan_neg_one);
  tcase_add_test(tc, test_atan_valid_arg);
  tcase_add_loop_test(tc, test_atan_no_valid_arg, -10, 10);
  tcase_add_test(tc, test_atan_dbl_max);
  tcase_add_test(tc, test_atan_dbl_min);
  suite_add_tcase(s, tc);
  return s;
}