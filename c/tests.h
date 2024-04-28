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

void RunAllTests(void); // Runs all tests, contains suite tests
CuSuite* Test1(); // Test Suite 1, contains subtests
CuSuite* Test2(); // Test Suite 2, contains subtests
CuSuite* Test3(); // Test Suite 3, contains subtests

char* ch2ch(char *s); // The function reduces the C-style string to size \0 and returns a pointer to a new one
void split(char* str, double *a, double *b, double *c); // A function for parsing an input string and writing values to variables
char* func(char* str); // The function under test


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
 
char* func(char* str) {

    int argc = 2;
    char *argv[] = {"program_name", "-t"};
    struct sys_parametrs sys = {.command_line_use = FALSEMY}; 

    char arr[256];
    char* ans;
    double a, b, c;

    split(str, &a, &b, &c);

    solve_equation_main(argc, argv, a, b, c, sys, arr);
    
    // adjusting the output to the char * string that CuTest will understand
    ans = ch2ch(arr);

	return ans;
}

/*
 * =================================================================================
 * #Test1#
 * Description: Testing when all the input units, the options are different in sign
 * =================================================================================
*/

// Some test _1 from test suite 
void Test1_1(CuTest *tc) {
	char* input = strdup("1 1 1");
	char* actual = func(input);
	char* expected = "-0.500000 0.866025 -0.500000 -0.866025";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_2(CuTest *tc) {
	char* input = strdup("1 1 -1");
	char* actual = func(input);
	char* expected = "0.618034 -1.618034";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_3(CuTest *tc) {
	char* input = strdup("1 -1 1");
	char* actual = func(input);
	char* expected = "0.500000 0.866025 0.500000 -0.866025";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_4(CuTest *tc) {
	char* input = strdup("1 -1 -1");
	char* actual = func(input);
	char* expected = "1.618034 -0.618034";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_5(CuTest *tc) {
	char* input = strdup("-1 1 1");
	char* actual = func(input);
	char* expected = "-0.618034 1.618034";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_6(CuTest *tc) {
	char* input = strdup("-1 1 -1");
	char* actual = func(input);
	char* expected = "0.500000 -0.866025 0.500000 0.866025";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_7(CuTest *tc) {
	char* input = strdup("-1 -1 1");
	char* actual = func(input);
	char* expected = "-1.618034 0.618034";
	CuAssertStrEquals(tc, expected, actual);
}

void Test1_8(CuTest *tc) {
	char* input = strdup("-1 -1 -1");
	char* actual = func(input);
	char* expected = "-0.500000 -0.866025 -0.500000 0.866025";
	CuAssertStrEquals(tc, expected, actual);
}

// Test1 Test Suite
CuSuite* Test1() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Test1_1);
    SUITE_ADD_TEST(suite, Test1_2);
    SUITE_ADD_TEST(suite, Test1_3);
    SUITE_ADD_TEST(suite, Test1_4);
    SUITE_ADD_TEST(suite, Test1_5);
    SUITE_ADD_TEST(suite, Test1_6);
    SUITE_ADD_TEST(suite, Test1_7);
    SUITE_ADD_TEST(suite, Test1_8);
	return suite;
}


/*
 * =================================================================================
 * #Test2#
 * Description: Testing when the input unit is at 1 and 3 positions
 * Testing when the input unit is at 1 and 2 positions
 * Testing when all input units are one for 1 position
 * =================================================================================
*/

void Test2_1(CuTest *tc) {
	char* input = strdup("1 0 1");
	char* actual = func(input);
	char* expected = "0.000000 1.000000 0.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_2(CuTest *tc) {
	char* input = strdup("1 0 -1");
	char* actual = func(input);
	char* expected = "1.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_3(CuTest *tc) {
	char* input = strdup("-1 0 1");
	char* actual = func(input);
	char* expected = "1.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_4(CuTest *tc) {
	char* input = strdup("-1 0 -1");
	char* actual = func(input);
	char* expected = "0.000000 1.000000 0.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_5(CuTest *tc) {
	char* input = strdup("1 1 0");
	char* actual = func(input);
	char* expected = "0.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_6(CuTest *tc) {
	char* input = strdup("1 -1 0");
	char* actual = func(input);
	char* expected = "0.000000 1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_7(CuTest *tc) {
	char* input = strdup("-1 1 0");
	char* actual = func(input);
	char* expected = "0.000000 1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_8(CuTest *tc) {
	char* input = strdup("-1 -1 0");
	char* actual = func(input);
	char* expected = "0.000000 -1.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_9(CuTest *tc) {
	char* input = strdup("1 0 0");
	char* actual = func(input);
	char* expected = "0.000000";
	CuAssertStrEquals(tc, expected, actual);
}

void Test2_10(CuTest *tc) {
	char* input = strdup("-1 0 0");
	char* actual = func(input);
	char* expected = "0.000000";
	CuAssertStrEquals(tc, expected, actual);
}

//  For D == 0
void Test2_11(CuTest *tc) {
	char* input = strdup("1 4 4");
	char* actual = func(input);
	char* expected = "-2.000000";
	CuAssertStrEquals(tc, expected, actual);
}

//  For D > 0
void Test2_12(CuTest *tc) {
	char* input = strdup("2 7 4");
	char* actual = func(input);
	char* expected = "-0.719224 -2.780776";
	CuAssertStrEquals(tc, expected, actual);
}

/*
//  For 0 0 0
void Test2_1(CuTest *tc) {
	char* input = strdup("0 0 0");
	char* actual = func(input);
	char* expected = "-0.719224 -2.780776";
	CuAssertStrEquals(tc, expected, actual);
}
*/

CuSuite* Test2() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Test2_1);
    SUITE_ADD_TEST(suite, Test2_2);
    SUITE_ADD_TEST(suite, Test2_3);
    SUITE_ADD_TEST(suite, Test2_4);
    SUITE_ADD_TEST(suite, Test2_5);
    SUITE_ADD_TEST(suite, Test2_6);
    SUITE_ADD_TEST(suite, Test2_7);
    SUITE_ADD_TEST(suite, Test2_8);
    SUITE_ADD_TEST(suite, Test2_9);
    SUITE_ADD_TEST(suite, Test2_10);
    SUITE_ADD_TEST(suite, Test2_11);
    SUITE_ADD_TEST(suite, Test2_12);
	return suite;
}


/*
 * =================================================================================
 * #Test3#
 * Description: Testing when the input unit is at 2 and 3 positions -> ERROR
 * =================================================================================
*/

void Test3_1(CuTest *tc) {
	char* input = strdup("0 0 0");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_2(CuTest *tc) {
	char* input = strdup("0 1 1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_3(CuTest *tc) {
	char* input = strdup("0 1 -1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_4(CuTest *tc) {
	char* input = strdup("0 -1 1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_5(CuTest *tc) {
	char* input = strdup("0 -1 -1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_6(CuTest *tc) {
	char* input = strdup("0 0 1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_7(CuTest *tc) {
	char* input = strdup("0 0 -1");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_8(CuTest *tc) {
	char* input = strdup("0 1 0");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}

void Test3_9(CuTest *tc) {
	char* input = strdup("0 -1 0");
	char* actual = func(input);
	char* expected = "Error: this is not a quadratic equation because a=0";
	CuAssertStrEquals(tc, expected, actual);
}


CuSuite* Test3() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Test3_1);
    SUITE_ADD_TEST(suite, Test3_2);
    SUITE_ADD_TEST(suite, Test3_3);
    SUITE_ADD_TEST(suite, Test3_4);
    SUITE_ADD_TEST(suite, Test3_5);
    SUITE_ADD_TEST(suite, Test3_6);
    SUITE_ADD_TEST(suite, Test3_7);
    SUITE_ADD_TEST(suite, Test3_8);
    SUITE_ADD_TEST(suite, Test3_9);
	return suite;
}

#endif // QUADRATIC_EQ_TEST

