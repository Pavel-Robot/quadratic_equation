/*
 * c/ (DIRECTORY)
 *
 * tests.h (FILE NAME)
 * 
*/ 

#ifndef QUADRATIC_EQ_TEST
#define QUADRATIC_EQ_TEST
#include <assert.h>
#include "quadratic_equation.h"


void ts(double a, double b, double c, char* correct, char* ans){
    int argc = 2;
    char *argv[] = {"program_name", "-t"};

    struct sys_parametrs sys = input_args(argc, argv);  
    sys.command_line_use == FALSEMY;

    solve_equation_main(argc, argv, a, b, c, sys, ans);

    printf("%s\n%s\n", ans, correct);

    //assert(1>2);
}

void tests();
void test1();
void test2();

void tests()
{
    printf("Start testing!\n");
    
    test1();

}
/*
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

void test1()
{
    char ans[50];
    char cor[] = "-0.500000 0.866025 -0.500000 -0.866025";
    
    ts(1, 1, 1, 
        cor,
        ans);
    printf("%s", ans);
    
}

#endif // QUADRATIC_EQ_TEST