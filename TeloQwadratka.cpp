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
void abcGet(struct equation * sq)
{
    while (scanf("%lf %lf %lf", &sq->aa, &sq->bb, &sq->cc) != 3)
    {
        skipLine();
        printf("\033[91mInput error\033[0m. \033[91mEnter the values of the coefficients\033[0m"
        " \033[93ma\033[0m, \033[94mb\033[0m, \033[95mc\033[0m \033[91musing numbers\033[0m:\n");
    }
    assert (isfinite(sq->aa));
    assert (isfinite(sq->bb));
    assert (isfinite(sq->cc));

    printf("\033[92mThe values are accepted\033[0m: \033[93ma\033[0m = %lg;"
    " \033[94mb\033[0m = %lg; \033[95mc\033[0m = %lg\n", sq->aa, sq->bb, sq->cc);
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
        case ZER: printf("\033[92mThe equation has no roots\033[0m");
            break;
        case ONE: printf("\033[92mThe equation has one root equal to\033[0m: %lg\n", sq->xx1);
            break;
        case TWO: printf("\033[92mThe equation has two roots\033[0m: x1 = %lg x2 = %lg\n\033[0m", sq->xx1, sq->xx2);
            break;
        case INF: printf("\033[92mThe equation has infinitely many solutions\033[0m");
            break;
        default : printf("\033[91mError, impossible number of roots\033[0m");
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
                printf("\033[91mThe test\033[0m №%d \033[91mfound an error\033[0m:"
                " a = %lg; b = %lg; c = %lg; x1 = %lg; x2 = %lg; nRoots = %d\n"
                "\033[91mRequired values\033[0m: x1 = %lg; x2 = %lg; nRoots = %d\n",
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
