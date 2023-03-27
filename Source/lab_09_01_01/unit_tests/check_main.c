#include "fb_handling.h"
#include "err_codes.h"
#include <check.h>

// Для данной конкретной задачи необходимость в Unit Test'aх отсутствует,
// так как функциональные тесты в полной мере выполняют тестирование
// аспектов, которые можно было бы протестировать в Unit Test'aх.

Suite *fb_suite(void);



int main(void)
{
    int no_failed = 0;
    Suite *s_fb_handling;
    SRunner *runner;

    s_fb_handling = fb_suite();
    runner = srunner_create(s_fb_handling);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}