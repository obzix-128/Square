/**@file */

#include "FunctionQwadratka.h"

/**@brief @brief Главная функция.
*@param square Структура в которой хранятся коэффициенты квадратного уравнения, его корни и их кол-во.
*@return Прата сказал надо 0 вернуть.
*/
int main(void)
{
    struct equation square ={NAN, NAN, NAN, 0, 0, ZER};

    Tester();

    char quit;
    do
    {
    printf(DRAW_TEXT(GREEN, "Enter the coefficients of the quadratic equation a, b, c: "));

    error error = NOT_ERROR;

    error = abcGet(&square);

    ErrorList(error);

    SolveSquare(&square);

    print_roots(&square);

    quit_check(&quit);

    } while (quit != '\n');
    return 0;
}
