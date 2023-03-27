#include <stdlib.h>
#include <check.h>
#include "err_codes.h"
#include "matrix_processing.h"

///////////////////////////////////////
///////// make_square_matrix //////////
///////////////////////////////////////

START_TEST(test_make_square_matrix_columns_more_rows)
{
    int *psrc = malloc(sizeof(int) * 6);
    *(psrc + 0) = 1;
    *(psrc + 1) = 2;
    *(psrc + 2) = 3;
    *(psrc + 3) = 4;
    *(psrc + 4) = 5;
    *(psrc + 5) = 6;
    int psrc_rows = 2, psrc_columns = 3;
    int *dst = malloc(sizeof(int)*4);
    *(dst + 0) = 2;
    *(dst + 1) = 3;
    *(dst + 2) = 5;
    *(dst + 3) = 6;
    make_square_matrix(&psrc, &psrc_rows, &psrc_columns);
    ck_assert_mem_eq(psrc, dst, 4 * sizeof(int));
    matrix_del(dst);
    matrix_del(psrc);
}

START_TEST(test_make_square_matrix_columns_less_rows)
{
    int *psrc = malloc(sizeof(int) * 6);
    *(psrc + 0) = 1;
    *(psrc + 1) = 2;
    *(psrc + 2) = 3;
    *(psrc + 3) = 4;
    *(psrc + 4) = 5;
    *(psrc + 5) = 6;
    int psrc_rows = 3, psrc_columns = 2;
    int *dst = malloc(sizeof(int)*4);
    *(dst + 0) = 3;
    *(dst + 1) = 4;
    *(dst + 2) = 5;
    *(dst + 3) = 6;
    make_square_matrix(&psrc, &psrc_rows, &psrc_columns);
    ck_assert_mem_eq(psrc, dst, 4 * sizeof(int));
    matrix_del(dst);
    matrix_del(psrc);
}

START_TEST(test_make_square_matrix_columns_eq_rows)
{
    int *psrc = malloc(sizeof(int) * 4);
    *(psrc + 0) = 1;
    *(psrc + 1) = 2;
    *(psrc + 2) = 3;
    *(psrc + 3) = 4;
    int psrc_rows = 2, psrc_columns = 2;
    int *dst = malloc(sizeof(int)*4);
    *(dst + 0) = 1;
    *(dst + 1) = 2;
    *(dst + 2) = 3;
    *(dst + 3) = 4;
    make_square_matrix(&psrc, &psrc_rows, &psrc_columns);
    ck_assert_mem_eq(psrc, dst, 4 * sizeof(int));
    matrix_del(dst);
    matrix_del(psrc);
}

///////////////////////////////////////
///////// make_eq_size_matrix /////////
///////////////////////////////////////

START_TEST(test_make_eq_size_matrix_matrix1_more_matrix2)
{
    int *matrix1 = malloc(sizeof(int) * 9);
    *(matrix1 + 0) = 1;
    *(matrix1 + 1) = 2;
    *(matrix1 + 2) = 3;
    *(matrix1 + 3) = 4;
    *(matrix1 + 4) = 5;
    *(matrix1 + 5) = 6;
    *(matrix1 + 6) = 7;
    *(matrix1 + 7) = 8;
    *(matrix1 + 8) = 9;
    int matrix1_rows = 3, matrix1_columns = 3;

    int *matrix2 = malloc(sizeof(int) * 1);
    *(matrix2 + 0) = 5;
    int matrix2_rows = 1, matrix2_columns = 1;

    int *dst = malloc(sizeof(int) * 9);
    *(dst + 0) = 5;
    *(dst + 1) = 5;
    *(dst + 2) = 5;
    *(dst + 3) = 5;
    *(dst + 4) = 5;
    *(dst + 5) = 5;
    *(dst + 6) = 5;
    *(dst + 7) = 5;
    *(dst + 8) = 5;

    ck_assert_int_eq(make_eq_size_matrix(&matrix1, &matrix1_rows, &matrix1_columns, &matrix2, &matrix2_rows, &matrix2_columns), SUCCESS);
    ck_assert_mem_eq(dst, matrix2, 9 * sizeof(int));
    matrix_del(matrix1);
    matrix_del(matrix2);
    matrix_del(dst);
}

START_TEST(test_make_eq_size_matrix_matrix1_less_matrix2)
{
    
    int *matrix1 = malloc(sizeof(int) * 9);
    *(matrix1 + 0) = 1;
    *(matrix1 + 1) = 2;
    *(matrix1 + 2) = 3;
    *(matrix1 + 3) = 4;
    *(matrix1 + 4) = 5;
    *(matrix1 + 5) = 6;
    *(matrix1 + 6) = 7;
    *(matrix1 + 7) = 8;
    *(matrix1 + 8) = 9;
    int matrix1_rows = 3, matrix1_columns = 3;

    int *matrix2 = malloc(sizeof(int) * 1);
    *(matrix2 + 0) = 5;
    int matrix2_rows = 1, matrix2_columns = 1;

    int *dst = malloc(sizeof(int) * 9);
    *(dst + 0) = 5;
    *(dst + 1) = 5;
    *(dst + 2) = 5;
    *(dst + 3) = 5;
    *(dst + 4) = 5;
    *(dst + 5) = 5;
    *(dst + 6) = 5;
    *(dst + 7) = 5;
    *(dst + 8) = 5;

    ck_assert_int_eq(make_eq_size_matrix(&matrix2, &matrix2_rows, &matrix2_columns, &matrix1, &matrix1_rows, &matrix1_columns), SUCCESS);
    ck_assert_mem_eq(dst, matrix2, 9 * sizeof(int));
    matrix_del(matrix1);
    matrix_del(matrix2);
    matrix_del(dst);
}

///////////////////////////////////////
//////////// multi_matrix /////////////
///////////////////////////////////////

START_TEST(test_multi_matrix)
{

    int *matrix1 = malloc(sizeof(int) * 1);
    *(matrix1 + 0) = 1;
    int matrix1_rows = 1;

    int *matrix2 = malloc(sizeof(int) * 1);
    *(matrix2 + 0) = 5;
    int matrix2_rows = 1;

    int *dst = malloc(sizeof(int) * 1);
    *(dst + 0) = 5;

    ck_assert_int_eq(multi_matrix(&matrix1, &matrix1_rows, matrix2, &matrix2_rows), SUCCESS);
    ck_assert_mem_eq(dst, matrix2, 1 * sizeof(int));
    matrix_del(matrix1);
    matrix_del(matrix2);
    matrix_del(dst);
}

Suite *matrix_processing_suite(void)
{
    Suite *s;
    TCase *make_square_matrix_case;
    TCase *make_eq_size_matrix_case;
    TCase *multi_matrix_suite;

    s = suite_create("matrix_processing_suite");

    make_square_matrix_case = tcase_create("make_square_matrix_case");
    tcase_add_test(make_square_matrix_case, test_make_square_matrix_columns_more_rows);
    tcase_add_test(make_square_matrix_case, test_make_square_matrix_columns_less_rows);
    tcase_add_test(make_square_matrix_case, test_make_square_matrix_columns_eq_rows);


    make_eq_size_matrix_case = tcase_create("make_eq_size_matrix_case");
    tcase_add_test(make_eq_size_matrix_case, test_make_eq_size_matrix_matrix1_more_matrix2);
    tcase_add_test(make_eq_size_matrix_case, test_make_eq_size_matrix_matrix1_less_matrix2);

    multi_matrix_suite = tcase_create("multi_matrix_suite");
    tcase_add_test(multi_matrix_suite, test_multi_matrix);

    suite_add_tcase(s, make_square_matrix_case);
    suite_add_tcase(s, make_eq_size_matrix_case);
    suite_add_tcase(s, multi_matrix_suite);

    return s;
}

int main(void)
{
    setbuf(stdout, NULL);

    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = matrix_processing_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

