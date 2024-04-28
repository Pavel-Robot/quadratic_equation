#include <stdio.h>
#include <math.h>   // sqrt()
#include <stdlib.h> // for malloc() and realloc(), atof()
#include <string.h> // for strcmp(a,b)
#include "quadratic_equation.h"
#include "tests.h"


int main()
{
    RunAllTests(); // or ./a.out -t
        
        return 0;
}


void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	
	CuSuiteAddSuite(suite, Test1());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
