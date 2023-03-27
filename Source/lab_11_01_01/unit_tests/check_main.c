
#include <check.h>
#include <stdlib.h>

Suite *i_suite(void);
Suite *d_suite(void);
Suite *o_suite(void);
Suite *li_suite(void);
Suite *ld_suite(void);
Suite *lo_suite(void);
Suite *non_spec_suite(void);
Suite *non_num_suite(void);
Suite *hd_suite(void);
Suite *hi_suite(void);
Suite *hx_suite(void);
Suite *x_suite(void);
Suite *lx_suite(void);

int main(void)
{
    int no_failed = 0;
    SRunner *runner;
    Suite *s_i_suite;

    s_i_suite = i_suite();
    runner = srunner_create(s_i_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_d_suite;

    s_d_suite = d_suite();
    runner = srunner_create(s_d_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_o_suite;

    s_o_suite = o_suite();
    runner = srunner_create(s_o_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_li_suite;

    s_li_suite = li_suite();
    runner = srunner_create(s_li_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_ld_suite;

    s_ld_suite = ld_suite();
    runner = srunner_create(s_ld_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_lo_suite;

    s_lo_suite = lo_suite();
    runner = srunner_create(s_lo_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_non_spec_suite;

    s_non_spec_suite = non_spec_suite();
    runner = srunner_create(s_non_spec_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_non_num_suite;

    s_non_num_suite = non_num_suite();
    runner = srunner_create(s_non_num_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_hd_suite;

    s_hd_suite = hd_suite();
    runner = srunner_create(s_hd_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_hi_suite;

    s_hi_suite = hi_suite();
    runner = srunner_create(s_hi_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_hx_suite;

    s_hx_suite = hx_suite();
    runner = srunner_create(s_hx_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_x_suite;

    s_x_suite = x_suite();
    runner = srunner_create(s_x_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    Suite *s_lx_suite;

    s_lx_suite = lx_suite();
    runner = srunner_create(s_lx_suite);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
