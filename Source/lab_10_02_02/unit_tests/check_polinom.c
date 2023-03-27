#include "err_codes.h"
#include <check.h>

START_TEST(test_eq)
{
    ck_assert_int_eq(1, 1);
}
END_TEST


Suite *polinom_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("polinom_suite");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_eq);   
    suite_add_tcase(s, tc_pos);

    return s;
}