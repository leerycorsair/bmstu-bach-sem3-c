
#include <stdlib.h>
#include <check.h>
#include "arr_lib.h"
#include "err_codes.h"

////////////////////////////////
/////// Негативы test_key //////
////////////////////////////////

START_TEST(test_key_NULL_src)
{
    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int rc = key(NULL, NULL, &pb_dest, &pe_dest);

    ck_assert_int_eq(rc, FILTER_ERROR);
}
END_TEST

START_TEST(test_key_equal_src_pointers)
{
    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int *pb_src = malloc(10);
    int *pe_src = pb_dest;
    int rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    free(pb_src);
    ck_assert_int_eq(rc, FILTER_ERROR);
}
END_TEST

START_TEST(test_key_pb_src_more_pe_src)
{

    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int *pb_src = malloc(sizeof(int));
    int *pe_src = pb_src - sizeof(int);
    int rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    free(pb_src);
    ck_assert_int_eq(rc, FILTER_ERROR);
}
END_TEST

START_TEST(test_key_empty_dest_after_filtration)
{
    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int *pb_src = malloc(sizeof(int) * 5);
    int *pe_src = pb_dest + 5;
    for (int *i = pb_src; i < pe_src; i++)
        *i = 5;
    int rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    free(pb_src);
    ck_assert_int_eq(rc, FILTER_ERROR);
}
END_TEST

//////////////////////////////
///// Позитивы test_key //////
//////////////////////////////

START_TEST(test_key_inc_seq)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int *pe_src = pb_src + 5;
    int k = 0;
    for (int *i = pb_src; i < pe_src; i++)
    {
        *i = k;
        k += 1;
    }
    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    pb_dest = malloc(sizeof(int) * rc);
    pe_dest = pb_dest + rc;
    rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    free(pb_src);
    free(pb_dest);
    ck_assert_int_eq(rc, SUCCESS);
}

START_TEST(test_key_dec_seq)
{
    int *pb_dest = NULL;
    int *pe_dest = NULL;
    int *pb_src = malloc(sizeof(int) * 5);
    int *pe_src = pb_src + 5;
    int k = 5;
    for (int *i = pb_src; i < pe_src; i++)
    {
        *i = k;
        k -= 1;
    }
    int rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    pb_dest = malloc(sizeof(int) * rc);
    pe_dest = pb_dest + rc;
    rc = key(pb_src, pe_src, &pb_dest, &pe_dest);
    free(pb_src);
    free(pb_dest);
    ck_assert_int_eq(rc, SUCCESS);
}

///////////////////////////////////
////// Позитивы test_mysort ///////
///////////////////////////////////

START_TEST(test_mysort_inc_seq)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int *pe_src = pb_src + 5;
    int k = 1;
    for (int *i = pb_src; i < pe_src; i++)
    {
        *i = k;
        k += 1;
    }
    int *pb_src1 = malloc(sizeof(int) * 5);
    int *pe_src1 = pb_src1 + 5;
    k = 1;
    for (int *i = pb_src1; i < pe_src1; i++)
    {
        *i = k;
        k += 1;
    }
    mysort(pb_src, 5, sizeof(int), compare_int);
    ck_assert_mem_eq(pb_src, pb_src1, sizeof(int));
    free(pb_src);
    free(pb_src1);
}

START_TEST(test_mysort_dec_seq)
{
    int *pb_src = malloc(sizeof(int) * 5);
    int *pe_src = pb_src + 5;
    int k = 5;
    for (int *i = pb_src; i < pe_src; i++)
    {
        *i = k;
        k -= 1;
    }
    int *pb_src1 = malloc(sizeof(int) * 5);
    int *pe_src1 = pb_src1 + 5;
    k = 1;
    for (int *i = pb_src1; i < pe_src1; i++)
    {
        *i = k;
        k += 1;
    }
    mysort(pb_src, 5, sizeof(int), compare_int);
    ck_assert_mem_eq(pb_src, pb_src1, sizeof(int));
    free(pb_src);
    free(pb_src1);
}

Suite *arr_handling_suite(void)
{
    Suite *s;
    TCase *key_neg_case;
    TCase *key_pos_case;
    TCase *mysort_case;

    s = suite_create("arr_handling_suite");

    key_neg_case = tcase_create("key_neg_case");
    tcase_add_test(key_neg_case, test_key_NULL_src);
    tcase_add_test(key_neg_case, test_key_equal_src_pointers);
    tcase_add_test(key_neg_case, test_key_pb_src_more_pe_src);
    tcase_add_test(key_neg_case, test_key_empty_dest_after_filtration);

    key_pos_case = tcase_create("key_pos_case");
    tcase_add_test(key_pos_case, test_key_inc_seq);
    tcase_add_test(key_pos_case, test_key_dec_seq);

    mysort_case = tcase_create("mysort_case");
    tcase_add_test(mysort_case, test_mysort_inc_seq);
    tcase_add_test(mysort_case, test_mysort_dec_seq);

    suite_add_tcase(s, key_pos_case);
    suite_add_tcase(s, key_neg_case);
    suite_add_tcase(s, mysort_case);

    return s;
}

int main(void)
{
    setbuf(stdout, NULL);

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
