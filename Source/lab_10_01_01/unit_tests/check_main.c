#include "err_codes.h"
#include <check.h>

#include <stdlib.h>

Suite *find_suite(void);
Suite *pop_front_suite(void);
Suite *pop_back_suite(void);
Suite *insert_suite(void);
Suite *copy_suite(void);
Suite *append_suite(void);
Suite *remove_duplicates_suite(void);
Suite *sorted_insert_suite(void);
Suite *sort_suite(void);
// Suite *reverse_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;
    Suite *s_find_suite;

    s_find_suite = find_suite();
    runner = srunner_create(s_find_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_pop_front_suite;

    s_pop_front_suite = pop_front_suite();
    runner = srunner_create(s_pop_front_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_pop_back_suite;

    s_pop_back_suite = pop_back_suite();
    runner = srunner_create(s_pop_back_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_insert_suite;

    s_insert_suite = insert_suite();
    runner = srunner_create(s_insert_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_copy_suite;

    s_copy_suite = copy_suite();
    runner = srunner_create(s_copy_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_append_suite;

    s_append_suite = append_suite();
    runner = srunner_create(s_append_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_remove_duplicates_suite;

    s_remove_duplicates_suite = remove_duplicates_suite();
    runner = srunner_create(s_remove_duplicates_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_sorted_insert_suite;

    s_sorted_insert_suite = sorted_insert_suite();
    runner = srunner_create(s_sorted_insert_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_sort_suite;

    s_sort_suite = sort_suite();
    runner = srunner_create(s_sort_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    // Suite *s_reverse_suite;

    // s_reverse_suite = reverse_suite();
    // runner = srunner_create(s_reverse_suite);

    // srunner_run_all(runner, CK_VERBOSE);
    // no_failed += srunner_ntests_failed(runner);
    // srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
