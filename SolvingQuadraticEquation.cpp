#include "SolvingQuadraticEquation.h"
#include "WorkWithDouble.h"

static const int LINE_LENGTH = 128;

void solveSquare(Equation *quadratic_equation)
{
    if(isZero(quadratic_equation->a))
    {
        solvingLinearEquation(quadratic_equation);
    }
    else
    {
        double d = quadratic_equation->b * quadratic_equation->b - 4 *
            quadratic_equation->a * quadratic_equation->c;

        if (isZero(d))
        {
            quadratic_equation->x1 = quadratic_equation->x2 =
                    -quadratic_equation->b / (2 * quadratic_equation->a);
            quadratic_equation->number_of_roots = ONE_ROOTS;

            MYASSERT(isfinite(quadratic_equation->x1));
            MYASSERT(isfinite(quadratic_equation->x2));
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt (d);

            quadratic_equation->x1 = (-quadratic_equation->b - sqrt_d) /
                                     (2 * quadratic_equation->a);
            quadratic_equation->x2 = (-quadratic_equation->b + sqrt_d) /
                                     (2 * quadratic_equation->a);

            MYASSERT(isfinite(quadratic_equation->x1));
            MYASSERT(isfinite(quadratic_equation->x2));

            quadratic_equation->number_of_roots = TWO_ROOTS;
        }
        else
        {
            quadratic_equation->number_of_roots = ZERO_ROOTS;
        }
    }
    if(isZero(quadratic_equation->x1))
        quadratic_equation->x1 = 0;
    if(isZero(quadratic_equation->x2))
        quadratic_equation->x2 = 0;
}

void solvingLinearEquation(Equation *equation)
{
    if(isZero(equation->b))
    {
        equation->number_of_roots =
        (isZero(equation->c))? INFINITY_ROOTS : ZERO_ROOTS;
    }
    else
    {
        equation->x1 = -equation->c / equation->b;
        equation->number_of_roots = ONE_ROOTS;

        MYASSERT(isfinite(equation->x1));
    }
}

ErrorNumber fileSolveSquare(const char *argv)
{
    const int MAX_EQUATIONS = 10;

    struct Equation square = {};

    char row[LINE_LENGTH] = {};

    FILE *open_file = fopen(argv, "r");
    if(open_file == NULL)
    {
        return READING_ERROR;
    }

    char *check_reading = fgets(row, LINE_LENGTH, open_file);

    if(check_reading == NULL)
    {
        fclose(open_file);
        return READING_ERROR;
    }

    int quantity = 0;

    int check = sscanf(row, "%d", &quantity);
    if(check == EOF)
    {
        fclose(open_file);
        return SCANNING_ERROR;
    }

    printf(DRAW_TEXT(ORANGE,"Solving equations from a file \"%s\"\n"), argv);

    for(int i = 0; fgets(row, LINE_LENGTH, open_file) != NULL && i < quantity &&
                                                            i < MAX_EQUATIONS; i++)
    {
        check = sscanf(row, "%lf %lf %lf", &square.a, &square.b, &square.c);
        if(check == EOF)
        {
            fclose(open_file);
            return SCANNING_ERROR;
        }
        solveSquare(&square);
        printRoots(&square);
    }
    fclose(open_file);
    return NOT_ERROR;
}

ErrorNumber testingSolveSquare(void)
{
    const int MAXIMUM_TESTS = 25;

    struct Equation square[MAXIMUM_TESTS] = {};

    int quantity_tests = 0;

    ErrorNumber check_error = parseFile(square, &quantity_tests);

    if (check_error != NOT_ERROR)
        return check_error;

    double set_value_x1 = NAN, set_value_x2 = NAN;
    NumberOfRoots set_value_roots = ZERO_ROOTS;

    for (int nTest = 0; nTest < MAXIMUM_TESTS && nTest < quantity_tests; nTest++)
    {
        set_value_x1 = square[nTest].x1;
        set_value_x2 = square[nTest].x2;
        set_value_roots = square[nTest].number_of_roots;

        MYASSERT(isfinite(set_value_x1));
        MYASSERT(isfinite(set_value_x2));

        solveSquare(&square[nTest]);

        sortRoots(&set_value_x1, &set_value_x2);
        sortRoots(&square[nTest].x1, &square[nTest].x2);

        if (compareDoubles(square[nTest].x1, set_value_x1) == 0 ||
            compareDoubles(square[nTest].x2, set_value_x2) == 0 ||
            square[nTest].number_of_roots != set_value_roots)
        {
            fprintf(stderr, DRAW_TEXT(RED, "The test #%d found an error:")
            " a = %lg; b = %lg; c = %lg; x1 = %lg; x2 = %lg; nRoots = %d\n"
            "Required values: x1 = %lg; x2 = %lg; nRoots = %d\n",
            nTest + 1, square[nTest].a, square[nTest].b, square[nTest].c, square[nTest].x1,
            square[nTest].x2, square[nTest].number_of_roots, set_value_x1, set_value_x2, set_value_roots);
            return TEST_ERROR;
        }
    }
    return NOT_ERROR;
}

ErrorNumber parseFile(Equation *square, int *quantity_tests)
{
    char row[LINE_LENGTH] = {};

    FILE *open_file = fopen("Test.txt", "r");
    if(open_file == NULL)
    {
        return READING_ERROR;
    }

    char *check_reading = fgets(row, LINE_LENGTH, open_file);
    if(check_reading == NULL)
    {
        return READING_ERROR;
    }

    int check = sscanf(row, "%d", quantity_tests);
    if(check == EOF)
    {
        return SCANNING_ERROR;
    }

    for(int i = 0; fgets(row, LINE_LENGTH, open_file) != NULL && i < *quantity_tests; i++)
    {
        check = sscanf(row, "%lf %lf %lf %lf %lf %d", &square[i].a, &square[i].b,
            &square[i].c, &square[i].x1, &square[i].x2, (int*)&square[i].number_of_roots);
        if(check == EOF)
        {
            return SCANNING_ERROR;
        }
    }
    fclose(open_file);
    return NOT_ERROR;
}
