#include "UserInteraction.h" // TODO: название файла...
#include "Other.h"
#include "SkipLine.h"

void checkQuit(char *quit)
{
    printf(DRAW_TEXT(BLUE, "Type [enter] to exit the program or any other character to contiune:\n"));

    int check_error = scanf("%c", quit);
    MYASSERT(check_error);
}

int abcGet(struct Equation *quadratic_equation)
{
    MYASSERT(quadratic_equation != NULL);

    int attempt = 0;

    while (scanf("%lf %lf %lf", &quadratic_equation->a, &quadratic_equation->b, &quadratic_equation->c) != 3)
    {
        skipLine();

        if(attempt >= 3)
            {
            errorList(ERROR_INPUT);
            return 0;
            }

        printf(DRAW_TEXT(RED, "Input error. Enter the values of the coefficients a, b, c using numbers: "));
        attempt++;
    }

    MYASSERT(isfinite(quadratic_equation->a));
    MYASSERT(isfinite(quadratic_equation->b));
    MYASSERT(isfinite(quadratic_equation->c));

    skipLine();

    printf(DRAW_TEXT(GREEN, "The values are accepted: a = %lg; b = %lg; c = %lg\n"), quadratic_equation->a, quadratic_equation->b, quadratic_equation->c);
}

void errorList(ErrorNumber error_name)
{
    switch(error_name)
    {
        case NOT_ERROR:
            break;
        case ERROR_INPUT:
            fprintf(stderr, DRAW_TEXT(RED, "ERROR: The limit of input attempts has been exceeded\n"));
            break;
        case READING_ERROR :
            fprintf(stderr, DRAW_TEXT(RED, "ERROR : Couldn't read the data from the file"));
            break;
        case SCANNING_ERROR :
            fprintf(stderr, DRAW_TEXT(RED, "ERROR : It was not possible to read the received data"));
            break;
        case TEST_ERROR :
            break;
        default:
            fprintf(stderr, DRAW_TEXT(RED, "Unknown error\n"));
            break;
    }
}

int standartStart(void)
{
    struct Equation square ={NAN, NAN, NAN, NAN, NAN, ZERO_ROOTS};
    char quit = '0';

    do
    {
        printf(DRAW_TEXT(GREEN, "Enter the coefficients of the quadratic Equation a, b, c: "));

        int reading_status = abcGet(&square);
        if(reading_status == 0)
            return 0;
        solveSquare(&square);
        printRoots(&square);
        checkQuit(&quit);

        if (quit != '\n')
        skipLine();

    } while (quit != '\n');
}
