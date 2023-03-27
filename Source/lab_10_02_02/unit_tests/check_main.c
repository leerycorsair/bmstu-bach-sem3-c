#include "err_codes.h"
#include <check.h>
#include <stdlib.h>

// Для данной конкретной задачи необходимость в Unit Test'aх отсутствует,
// так как функциональные тесты в полной мере выполняют тестирование
// аспектов, которые можно было бы протестировать в Unit Test'aх.

Suite *polinom_suite(void);




int main(void)
{
    int no_failed = 0;
    Suite *s_polinom_handling;
    SRunner *runner;

    s_polinom_handling = polinom_suite();
    runner = srunner_create(s_polinom_handling);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}