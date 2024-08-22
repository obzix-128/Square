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

    printf("\033[92mEnter the coefficients of the quadratic equation "
    "\033[93ma\033[0m, \033[94mb\033[0m, \033[95mc\033[0m:\n\033[0m");

    abcGet(&square);

    SolveSquare(&square);

    print_roots(&square);

    return 0;
}
