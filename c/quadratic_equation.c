/*
 * c/ (DIRECTORY)
 *
 *
 * quadratic_equation.c (FILE NAME)
 *
 *		Module quadratic_equation for calc equations.
 *      By Verevkin Pavel Nikolaevich from University Science and Technology
 *      in city Krasnoyarsk, student-magistry, email: verevkinpavel1997@mail.ru
 *                                    telegram: https://t.me/PublicHeroWin
 */

#include <stdio.h>
#include <math.h>   // sqrt()
#include <stdlib.h> // for malloc() and realloc(), atof()
#include <string.h> // for strcmp(a,b)
#include "quadratic_equation.h"
#include "tests.h"


int main(int argc, char *argv[])
{
    /* Example use program and testing module */

    // Set parametrs 
    struct sys_parametrs sys = input_args(argc, argv);

    // Solve eq or do tests
    if(sys.testing_program == TRUEMY) tests();
    else {
        char ans[50]; // answer
        solve_equation_main(argc, argv, 1., 2., 3., sys, ans);
        printf("%s", ans);
    }
    
    
    return 0;
}

// Function for calc ax^2+bx+c=0
int solve_equation(double a, double b, double c, double *root)
{
    struct data_eq data = {.isWhoI = -1, .type = -1};

    if (a != 0) // If the equation is quadratic, the coefficient 'a' must be nonzero
    {
        data.isWhoI = 1;

        if (b != 0 && c != 0) // If the equation is complete, then there will be 3 cases
        {
            data.discr = b * b - 4 * a * c;

            if (data.discr > 0) // D>0 We have two real roots
            {
                data.type = full_D_big_null;
                data.n_root = two_root_real;
                data.x1 = (-b + sqrt(data.discr)) / (2 * a);
                data.x2 = (-b - sqrt(data.discr)) / (2 * a);

                root = (double *)realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                root[1] = data.x2;
                return data.n_root;
            }
            else if (data.discr == 0) // D=0 We have one real root
            {
                data.type = full_D_equal_null;
                data.n_root = one_root_real;
                data.x1 = -b / (2 * a);
                data.x2 = data.x1;

                root = (double *)realloc(root, sizeof(double) * 1);
                root[0] = data.x1;
                return data.n_root;
            }
            else if (data.discr < 0) // D<0 We have two complex root
            {
                data.type = full_D_less_null;
                data.n_root = two_root_complex;
                // real_part is the same at the two roots, image_part differs in sign
                data.cmp1.real_part = -b / (2 * a);
                data.cmp1.image_part = sqrt(-data.discr) / (2 * a);
                data.cmp2.real_part = data.cmp1.real_part;
                data.cmp2.image_part = -1 * data.cmp1.image_part;

                root = (double *)realloc(root, sizeof(double) * 4);
                root[0] = data.cmp1.real_part;
                root[1] = data.cmp1.image_part;
                root[2] = data.cmp2.real_part;
                root[3] = data.cmp2.image_part;
                return data.n_root;
            }
        }
        else // if the equation is incomplete and one of the coefficients b=0,c=0 is zero
        {
            if (b == 0 && c != 0)
            {
                data.discr = -c / a;
                if (data.discr > 0) // There will be two solutions
                {
                    data.type = nofull_b_equal_null_D_big_null;
                    data.n_root = two_root_real;
                    data.x1 = sqrt(data.discr);
                    data.x2 = -data.x1;

                    root = (double *)realloc(root, sizeof(double) * 2);
                    root[0] = data.x1;
                    root[1] = data.x2;
                    return data.n_root;
                }
                else // -c/a < 0
                {
                    data.type = nofull_b_equal_null_D_less_null;
                    data.n_root = two_root_complex;
                    data.cmp1.real_part = 0;
                    data.cmp1.image_part = sqrt(-data.discr);
                    data.cmp2.real_part = 0;
                    data.cmp2.image_part = -data.cmp1.image_part;

                    root = (double *)realloc(root, sizeof(double) * 4);
                    root[0] = data.cmp1.real_part;
                    root[1] = data.cmp1.image_part;
                    root[2] = data.cmp2.real_part;
                    root[3] = data.cmp2.image_part;
                    return data.n_root;
                }
            }
            else if (c == 0 && b != 0)
            {
                data.type = nofull_c_equal_null;
                data.n_root = two_root_real;
                data.x1 = 0;
                data.x2 = -b / a;

                root = (double *)realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                root[1] = data.x2;
                return data.n_root;
            }
            else // If b=0 and c=0, then x1=0 and x2=0
            {
                data.type = nofull_c_and_b_equal_null;
                data.n_root = one_root_real;
                data.x1 = 0;
                data.x2 = 0;

                root = (double *)realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                return data.n_root;
            }
        }
    }
    else
    {
        data.isWhoI = 0;
        fprintf(stderr, "Error: this is not a quadratic equation because a=0\n");
        exit(0);
    }
}

// How use function
void solve_equation_main(int argc, char *argv[], double a, double b, double c, struct sys_parametrs sys, char* ans)
{
    char str_buffer[50];

    int size = -1;
    double *root = (double *)malloc(1 * sizeof(double));
    if (root == NULL)
    {
        fprintf(stderr, "Error: memory is not allocated.\n");
        exit(0);
    }
    else
    {
        #if 1
        if(sys.command_line_use == TRUEMY)
             size = solve_equation(atof(argv[1]), atof(argv[2]), atof(argv[3]), root);
        else size = solve_equation(a, b, c, root);
        #endif

        // Vision answer
        if (sys.default_see == TRUEMY)
            if (size == -1) // if error
            {
                strcat(ans, "Error: size = -1");
                //fprintf(stderr, "Error: size = -1\n");
            }
            else if(size == 1) { // one real root
                if (sys.type_response == FALSEMY)
                {
                    snprintf(str_buffer, sizeof str_buffer, "x1,x2 = %f; ", root[0]);
                    strcat(ans, str_buffer);
                    //printf("x1,x2 = %f; ", root[0]);
                }
                else
                {
                    snprintf(str_buffer, sizeof str_buffer, "%f", root[0]);
                    strcat(ans, str_buffer);
                    //printf("%f\n", root[0]);
                }
                    
            }
            else if (size <= 2) // two real root
            {
                if (sys.type_response == FALSEMY)
                {
                    snprintf(str_buffer, sizeof str_buffer, "x1 = %f; ", root[0]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, "x2 = %f;", root[1]);
                    strcat(ans, str_buffer);

                    //printf("x1 = %f; ", root[0]);
                    //printf("x2 = %f;\n", root[1]);
                }
                else
                    {
                        snprintf(str_buffer, sizeof str_buffer, "%f", root[0]);
                        strcat(ans, str_buffer);
                        snprintf(str_buffer, sizeof str_buffer, " %f", root[1]);
                        strcat(ans, str_buffer);

                        //printf("%f %f\n", root[0], root[1]);
                    }
                    
            }
            else // complex vision
            {
                if (sys.type_response == FALSEMY)
                {
                    snprintf(str_buffer, sizeof str_buffer, "c1 = %f + ", root[0]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, "%f*i; ", root[1]);
                    strcat(ans, str_buffer);

                    snprintf(str_buffer, sizeof str_buffer, "c2 = %f + ", root[2]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, "%f*i;", root[3]);
                    strcat(ans, str_buffer);

                    //printf("c1 = %f + %f*i; ", root[0], root[1]);
                    //printf("c2 = %f + %f*i\n", root[2], root[3]);
                }
                else
                {
                    snprintf(str_buffer, sizeof str_buffer, "%f", root[0]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, " %f", root[1]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, " %f", root[2]);
                    strcat(ans, str_buffer);
                    snprintf(str_buffer, sizeof str_buffer, " %f", root[3]);
                    strcat(ans, str_buffer);

                    //printf("%f %f %f %f\n", root[0], root[1], root[2], root[3]);
                }
                    
            }
    }

    free(root);
}

struct sys_parametrs input_args(int argc, char *argv[])
{
    struct sys_parametrs sys = {SEE_ROOTS,
                                PROGRAM_COMMAND_LINE_ARGS, 
                                SEE_PATH_FILE, ROOT_SEE,
                                TYPE_RESPONSE, 
                                TESTING_PROGRAM};

    // To use the program from the command line
    if (sys.command_line_use == TRUEMY)
    {

        // If there are few arguments (count for argc from 1, for argv from 0)
        if (argc <= 1)
        {
            fprintf(stderr, "Error: invalid number of arguments <=1\n");
            exit(1);
        }

        if (strcmp(argv[1], "-t") == TRUEMY)
        {
            sys.testing_program = FALSEMY;

            //tests();

            exit(400);
        }

        // Help for arguments and examples
        if (strcmp(argv[1], "-h") == TRUEMY)
        {
            puts("This is the quadratic_equation module for calculating ax^2+bx+c=0.");
            puts("You have called help -h or testing -t.");
            puts("Example use: ./quadratic_equation 1 1 1");
            puts("Arguments:");
            puts("[1] = a [2] = b [3] = c");
            puts("[4] = -y/-n -- whether to show the roots of the equation (by default, Yes)");
            puts("Example use: ./quadratic_equation 1 1 1 -y");
            puts("[5] = -yp/-np -- Whether to show the full path to the file (by default, No)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp");
            puts("[6] = -yr/-nr -- Whether to show the entered a b c (by default, No)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp -yr");
            puts("[[7] = -mas/-mas -- Show the response type y max - [x1, x2] or [[c1,c1i], [c2,c2i]], nmas - as a string x1=.0 x2=.0 (default -ymaps)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp -yr -ymas");
            exit(2);
        }

        // Checking for the allowed number of arguments
        if (argc < 4 || argc > 8)
        {
            fprintf(stderr, "Incorrect number of parameters : must be <4 or >8 : entered :%d\n", argc);
            exit(3);
        }

        // Checking for input and error for an argument [4]
        if (argc == 5)
            if (strcmp(argv[4], "-y") == TRUEMY)
            {
                ;
            }
            else if (strcmp(argv[4], "-n") == TRUEMY)
            {
                sys.default_see = FALSEMY;
            }
            else
            {
                fprintf(stderr, "The argument [4] can only be -y/-n\n");
                exit(4);
            }

        // Checking for input and error for an argument [5]
        if (argc == 6)
            if (strcmp(argv[5], "-yp") == TRUEMY)
            {
                sys.see_path_line = TRUEMY;
                puts(argv[0]);
            }
            else if (strcmp(argv[5], "-np") == TRUEMY)
            {
                sys.see_path_line = FALSEMY;
            }
            else
            {
                fprintf(stderr, "The argument [5] can only be -yp/-np\n");
                exit(5);
            }

        // Input check and error for the argument [6]
        if (argc == 7)
            if (strcmp(argv[6], "-yr") == TRUEMY)
            {
                sys.root_see = TRUEMY;
                puts(argv[1]);
                puts(argv[2]);
                puts(argv[3]);
            }
            else if (strcmp(argv[6], "-nr") == TRUEMY)
            {
                sys.root_see = FALSEMY;
            }
            else
            {
                fprintf(stderr, "The argument [6] can only be -yr/-nr\n");
                exit(6);
            }

        // Input check and error for the argument [7]
        if (argc == 8)
            if (strcmp(argv[7], "-ymas") == TRUEMY)
            {
                sys.type_response = TRUEMY;
            }
            else if (strcmp(argv[7], "-nmas") == TRUEMY)
            {
                sys.type_response = FALSEMY;
            }
            else
            {
                fprintf(stderr, "The argument [7] can only be -y mas/-mas\n");
                exit(7);
            }
    }

    return sys;
   
}


