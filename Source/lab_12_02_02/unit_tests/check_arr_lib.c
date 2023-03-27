#include <stdlib.h>
#include <check.h>
#include "arr_lib.h"

////////////////////////////////
/////// Тесты del_duples  //////
////////////////////////////////

START_TEST(test_del_duples_no)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int *pb_dst = malloc(sizeof(int) * 5);
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        pb_src[i] = k;
        k += 1;
    }
    int rc = del_duples(pb_src, 5, pb_dst, 5);
    free(pb_dst);
    free(pb_src);
    ck_assert_int_eq(rc, SUCCESS);
}

START_TEST(test_del_duples_many)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int *pb_dst = malloc(sizeof(int) * 5);
    int k = 1;
    for (int i = 0; i < 5; i++)
    {
        pb_src[i] = k;
    }
    int rc = del_duples(pb_src, 5, pb_dst, 5);
    free(pb_src);
    free(pb_dst);
    ck_assert_int_eq(rc, SUCCESS);
}

//////////////////////////////
///// Тесты arr_fill_fib /////
//////////////////////////////

START_TEST(test_arr_fill_fib_one)
{
    int *pb_src = malloc(sizeof(int) * 1);
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        pb_src[i] = k;
        k += 1;
    }
    int rc = arr_fill_fib(pb_src, 1);
    free(pb_src);
    ck_assert_int_eq(rc, SUCCESS);
}

START_TEST(test_arr_fill_fib_many)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        pb_src[i] = k;
        k += 1;
    }
    int rc = arr_fill_fib(pb_src, 5);
    free(pb_src);
    ck_assert_int_eq(rc, SUCCESS);
}

Suite *arr_handling_suite(void)
{
    Suite *s;
    TCase *test_arr_fill;
    TCase *test_del_duples;

    s = suite_create("arr_handling_suite");

    test_arr_fill = tcase_create("test_arr_fill");
    tcase_add_test(test_arr_fill, test_arr_fill_fib_one);
    tcase_add_test(test_arr_fill, test_arr_fill_fib_many);

    test_del_duples = tcase_create("test_del_duples");
    tcase_add_test(test_del_duples, test_del_duples_no);
    tcase_add_test(test_del_duples, test_del_duples_many);

    suite_add_tcase(s, test_arr_fill);
    suite_add_tcase(s, test_del_duples);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = arr_handling_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
