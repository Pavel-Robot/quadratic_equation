// Module quadratic_equation for calc equations
// By Verevkin Pavel Nikolaevich from University Science and Technology
// // in city Krasnoyarsk, student-magistry, email: verevkinpavel1997@mail.ru

#include <stdio.h>
#include <math.h> // sqrt()
#include <stdlib.h> // for malloc() and realloc(), atof()
#include <string.h> // for strcmp(a,b)
#include "quadratic_equation.h"

int main(int argc, char *argv[])
{
    int default_see = SEE_ROOTS;
    //int command_line_use = PROGRAM_COMMAND_LINE_ARGS;
    int see_path_line = SEE_PATH_FILE;
    int root_see = ROOT_SEE;
    int type_response = TYPE_RESPONSE;

    // Для использования программы из командной строки
    if(PROGRAM_COMMAND_LINE_ARGS == TRUEMY){

        // Если мало аргументов
        if(argc <= 1) {puts("Неверное количество аргументов <=1"); return 1;}

        // Справка по аргуметам и примеры
        if(strcmp(argv[1], "-h") == TRUEMY)
        {
            puts("Это модуль quadratic_equation для вычисления ax^2+bx+c=0.");
            puts("Вы вызвали справку help -h.");
            puts("Example use: ./quadratic_equation 1 1 1");
            puts("Аргументы:");
            puts("[1] = a [2] = b [3] = c");
            puts("[4] = -y/-n -- показывать ли корни уравнения (по умолчанию - Да)");
            puts("Example use: ./quadratic_equation 1 1 1 -y");
            puts("[5] = -yp/-np -- Показывать ли полный путь к файлу (по умолчанию - Нет)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp");
            puts("[6] = -yr/-nr -- Показывать ли введенные a b c (по умолчанию - Нет)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp -yr");
            puts("[7] = -ymas/-nmas -- Показывать тип ответа  ymas - [x1, x2] или [[c1r,c1i], [c2r,c2i]], nmas - в виде строки x1= x2= (по умолчанию -ymas)");
            puts("Example use: ./quadratic_equation 1 1 1 -y -yp -yr -ymas");
            return 2;
        }

        // Проверка на допустимое количество аргументов
        if(argc < 4 || argc > 8) { puts("Неверное количество параметров : должно 3-7 : введено :"); puts(argc); return 3;}

        // Проверка на ввод и ошибка для аргумента [4]
        if(strcmp(argv[4], "-y") == TRUEMY) {default_see = TRUEMY;}
        else if(strcmp(argv[4], "-n") == TRUEMY) {default_see = FALSEMY;}
        else { puts("Аргументом [4] может быть только -y/-n"); return 4;}

        // Проверка на ввод и ошибка для аргумента [5]        
        if(strcmp(argv[5], "-yp") == TRUEMY) {see_path_line = TRUEMY; puts(argv[0]);}
        else if(strcmp(argv[5], "-np") == TRUEMY) {see_path_line = FALSEMY;}
        else { puts("Аргументом [5] может быть только -yp/-np"); return 5;}       

        // Проверка на ввод и ошибка для аргумента [6]
        if(strcmp(argv[6], "-yr") == TRUEMY) {root_see = TRUEMY; puts(argv[1]); puts(argv[2]); puts(argv[3]);}
        else if(strcmp(argv[6], "-nr") == TRUEMY) {root_see = FALSEMY;}
        else { puts("Аргументом [6] может быть только -yr/-nr"); return 6;}    

        // Проверка на ввод и ошибка для аргумента [7]
        if(strcmp(argv[7], "-ymas") == TRUEMY) {type_response = TRUEMY;}
        else if(strcmp(argv[7], "-nmas") == TRUEMY) {type_response = FALSEMY;}
        else { puts("Аргументом [7] может быть только -y/-n"); return 7;}

    }

    // How use function
    int size = -1;
    double* root = malloc(1 * sizeof(double));
    if(root == NULL) 
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else 
    {
        size = solve_equation(atof(argv[1]), atof(argv[2]), atof(argv[3]), root);

        // Отображение
        if(default_see == TRUEMY)
        if(size == -1) printf("Error: size = -1");
        else if(size <= 2)
        {   
            if(type_response == FALSEMY)
            {
            printf("x1 = %f; ", root[0]);
            printf("x2 = %f;\n", root[1]);
            } else printf("%f %f\n", root[0], root[1]);
        } else
        {
            if(type_response == FALSEMY)
            {
            printf("cl = %f + %f*i; ", root[0], root[1]);
            printf("c2 = %f + %f*i\n", root[2], root[3]);
            } else printf("%f %f %f %f\n", root[0], root[1], root[2], root[3]);
        }
    }
    
    return 0;
}

//Function for calc ax^2+bx+c=0
int solve_equation(double a, double b, double c, double* root)
{
    struct data_eq data = {.isWhoI=-1, .type=-1};

    if(a != 0) // Если уравнение квадратичное коэффициент 'a' должен быть отличен от нуля 
    { 
        data.isWhoI = 1;

        if(b != 0 && c != 0) // Если уравнение полное, то будет 3 случая
        {
            data.discr = b*b - 4 * a * c;

            if(data.discr > 0) // D>0 We have two real roots
            {
                data.type = full_D_big_null;
                data.n_root = two_root_real;
                data.x1 = (-b + sqrt(data.discr)) / (2*a);
                data.x2 = (-b - sqrt(data.discr)) / (2*a);

                root = realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                root[1] = data.x2;
                return data.n_root;
            }
            else if(data.discr == 0) // D=0 We have one real root
            {
                data.type = full_D_equal_null;
                data.n_root = one_root_real;
                data.x1 = -b / (2*a);
                data.x2 = data.x1;

                root = realloc(root, sizeof(double) * 1);
                root[0] = data.x1;
                return data.n_root;
            }
            else if(data.discr < 0) // D<0 We have two complex root
            {
                data.type = full_D_less_null;
                data.n_root = two_root_complex;
                // real_part is the same at the two roots, image_part differs in sign
                data.cmp1.real_part = -b / (2*a);
                data.cmp1.image_part = sqrt(-data.discr) / (2*a);
                data.cmp2.real_part = data.cmp1.real_part;
                data.cmp2.image_part = -1 * data.cmp1.image_part;

                root = realloc(root, sizeof(double) * 4);
                root[0] = data.cmp1.real_part;
                root[1] = data.cmp1.image_part;
                root[2] = data.cmp2.real_part;
                root[3] = data.cmp2.image_part;
                return data.n_root;
            }

        } else // если уравнение не полное и один из коэффициентов b=0,c=0 равен нулю
        {
            if(b == 0 && c != 0)
            {
                data.discr = -c / a;
                if(data.discr > 0) // Будет два решения
                {
                    data.type = nofull_b_equal_null_D_big_null;
                    data.n_root = two_root_real;
                    data.x1 = sqrt(data.discr);
                    data.x2 = -data.x1;

                    root = realloc(root, sizeof(double) * 2);
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

                    root = realloc(root, sizeof(double) * 4);
                    root[0] = data.cmp1.real_part;
                    root[1] = data.cmp1.image_part;
                    root[2] = data.cmp2.real_part;
                    root[3] = data.cmp2.image_part;
                    return data.n_root;
                }
            } else if(c == 0 && b != 0)
            {
                data.type = nofull_c_equal_null;
                data.n_root = two_root_real;
                data.x1 = 0;
                data.x2 = -b / a;

                root = realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                root[1] = data.x2;
                return data.n_root;
            } else // Если b=0 и c=0, то x12=0 
            {
                data.type = nofull_c_and_b_equal_null;
                data.n_root = one_root_real;
                data.x1 = 0;
                data.x2 = 0;

                root = realloc(root, sizeof(double) * 2);
                root[0] = data.x1;
                return data.n_root;
            }
        }
    } else 
    { 
        data.isWhoI = 0;
        fprintf(stderr, "Ошибка: это не квадратичное уравнение т.к. a=0\n");
        exit(0);
    }

}





