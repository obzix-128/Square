#include<TXLib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>

enum nRoot{
    ZER = 0,
    ONE = 1,
    TWO = 2, // TODO:CAPS
    INF = -1
};

struct equation{
    double aa;
    double bb;
    double cc;
    double xx1;
    double xx2;
    nRoot nnRoots;
};

const int winEOF = 26;

void SolveSquare(struct equation *);
void abcGet(struct equation *);
void skipLine(void);
bool IsZero(double);
void print_roots(struct equation *);
void Tester(void);
bool compare_doubles(double, double);

int main(void)
{
    struct equation square ={
        0,
        0,
        0,
        0,
        0,
        ZER,
    };

    printf("Введите коэффициенты квадратного уравнения a, b, c:\n");

    abcGet(&square);

    SolveSquare(&square);

    Tester();

    print_roots(&square);

    return 0;
}

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
        printf("Ошибка ввода. Введите значения коэффициентов a, b, c используя цифры:\n");
    }
    printf("Значения приянты a = %lg; b = %lg; c = %lg\n", sq->aa, sq->bb, sq->cc);
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
        case ZER: printf("У уравнения нет корней");
            break;
        case ONE: printf("У уравнения один корень равный: %lg\n", sq->xx1);
            break;
        case TWO: printf("У уравнения два корня: х1= %lg х2= %lg\n", sq->xx1, sq->xx2);
            break;
        case INF: printf("У уравнения бесконечно много решений");
            break;
        default : printf("Ошибка, невозможное кол-во корней");
            break;
    }
}
void Tester(void)
{
    struct equation square[8];
    square[0].aa = 0;
    square[0].bb = 0;
    square[0].cc = 0;
    square[0].xx1 = 0;
    square[0].xx2 = 0;
    square[0].nnRoots = INF;
    square[1].aa = -4;
    square[1].bb = 0;
    square[1].cc = 0;
    square[1].xx1 = 0;
    square[1].xx2 = 0;
    square[1].nnRoots = ONE;
    square[2].aa = 0;
    square[2].bb = -4;
    square[2].cc = 0;
    square[2].xx1 = 0;
    square[2].xx2 = 0;
    square[2].nnRoots = ONE;
    square[3].aa = 0;
    square[3].bb = 0;
    square[3].cc = -4;
    square[3].xx1 = 0;
    square[3].xx2 = 0;
    square[3].nnRoots = ZER;
    square[4].aa = -4;
    square[4].bb = 4;
    square[4].cc = 0;
    square[4].xx1 = 1;
    square[4].xx2 = 0;
    square[4].nnRoots = TWO;
    square[5].aa = 0;
    square[5].bb = -4;
    square[5].cc = 4;
    square[5].xx1 = 1;
    square[5].xx2 = 0;
    square[5].nnRoots = ONE;
    square[6].aa = -4;
    square[6].bb = 0;
    square[6].cc = 4;
    square[6].xx1 = 1;
    square[6].xx2 = -1;
    square[6].nnRoots = TWO;
    square[7].aa = 1;
    square[7].bb = 2;
    square[7].cc = -3;
    square[7].xx1 = -3;
    square[7].xx2 = 1;
    square[7].nnRoots = TWO;

    double x1Required = 0, x2Required = 0;
    nRoot nRootsRequired = ZER;

    int nTest;
    for (nTest = 0; nTest < 8; nTest++)
    {

            x1Required = square[nTest].xx1;
            x2Required = square[nTest].xx2;
            nRootsRequired = square[nTest].nnRoots;

            SolveSquare(&square[nTest]);

            if (compare_doubles(square[nTest].xx1, x1Required) == 0 ||
                compare_doubles(square[nTest].xx2, x2Required) == 0 ||
                square[nTest].nnRoots != nRootsRequired)
            {
                printf("Тест №%d обнаружил ошибку: a = %lg; b = %lg; c = %lg;"
                "x1 = %lg; x2 = %lg; nRoots = %d\n"
                "Требуемые значения: x1 = %lg; x2 = %lg; nRoots = %d\n",
                nTest, square[nTest].aa, square[nTest].bb, square[nTest].cc, square[nTest].xx1,
                square[nTest].xx2, square[nTest].nnRoots, x1Required, x2Required, nRootsRequired);
                break;
            }
    }
}

bool compare_doubles(double a, double b)// TODO: compare_doubles (double a, double b)
{
    if (fabs((a-b)) < 1e-6)
        return true;
    else
        return false;
}
