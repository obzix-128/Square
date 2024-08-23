#include "FunctionQwadratka.h"

/**@brief The main function.
*@param square The structure in which the
* coefficients of a quadratic equation, its roots and their number are stored.
*@return Prata said it is necessary to return 0.
*/
int main(int argc, char **argv)
{
    ChoiceMain(argc, argv);

    struct equation square ={NAN, NAN, NAN, NAN, NAN, ZER};

    char quit = '0';
    do
    {

    printf(DRAW_TEXT(GREEN, "Enter the coefficients of the quadratic equation a, b, c: "));

    error error = NOT_ERROR;

    error = abcGet(&square);

    ErrorList(error);

    SolveSquare(&square);

    print_roots(&square);

    quit_check(&quit);

    if (quit != '\n')
        skipLine();

    } while (quit != '\n');
    return 0;
}
