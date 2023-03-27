
#include <check.h>
#include <stdio.h>
#include <limits.h>

#include "my_snprintf.h"

// ###############################################
//         start i-spec
// ###############################################

START_TEST(test_i_pos)
{
    int num = 1234567;
    int size = 10;
    char format[30] = "one two %i three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_i_neg)
{
    int num = -324;
    int size = 20;
    char format[30] = "one two %i three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_i_many_args)
{
    int num1 = 2, num2 = 324, num3 = -21;
    int size = 50;
    char format[100] = "one %i two %i three %i";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *i_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("i suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_i_pos);
    tcase_add_test(tests, test_i_neg);
    tcase_add_test(tests, test_i_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end i-spec
// ###############################################

// ###############################################
//         start d-spec
// ###############################################

START_TEST(test_d_pos)
{
    int num = 4120;
    size_t size = 30;
    char format[20] = "one two %d three";

    char str1[50] = "str";
    char str2[50] = "str";
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_int_eq(err_code1, err_code2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_d_neg)
{
    int num = -214;
    int size = 30;
    char format[100] = "one %d three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_d_many_args)
{
    int num1 = 2, num2 = 324, num3 = -21;
    int size = 30;
    char format[100] = "one %d two %d three %d";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *d_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("d suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_d_pos);
    tcase_add_test(tests, test_d_neg);
    tcase_add_test(tests, test_d_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end d-spec
// ###############################################

// ###############################################
//         start o-spec
// ###############################################

START_TEST(test_o_one_elem)
{
    unsigned num = 0;
    int size = 27;
    char format[100] = "one two %o three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_int_eq(err_code1, err_code2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_o_many_args)
{
    unsigned num1 = 10, num2 = 43942, num3 = 111;
    int size = 50;
    char format[100] = "one %o two %o three %o";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_int_eq(err_code1, err_code2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *o_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("o suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_o_one_elem);
    tcase_add_test(tests, test_o_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end o-spec
// ###############################################

// ###############################################
//         start li-spec
// ###############################################

START_TEST(test_li_pos)
{
    long int num = 3242121;
    int size = 50;
    char format[100] = "one two %li three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_li_neg)
{
    long int num = -324;
    int size = 50;
    char format[100] = "one two %li three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_li_many_args)
{
    long int num1 = 2, num2 = 324, num3 = -21;
    int size = 50;
    char format[100] = "one %li two %li three %li";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *li_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("li suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_li_pos);
    tcase_add_test(tests, test_li_neg);
    tcase_add_test(tests, test_li_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end li-spec
// ###############################################

// ###############################################
//         start ld-spec
// ###############################################

START_TEST(test_ld_pos)
{
    long int num = LONG_MAX;
    int size = 50;
    char format[100] = "one two %ld three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_ld_neg)
{
    long int num = LONG_MIN;
    int size = 50;
    char format[100] = "one two %ld three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_ld_many_args)
{
    long int num1 = 2, num2 = 324, num3 = -21;
    int size = 50;
    char format[100] = "one %ld two %ld three %ld";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *ld_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("ld suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_ld_pos);
    tcase_add_test(tests, test_ld_neg);
    tcase_add_test(tests, test_ld_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end ld-spec
// ###############################################

// ###############################################
//         start lo-spec
// ###############################################

START_TEST(test_lo_one_elem)
{
    unsigned long num = ULONG_MAX;
    int size = 50;
    char format[100] = "one two %lo three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num);
    int err_code2 = snprintf(str2, size, format, num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_lo_many_args)
{
    unsigned long num1 = 2, num2 = 324, num3 = 21;
    int size = 50;
    char format[100] = "one %lo two %lo three %lo";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, format, num1, num2, num3);
    int err_code2 = snprintf(str2, size, format, num1, num2, num3);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *lo_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("lo suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_lo_one_elem);
    tcase_add_test(tests, test_lo_many_args);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end lo-spec
// ###############################################

// ###############################################
//         start non-spec
// ###############################################

START_TEST(test_non_spec_str_overflow)
{
    int size = 27;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two three");
    int err_code2 = snprintf(str2, size, "one two three");

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_non_spec_null_size)
{
    int size = 0;

    char str1[100] = "keklul";
    char str2[100] = "keklul";
    int err_code1 = my_snprintf(str1, size, "one two three");
    int err_code2 = snprintf(str2, size, "one two three");

    ck_assert_int_eq(err_code1, err_code2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_non_spec)
{
    int size = 20;

    char str1[100] = "keklul", str2[100] = "keklul";
    int err_code1 = my_snprintf(str1, size, "one two three");
    int err_code2 = snprintf(str2, size, "one two three");

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *non_spec_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("non_spec suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_non_spec_str_overflow);
    tcase_add_test(tests, test_non_spec_null_size);
    tcase_add_test(tests, test_non_spec);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end non-spec
// ###############################################

// ###############################################
//         start non-num
// ###############################################

START_TEST(test_non_num_str)
{
    int size = 27;
    char str[100] = "one two three";

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %s three", str);
    int err_code2 = snprintf(str2, size, "one two %s three", str);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_non_num_char)
{
    int size = 27;
    char ch = 'E';

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %c three", ch);
    int err_code2 = snprintf(str2, size, "one two %c three", ch);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *non_num_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("non_num suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_non_num_str);
    tcase_add_test(tests, test_non_num_char);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end non-num
// ###############################################

// ###############################################
//         start hd
// ###############################################

START_TEST(test_hd_pos)
{
    int size = 27;
    short num = SHRT_MAX;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hd three", num);
    int err_code2 = snprintf(str2, size, "one two %hd three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_hd_neg)
{
    int size = 27;
    short num = SHRT_MIN;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hd three", num);
    int err_code2 = snprintf(str2, size, "one two %hd three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *hd_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("hd suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_hd_pos);
    tcase_add_test(tests, test_hd_neg);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end hd
// ###############################################


// ###############################################
//         start hi
// ###############################################

START_TEST(test_hi_pos)
{
    int size = 27;
    short num = SHRT_MAX;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hi three", num);
    int err_code2 = snprintf(str2, size, "one two %hi three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_hi_neg)
{
    int size = 27;
    short num = SHRT_MIN;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hi three", num);
    int err_code2 = snprintf(str2, size, "one two %hi three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *hi_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("hi suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_hi_pos);
    tcase_add_test(tests, test_hi_neg);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end hi
// ###############################################

// ###############################################
//         start hx
// ###############################################

START_TEST(test_hx_pos)
{
    int size = 27;
    unsigned short num = USHRT_MAX;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hx three", num);
    int err_code2 = snprintf(str2, size, "one two %hx three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_hx_null)
{
    int size = 27;
    unsigned short num = 0;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %hx three", num);
    int err_code2 = snprintf(str2, size, "one two %hx three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *hx_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("hx suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_hx_pos);
    tcase_add_test(tests, test_hx_null);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end hx
// ###############################################


// ###############################################
//         start x
// ###############################################

START_TEST(test_x_pos)
{
    int size = 27;
    unsigned int num = UINT_MAX;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %x three", num);
    int err_code2 = snprintf(str2, size, "one two %x three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_x_null)
{
    int size = 27;
    unsigned int num = 0;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %x three", num);
    int err_code2 = snprintf(str2, size, "one two %x three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *x_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("x suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_x_pos);
    tcase_add_test(tests, test_x_null);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end x
// ###############################################


// ###############################################
//         start lx
// ###############################################

START_TEST(test_lx_pos)
{
    int size = 27;
    unsigned long num = ULONG_MAX;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %lx three", num);
    int err_code2 = snprintf(str2, size, "one two %lx three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

START_TEST(test_lx_null)
{
    int size = 27;
    unsigned long num = 0;

    char str1[100], str2[100];
    int err_code1 = my_snprintf(str1, size, "one two %lx three", num);
    int err_code2 = snprintf(str2, size, "one two %lx three", num);

    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(err_code1, err_code2);
}
END_TEST

Suite *lx_suite(void)
{
    Suite *s;
    TCase *tests;

    s = suite_create("lx suite");

    tests = tcase_create("tests");
    tcase_add_test(tests, test_lx_pos);
    tcase_add_test(tests, test_lx_null);

    suite_add_tcase(s, tests);

    return s;
}
// ###############################################
//         end lx
// ###############################################

