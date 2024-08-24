#include "Other.h"
#include "UserInteraction.h"

/**@brief The main function.
*@param square The structure in which the
* coefficients of a quadratic equation, its roots and their number are stored.
*@return Prata said it is necessary to return 0.
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("To work with the program, select a mode, to view the list of modes, "
        "enter [-h] after the program name.");
    }
    for(int count = 1; argc > count; count++)
    {
        ErrorNumber check_error = NOT_ERROR;

        switch (argv[count][1])
        {
            case 'h':
                printf(DRAW_TEXT(ORANGE, "[-h] - Help with the program\n"
                "[-t] - Start the program testing mode\n"
                "[-s] - The standard operating mode of the program\n"
                "[-f] - Use this flag and immediately after it write the name of the "
                "file from which you want to take the coefficients "
                "\"f coefficients.txt \"\n"));
                break;
            case 't':
                check_error = testing();

                if(check_error != NOT_ERROR)
                {
                    errorList(check_error);
                    return 0;
                }
                check_error = NOT_ERROR;

                printf(DRAW_TEXT(PURPLE, "Test done.\n"));
                break;
            case 's':
                standartStart();
                break;
            case 'f':
                fileSolveSquare(&argv[count+1]);

                count++;
                break;
            default :
                printf("To work with the program, select a mode, to view the list of modes, "
                "enter [-h] after the program name.");
                break;
        }
    }
    return 0;
}
