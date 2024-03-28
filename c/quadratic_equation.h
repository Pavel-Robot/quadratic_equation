#ifndef QUADRATIC_EQ_H
#define QUADRATIC_EQ_H

// defines
#define TRUEMY 0 // определение что является правдой
#define FALSEMY 1 // определение что является ложью
#define SEE_ROOTS TRUEMY // Показывать чему равны корни
#define PROGRAM_COMMAND_LINE_ARGS TRUEMY // Использовать из командной строки
#define SEE_PATH_FILE TRUEMY // Показывать ли полный путь к файлу, который запускаем
#define ROOT_SEE TRUEMY // Показывать введенные входные a b c
#define TYPE_RESPONSE TRUEMY // Тип ответа  yes - [x1, x2] или [[c1r,c1i], [c2r,c2i]], no - в виде строки x1= x2=


//Prototipe function for calc ax^2+bx+c=0
int solve_equation(double a, double b, double c, double* root);

// enums
enum type_eq // тип уравнения
{
    full_D_big_null,
    full_D_equal_null,
    full_D_less_null,

    nofull_b_equal_null_D_big_null,
    nofull_b_equal_null_D_less_null,
    nofull_c_equal_null,
    nofull_c_and_b_equal_null
};

enum num_root // количество корней
{
    zero_root = 0,
    one_root_real = 1,
    two_root_real = 2,
    two_root_complex = 4
};

// structs
struct complex // Структура для представления комплексных чисел
{
    double real_part;
    double image_part;
};

struct data_eq // все возможные данные уравнения
{
    int isWhoI; // Если 1, то уравнение квадртаичное, если 0, то ошибка
    int type; // тип уравнения type_eq
    int n_root; // количество корней
    double discr; // the number characterizing the equation
    double x1, x2; // real roots equation
    struct complex cmp1, cmp2; // complex roots equation
};

#endif // QUADRATIC_EQ_H