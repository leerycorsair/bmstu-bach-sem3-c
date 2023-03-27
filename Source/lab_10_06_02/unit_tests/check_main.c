#include "err_codes.h"
#include <check.h>
#include <stdlib.h>

// Для данной конкретной задачи необходимость в Unit Test'aх отсутствует,
// так как функциональные тесты в полной мере выполняют тестирование
// аспектов, которые можно было бы протестировать в Unit Test'aх.

Suite *matrix_suite(void);


int main(void)
{
    int no_failed = 0;
    Suite *matrix_suite_1;
    SRunner *runner;

    matrix_suite_1 = matrix_suite();
    runner = srunner_create(matrix_suite_1);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}