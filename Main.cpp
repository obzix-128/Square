#include "SolvingQuadraticEquation.h"
#include "UserInteraction.h"
#include "ErrorNumber.h"

/**@brief The main function.
*@param square The structure in which the
* coefficients of a quadratic equation, its roots and their number are stored.
*@return Prata said it is necessary to return 0.
*/

int main(const int argc,const char **argv)
{
    const int MIN_ARG_COUNT = 2;

    if (argc < MIN_ARG_COUNT)
    {
        printf(DRAW_TEXT(ORANGE, "To work with the program, select a mode, to "
        "view the list of modes, enter [-h] after the program name."));
    }

    ErrorNumber check_error = NOT_ERROR;
    for(int count = 1; argc > count; count++)
    {
        if(argv[count][0] != '-')
        {
            printf(DRAW_TEXT(ORANGE, "To work with the program, select a mode, to "
            "view the list of modes, enter [-h] after the program name."));
            return 0;
        }

        switch (argv[count][1])
        {
            case 'h':
                printf(DRAW_TEXT(ORANGE, "[-h] - Help with the program\n"
                "[-t] - Start the program testing mode\n"
                "[-s] - Enter the coefficients and solve the quadratic equation\n"
                "[-f] - Use this flag and immediately after it write the name of the "
                "file from which you want to take the coefficients "
                "\"f coefficients.txt \"\n"));
                break;
            case 't':
                check_error = testingSolveSquare();

                errorList(check_error);

                if(check_error == NOT_ERROR)
                    printf(DRAW_TEXT(PURPLE, "Test done.\n"));
                break;
            case 's':
                check_error = startSolveSquare();

                errorList(check_error);
                break;
            case 'f':
                check_error = fileSolveSquare(argv[count+1]);
                count++;

                errorList(check_error);
                break;
            default:
                printf(DRAW_TEXT(ORANGE, "To work with the program, select a mode, to "
                "view the list of modes, enter [-h] after the program name."));
                break;
        }
    }
    return 0;
}
