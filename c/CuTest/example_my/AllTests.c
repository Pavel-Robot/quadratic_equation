// gcc AllTests.c lib/CuTest.c StrUtil.c
// or cc -Wall -g -I. -Wno-address -lm -o bin/CuTestTest AllTests.c CuTestTest.c CuTest.c
#include "lib/CuTest.h"

CuSuite* StrUtilGetSuite();

void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	
	CuSuiteAddSuite(suite, StrUtilGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void) {
	RunAllTests();
}