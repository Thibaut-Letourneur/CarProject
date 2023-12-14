/**
 * @file test_track.c
 * @brief Testing the functions of track.c
 * @author Thibaut LETOURNEUR
 * @version 1.0.0
 * @date 2023
 */
#include "minunit.h"
#include "track.h"
#include "utils.h"

MU_TEST(test){
}

MU_TEST(test_setup) {
}

MU_TEST(test_teardown){
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}