#include "FunctionQwadratka.h"

void SolveSquare(struct equation * sq)
{
    if (IsZero(sq->aa))
    {
        if(IsZero(sq->bb))
        {
            sq->nnRoots = (IsZero(sq->cc))? INF : ZER;
        }
        else
        {
            sq->xx1 = -sq->cc/sq->bb;
            sq->nnRoots = ONE;
        }
    }
    else
    {
        double d = sq->bb*sq->bb - 4*sq->aa*sq->cc;

        if (IsZero(d))
        {
            sq->xx1 = sq->xx2 = -sq->bb/(2*sq->aa);
            sq->nnRoots = ONE;
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt (d);

            sq->xx1 = (-sq->bb - sqrt_d)/(2*sq->aa);
            sq->xx2 = (-sq->bb + sqrt_d)/(2*sq->aa);

            sq->nnRoots = TWO;
        }
        else
        {
            sq->nnRoots = ZER;
        }
    }
}
bool IsZero(double z)
{
    if (fabs(z) < 1e-6)
        return true;
    else
        return false;
}
error abcGet(struct equation * sq)
{
    int attempt = 0;

    while (scanf("%lf %lf %lf", &sq->aa, &sq->bb, &sq->cc) != 3)
    {
        skipLine();

        if(attempt >= 3)
            return ERROR_INPUT;

        printf(DRAW_TEXT(RED, "Input error. Enter the values of the coefficients a, b, c using numbers: "));

        attempt++;
    }
    MYASSERT(isfinite(sq->aa));
    MYASSERT(isfinite(sq->bb));
    MYASSERT(isfinite(sq->cc));

    printf(DRAW_TEXT(GREEN, "The values are accepted: a = %lg; b = %lg; c = %lg\n"), sq->aa, sq->bb, sq->cc);

    return NOT_ERROR;
}
void skipLine(void)
{
        int ch = 0;
        while (((ch = getchar()) != '\n') && (ch != winEOF) && (ch != EOF));
}
void print_roots(struct equation * sq)
{
        switch(sq->nnRoots)
    {
        case ZER: printf(DRAW_TEXT(GREEN, "The equation has no roots\n"));
            break;
        case ONE: printf(DRAW_TEXT(GREEN, "The equation has one root equal to:") "%lg\n", sq->xx1);
            break;
        case TWO: printf(DRAW_TEXT(GREEN, "The equation has two roots:") "x1 = %lg x2 = %lg\n", sq->xx1, sq->xx2);
            break;
        case INF: printf(DRAW_TEXT(GREEN, "The equation has infinitely many solutions\n"));
            break;
        default : printf(DRAW_TEXT(RED, "Error, impossible number of roots\n"));
            break;
    }
}
void Tester(void)
{
    const int COUNT = 10;

    struct equation square[COUNT] =
    {{.aa = 0,   .bb = 0,     .cc = 0,   .xx1 = 0,         .xx2 = 0,         .nnRoots = INF},
    {.aa = -4,   .bb = 0,     .cc = 0,   .xx1 = 0,         .xx2 = 0,         .nnRoots = ONE},
    {.aa = 0,    .bb = -4,    .cc = 0,   .xx1 = 0,         .xx2 = 0,         .nnRoots = ONE},
    {.aa = 0,    .bb = 0,     .cc = -4,  .xx1 = 0,         .xx2 = 0,         .nnRoots = ZER},
    {.aa = -4,   .bb = 4,     .cc = 0,   .xx1 = 1,         .xx2 = 0,         .nnRoots = TWO},
    {.aa = 0,    .bb = -4,    .cc = 4,   .xx1 = 1,         .xx2 = 0,         .nnRoots = ONE},
    {.aa = -4,   .bb = 0,     .cc = 4,   .xx1 = 1,         .xx2 = -1,        .nnRoots = TWO},
    {.aa = 0,    .bb = 0,     .cc = 0,   .xx1 = 0,         .xx2 = 0,         .nnRoots = INF},
    {.aa = 1,    .bb = 2,     .cc = -3,  .xx1 = -3,        .xx2 = 1,         .nnRoots = TWO},
    {.aa = 1.5,  .bb = 2.56,  .cc = -34, .xx1 = -5.690155, .xx2 = 3.983488,  .nnRoots = TWO}};
    double x1Required = 0, x2Required = 0;
    nRoot nRootsRequired = ZER;

    int nTest;
    for (nTest = 0; nTest < COUNT; nTest++)
    {

            x1Required = square[nTest].xx1;
            x2Required = square[nTest].xx2;
            nRootsRequired = square[nTest].nnRoots;

            SolveSquare(&square[nTest]);

            if (compare_doubles(square[nTest].xx1, x1Required) == 0 ||
                compare_doubles(square[nTest].xx2, x2Required) == 0 ||
                square[nTest].nnRoots != nRootsRequired)
            {
                printf(DRAW_TEXT(RED, "The test №%d found an error:")
                " a = %lg; b = %lg; c = %lg; x1 = %lg; x2 = %lg; nRoots = %d\n"
                "Required values: x1 = %lg; x2 = %lg; nRoots = %d\n",
                nTest, square[nTest].aa, square[nTest].bb, square[nTest].cc, square[nTest].xx1,
                square[nTest].xx2, square[nTest].nnRoots, x1Required, x2Required, nRootsRequired);
                break;
            }
    }
}

bool compare_doubles(double a, double b)
{
    if (fabs((a-b)) < 1e-6)
        return true;
    else
        return false;
}

void quit_check(char * quit)
{
    printf(DRAW_TEXT(BLUE, "Type [enter] to exit the program or any other character to contiune:\n"));
    skipLine();
    scanf("%c", quit);
}
void ErrorList(int nomber)
{
    switch(nomber)
    {
    case NOT_ERROR: printf(DRAW_TEXT(ORANGE, "No errors were found\n"));
                break;
    case ERROR_INPUT: printf(DRAW_TEXT(RED, "ERROR: The limit of input attempts has been exceeded\n"));
                exit(1);
                break;
    default: printf(DRAW_TEXT(RED, "Unknown error\n"));
                break;
    }
}
