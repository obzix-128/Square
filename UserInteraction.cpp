#include "UserInteraction.h"
#include "SolvingQuadraticEquation.h"
#include "SkipLine.h"

void checkQuit(char *quit)
{
    printf(DRAW_TEXT(BLUE, "Type [enter] to exit the program or any other character to contiune:\n"));

    int check_error = scanf("%c", quit);
    MYASSERT(check_error);

    if (*quit != '\n')
        skipLine();
}

ErrorNumber abcGet(Equation *quadratic_equation)
{
    MYASSERT((quadratic_equation != NULL));

    int attempt = 0;

    while (scanf("%lf %lf %lf", &quadratic_equation->a, &quadratic_equation->b,
                                                        &quadratic_equation->c) != 3)
    {
        skipLine();

        if(attempt >= 3)
            return ERROR_INPUT;

        printf(DRAW_TEXT(RED, "Input error. Enter the values of the coefficients a, b, c using numbers: "));
        attempt++;
    }

    MYASSERT(isfinite(quadratic_equation->a));
    MYASSERT(isfinite(quadratic_equation->b));
    MYASSERT(isfinite(quadratic_equation->c));

    skipLine();

    printf(DRAW_TEXT(GREEN, "The values are accepted: a = %lg; b = %lg; c = %lg\n"),
    quadratic_equation->a, quadratic_equation->b, quadratic_equation->c);

    return NOT_ERROR;
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
            fprintf(stderr, DRAW_TEXT(RED, "ERROR : Couldn't read the data from the file\n"));
            break;
        case SCANNING_ERROR :
            fprintf(stderr, DRAW_TEXT(RED, "ERROR : It was not possible to read the received data\n"));
            break;
        case TEST_ERROR :
            break;
        default:
            fprintf(stderr, DRAW_TEXT(RED, "Unknown Error\n"));
            break;
    }
}

ErrorNumber startSolveSquare(void)
{
    struct Equation square ={NAN, NAN, NAN, NAN, NAN, ZERO_ROOTS};
    char quit = '0';

    do
    {
        printf(DRAW_TEXT(GREEN, "Enter the coefficients of the quadratic Equation a, b, c: "));

        ErrorNumber reading_status = abcGet(&square);
        if(reading_status != NOT_ERROR)
            return reading_status;

        solveSquare(&square);
        printRoots(&square);
        checkQuit(&quit);

    } while (quit != '\n');
    return NOT_ERROR;
}

void printRoots(Equation *quadratic_equation)
{
        switch(quadratic_equation->number_of_roots)
    {
        case ZERO_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has no roots\n"));
            break;
        case ONE_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has one root equal to: %lg\n"), quadratic_equation->x1); // TODO: отрицательный ноль
            break;
        case TWO_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has two roots: x1 = %lg x2 = %lg\n"), quadratic_equation->x1, quadratic_equation->x2);
            break;
        case INFINITY_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has infinitely many solutions\n"));
            break;
        default:
            fprintf(stderr, DRAW_TEXT(RED, "Error, impossible number of roots\n"));
            break;
    }
}
