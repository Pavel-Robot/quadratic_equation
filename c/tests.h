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
#include <string.h>
#include <stdlib.h>

void RunAllTests(void);

CuSuite* Test1();

char* ch2ch(char *s)
{
    int len = 0;
    while(s[len] != '\0') len++; 

    char *resize = (char *)malloc(len * sizeof(char));
    for(int i = 0; i < len; i++)
        *(resize + i) =  *(s + i);

    return resize;
}


void split(char* str, double *a, double *b, double *c)
{
    char *token = strtok(str, " ");
    *a = atof(token);
    token = strtok(NULL, " ");
    *b = atof(token);
    token = strtok(NULL, " ");
    *c = atof(token);
}
 
// Тестируемая функция
char* func(char* str) {

    int argc = 2;
    char *argv[] = {"program_name", "-t"};
    struct sys_parametrs sys = {.command_line_use = FALSEMY}; 

    char arr[50];
    char* ans;
    double a, b, c;

    split(str, &a, &b, &c);

    solve_equation_main(argc, argv, a, b, c, sys, arr);
    
    // подстраиваем выход под строку char * которую поймет CuTest
    ans = ch2ch(arr);

	return ans;
}

// некоторый тест _1 из набора тестов 1_
void Test1_1(CuTest *tc) {
	char* input = strdup("1 1 1");
	char* actual = func(input);
	char* expected = "-0.500000 0.866025 -0.500000 -0.866025";
	CuAssertStrEquals(tc, expected, actual);
}

// Набор тестов Test1
CuSuite* Test1() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Test1_1);
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

1 1 -1 0.618034 -1.618034
1 -1 1 0.500000 0.866025 0.500000 -0.866025
1 -1 -1 1.618034 -0.618034
-1 1 1 -0.618034 1.618034
-1 1 -1 0.500000 -0.866025 0.500000 0.866025
-1 -1 1 -1.618034 0.618034
-1 -1 -1 -0.500000 -0.866025 -0.500000 0.866025
*/