/*
 * c/ (DIRECTORY)
 *
 * quadratic_equation.h (FILE NAME)
 * 
*/ 

#ifndef QUADRATIC_EQ_H
#define QUADRATIC_EQ_H

// defines
#define TRUEMY 0 // defining what is true
#define FALSEMY 1 // defining what is a false
#define SEE_ROOTS TRUEMY // Show what the roots are equal to
#define PROGRAM_COMMAND_LINE_ARGS TRUEMY // Use from the command line
#define SEE_PATH_FILE TRUEMY // Whether to show the full path to the file that we are launching
#define ROOT_SEE TRUEMY // Show the entered input a b c
#define TYPE_RESPONSE TRUEMY // The answer type is yes - [x1, x2] or [[c1,c1e], [c2,c2e]], no - as a string x1= x2=
#define TESTING_PROGRAM FALSEMY // If want testing program

struct sys_parametrs;

//Prototipe function for calc ax^2+bx+c=0
int solve_equation(double a, double b, double c, double* root);
void solve_equation_main(int argc, char *argv[], double a, double b, double c, struct sys_parametrs sys, char* ans);

struct sys_parametrs input_args(int argc, char *argv[]);

void ts(double a, double b, double c, char* correct, char* ans);

// enums
enum type_eq // type of equation
{
    full_D_big_null,
    full_D_equal_null,
    full_D_less_null,

    nofull_b_equal_null_D_big_null,
    nofull_b_equal_null_D_less_null,
    nofull_c_equal_null,
    nofull_c_and_b_equal_null
};

enum num_root // number of roots
{
    zero_root = 0,
    one_root_real = 1,
    two_root_real = 2,
    two_root_complex = 4
};

// structs
struct complex // A structure for representing complex numbers
{
    double real_part;
    double image_part;
};

struct data_eq // all possible equation data
{
    int isWhoI; // If 1, then the equation is quadratic, if 0, then the error is
    int type; // type of equation type_eq
    int n_root; // number of roots
    double discr; // the number characterizing the equation
    double x1, x2; // real roots equation
    struct complex cmp1, cmp2; // complex roots equation
};

struct sys_parametrs
{
    int default_see; // Show what the roots are equal to
    int command_line_use; // Use from the command line
    int see_path_line; // Whether to show the full path to the file that we are launching
    int root_see; // Show the entered input a b c
    int type_response; // The answer type is yes - [x1, x2] or [[c1,c1e], [c2,c2e]], no - as a string x1= x2=
    int testing_program; // If want testing program
};

#endif // QUADRATIC_EQ_H