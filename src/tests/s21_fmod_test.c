#include "s21_math_test.h"

#define TEST_EPS 1e-6l

START_TEST(fmod_test) {
  double x = 1.0;
  double y = -0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test1) {
  double x = 1.0;
  double y = 0.5;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 6);
}
END_TEST

START_TEST(fmod_test2) {
  double x = -1.0;
  double y = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 6);
}
END_TEST

START_TEST(fmod_test3) {
  double x = S21_INF;
  double y = 56;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(fmod_test4) {
  double x = -S21_INF;
  double y = -56;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  ck_assert_ldouble_nan(fmod(x, y));
}
END_TEST

START_TEST(fmod_test6) {
  double x = S21_NAN;
  double y = 7;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test7) {
  double x = (double)s21_fabs(S21_NAN);
  double y = 2;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test8) {
  double x = 4.7323234567890765;
  double y = (double)s21_fabs(S21_NAN);
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test9) {
  double x = 4732323456789076.5;
  double y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test10) {
  double x = -4.7323234567890765;
  double y = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 6);
}
END_TEST

START_TEST(test_x_inf_y_zero) {
  double x = 8743517471375471154.34143134134134;
  double y = 1747.13787435547115434144134313413;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 16);
}
END_TEST

START_TEST(test_x_inf_y_zero1) {
  double x = -8743517471375471154.34143134134134;
  double y = -8743547115417471375.13413434143134;
  ck_assert_ldouble_eq(s21_fmod(x, y), fmod(x, y));
}
END_TEST

START_TEST(test_neg) {
  ck_assert_ldouble_eq(fmod(-1234, 4), s21_fmod(-1234, 4));
}
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(fmod(1234, 4), s21_fmod(1234, 4)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(fmod(4, 2), s21_fmod(4, 2)); }
END_TEST

START_TEST(test_dbl_min) {
  double num = DBL_MIN * 2;
  double orig = fmod(num, DBL_MIN);
  double mmyy = (double)s21_fmod(num, DBL_MIN);
  ck_assert_ldouble_eq(orig, mmyy);
}
END_TEST

START_TEST(test_dbl_max) {
  double orig = fmod(DBL_MAX * 2, DBL_MAX);
  double mmyy = (double)s21_fmod(DBL_MAX * 2, DBL_MAX);
  ck_assert_ldouble_nan(orig);
  ck_assert_ldouble_nan(mmyy);
}
END_TEST

Suite *suite_fmod(void) {
  Suite *s = suite_create("suite_fmod");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, fmod_test);
  tcase_add_test(tc, fmod_test1);
  tcase_add_test(tc, fmod_test2);
  tcase_add_test(tc, fmod_test3);
  tcase_add_test(tc, fmod_test4);
  tcase_add_test(tc, fmod_test6);
  tcase_add_test(tc, fmod_test7);
  tcase_add_test(tc, fmod_test8);
  tcase_add_test(tc, fmod_test9);
  tcase_add_test(tc, fmod_test10);
  tcase_add_test(tc, test_x_inf_y_zero);
  tcase_add_test(tc, test_x_inf_y_zero1);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_dbl_min);
  tcase_add_test(tc, test_dbl_max);
  suite_add_tcase(s, tc);
  return s;
}