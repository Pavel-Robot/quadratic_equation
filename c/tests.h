/*
 * c/ (DIRECTORY)
 *
 * tests.h (FILE NAME)
 * 
*/ 

#ifndef QUADRATIC_EQ_TEST
#define QUADRATIC_EQ_TEST
#include "CuTest/lib/CuTest.h"
#include "quadratic_equation.h"

CuSuite* Test1();

// Тестируемая функция
char* func(char* str) {
	return str;
}

// некоторый тест _1 из набора тестов 1_
void Test1_1(CuTest *tc) {
	char* input = strdup("hello world");
	char* actual = func(input);
	char* expected = "HELLO WORLD";
	CuAssertStrEquals(tc, expected, actual);
}

// Набор тестов Test1
CuSuite* Test1() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Test1);
	return suite;
}

#endif // QUADRATIC_EQ_TEST

/*
void ts(double a, double b, double c, char* correct, char* ans){
    int argc = 2;
    char *argv[] = {"program_name", "-t"};

    struct sys_parametrs sys = input_args(argc, argv);  
    sys.command_line_use == FALSEMY;

    solve_equation_main(argc, argv, a, b, c, sys, ans);

    printf("%s\n%s\n", ans, correct);

    //assert(1>2);
}


void tests()
{
    printf("Start testing!\n");
    
    test1();

}

# Testing when all the input units, the options are different in sign
1 1 1 -0.500000 0.866025 -0.500000 -0.866025
1 1 -1 0.618034 -1.618034
1 -1 1 0.500000 0.866025 0.500000 -0.866025
1 -1 -1 1.618034 -0.618034
-1 1 1 -0.618034 1.618034
-1 1 -1 0.500000 -0.866025 0.500000 0.866025
-1 -1 1 -1.618034 0.618034
-1 -1 -1 -0.500000 -0.866025 -0.500000 0.866025
*/