/*
 * c/ (DIRECTORY)
 *
 * tests.h (FILE NAME)
 * 
*/ 

#ifndef QUADRATIC_EQ_TEST
#define QUADRATIC_EQ_TEST
#include "quadratic_equation.c"
#include <assert.h>     /* определение assert */

void fortest(int argc, char *argv[])
{
    /*
    int size = -1;
    double *root = malloc(1 * sizeof(double));
    if (root == NULL)
    {
        fprintf(stderr, "Error: memory is not allocated.\n");
        exit(0);
    }
    else
    {
        if(PROGRAM_COMMAND_LINE_ARGS == TRUEMY)
        size = solve_equation(atof(argv[1]), atof(argv[2]), atof(argv[3]), root);
        else size = solve_equation(1., 4., 4., root);

        // Vision answer
        if (default_see == TRUEMY)
            if (size == -1) // if error
                fprintf(stderr, "Error: size = -1\n");
            else if(size == 1) { // one real root
                if (type_response == FALSEMY)
                {
                    printf("x1,x2 = %f; ", root[0]);
                }
                else
                    printf("%f\n", root[0]);
            }
            else if (size <= 2) // two real root
            {
                if (type_response == FALSEMY)
                {
                    printf("x1 = %f; ", root[0]);
                    printf("x2 = %f;\n", root[1]);
                }
                else
                    printf("%f %f\n", root[0], root[1]);
            }
            else // complex vision
            {
                if (type_response == FALSEMY)
                {
                    printf("c1 = %f + %f*i; ", root[0], root[1]);
                    printf("c2 = %f + %f*i\n", root[2], root[3]);
                }
                else
                    printf("%f %f %f %f\n", root[0], root[1], root[2], root[3]);
            }
    }

    free(root);
    */
}

void tests(){
    printf("Running tests");

    //assert(fortest(2, "1 1 1") == "1 2 3");
}



#endif // QUADRATIC_EQ_TEST