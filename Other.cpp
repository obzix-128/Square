#include "Other.h"
#include "WorkWithDouble.h"

void solveSquare(struct Equation *quadratic_equation)
{
    if (isZero(quadratic_equation->a))
    {
        if(isZero(quadratic_equation->b))
        {
            quadratic_equation->number_of_roots =
            (isZero(quadratic_equation->c))? INFINITY_ROOTS : ZERO_ROOTS;
        }
        else
        {
            quadratic_equation->x1 = -quadratic_equation->c/quadratic_equation->b;
            quadratic_equation->number_of_roots = ONE_ROOTS;

            MYASSERT(isfinite(quadratic_equation->x1));
        }
    }
    else
    {
        double d = quadratic_equation->b*quadratic_equation->b - 4*quadratic_equation->a*quadratic_equation->c;

        if (isZero(d))
        {
            quadratic_equation->x1 = quadratic_equation->x2 = -quadratic_equation->b/(2*quadratic_equation->a);
            quadratic_equation->number_of_roots = ONE_ROOTS;

            MYASSERT(isfinite(quadratic_equation->x1));
            MYASSERT(isfinite(quadratic_equation->x2));
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt (d);

            quadratic_equation->x1 = (-quadratic_equation->b - sqrt_d)/(2*quadratic_equation->a);
            quadratic_equation->x2 = (-quadratic_equation->b + sqrt_d)/(2*quadratic_equation->a);

            MYASSERT(isfinite(quadratic_equation->x1));
            MYASSERT(isfinite(quadratic_equation->x2));

            quadratic_equation->number_of_roots = TWO_ROOTS;
        }
        else
        {
            quadratic_equation->number_of_roots = ZERO_ROOTS;
        }
    }
}

void printRoots(struct Equation *quadratic_equation)
{
        switch(quadratic_equation->number_of_roots)
    {
        case ZERO_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has no roots\n"));
            break;
        case ONE_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has one root equal to: %lg\n"), quadratic_equation->x1);
            break;
        case TWO_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has two roots: x1 = %lg x2 = %lg\n"), quadratic_equation->x1, quadratic_equation->x2);
            break;
        case INFINITY_ROOTS:
            printf(DRAW_TEXT(GREEN, "The equation has infinitely many solutions\n"));
            break;
        default :
            fprintf(stderr, DRAW_TEXT(RED, "Error, impossible number of roots\n"));
            break;
    }
}

ErrorNumber fileSolveSquare(char **argv)
{
    const int LINE_LENGTH = 128;
    struct Equation square = {};
    char row[LINE_LENGTH] = {};

    FILE *from_file = fopen(*argv, "r");
    if(from_file == NULL)
    {
        return READING_ERROR;
    }
    char *check_reading = fgets(row, LINE_LENGTH, from_file);
    if(check_reading == NULL)
    {
        return READING_ERROR;
    }
    int quantity = 0;

    int check_error = sscanf(row, "%d", &quantity);
    if(check_error == EOF)
    {
        return SCANNING_ERROR;
    }
    for(int i = 0; fgets(row, LINE_LENGTH, from_file) != NULL && i < quantity; i++)
    {
        check_error = sscanf(row, "%lf %lf %lf", &square.a, &square.b, &square.c);
        if(check_error == EOF)
        {
            return SCANNING_ERROR;
        }
        solveSquare(&square);
        printRoots(&square);
    }
    fclose(from_file);

}

ErrorNumber testing(void)
{
    const int MAXIMUM_TESTS = 9, LINE_LENGTH = 128;

    struct Equation square[MAXIMUM_TESTS] = {};
    char row[LINE_LENGTH] = {};

    FILE *from_file = fopen("Test.txt", "r");
    if(from_file == NULL)
    {
        return READING_ERROR;
    }
    char *check_reading = fgets(row, LINE_LENGTH, from_file);
    if(check_reading == NULL)
    {
        return READING_ERROR;
    }
    int quantity = 0;

    int check_error = sscanf(row, "%d", &quantity);
    if(check_error == EOF)
    {
        return SCANNING_ERROR;
    }
    for(int i = 0; fgets(row, LINE_LENGTH, from_file) != NULL && i < quantity; i++)
    {
        check_error = sscanf(row, "%lf %lf %lf %lf %lf %d", &square[i].a,
        &square[i].b, &square[i].c, &square[i].x1, &square[i].x2, &square[i].number_of_roots);
        if(check_error == EOF)
        {
            return SCANNING_ERROR;
        }
    }
    fclose(from_file);

    double set_value_x1 = NAN, set_value_x2 = NAN;
    NumberOfRoots set_value_roots = ZERO_ROOTS;

    for (int nTest = 0; nTest < MAXIMUM_TESTS; nTest++)
    {

            set_value_x1 = square[nTest].x1;
            set_value_x2 = square[nTest].x2;
            set_value_roots = square[nTest].number_of_roots;

            MYASSERT(isfinite(set_value_x1));
            MYASSERT(isfinite(set_value_x2));

            solveSquare(&square[nTest]);

            if (compareDoubles(square[nTest].x1, set_value_x1) == 0 ||
                compareDoubles(square[nTest].x2, set_value_x2) == 0 ||
                square[nTest].number_of_roots != set_value_roots) // TODO: сортировать корни
            {
                fprintf(stderr, DRAW_TEXT(RED, "The test #%d found an error:")
                " a = %lg; b = %lg; c = %lg; x1 = %lg; x2 = %lg; nRoots = %d\n"
                "Required values: x1 = %lg; x2 = %lg; nRoots = %d\n",
                nTest, square[nTest].a, square[nTest].b, square[nTest].c, square[nTest].x1,
                square[nTest].x2, square[nTest].number_of_roots, set_value_x1, set_value_x2, set_value_roots);
                return TEST_ERROR;
            }
    }
}
