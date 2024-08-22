#include<TXLib.h>      /*@file Qwadratka.cpp */
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>

/**@brief ���������� ��� ����������� ���-�� ������ ����������� ���������, INF ���������� �������������.

*/
enum nRoot{
    ZER = 0,
    ONE = 1,
    TWO = 2,
    INF = -1
};

/**@brief
    ��� �������� ��� �������� �������������, ������ � ���-�� ������ ����������� ���������.
*/
struct equation{
    double aa;
    double bb;
    double cc;
    double xx1;
    double xx2;
    nRoot nnRoots;
};
/**@brief ��������� ������ ASCII ���� <Ctrl+Z>.*/
const int winEOF = 26;

/**@brief ������� ��� ���������� ������ ���������.*/
void SolveSquare(struct equation *);

/**
* @brief ������� ��� ���������� ������� ������.
* @param [in] struct equation ptr
*/
void abcGet(struct equation *);

/**@brief ������� ��� ������� ������ � ������ ��������� �����.*/
void skipLine(void);

/**@brief �������, ������������ �������� �� ����� ���� double ������ ����.*/
bool IsZero(double);

/**@brief ������� ��� ������ ���������� ���������� �� �����.*/
void print_roots(struct equation *);

/**@brief �������, ����������� ������������ ���������� ������� SolveSquare.*/
void Tester(void);

/**@brief �������, ������������ ����� �� ��� ����� ���� double.*/
bool compare_doubles(double, double);

/**@brief ������� �������.
*@param square ��������� � ������� �������� ������������ ����������� ���������, ��� ����� � �� ���-��.
*@return ����� ������ ���� 0 �������.
*/
int main(void)
{
    struct equation square ={0, 0, 0, 0, 0, ZER};

    printf("������� ������������ ����������� ��������� a, b, c:\n");

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
        printf("������ �����. ������� �������� ������������� a, b, c ��������� �����:\n");
    }
    printf("�������� ������� a = %lg; b = %lg; c = %lg\n", sq->aa, sq->bb, sq->cc);
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
        case ZER: printf("� ��������� ��� ������");
            break;
        case ONE: printf("� ��������� ���� ������ ������: %lg\n", sq->xx1);
            break;
        case TWO: printf("� ��������� ��� �����: �1= %lg �2= %lg\n", sq->xx1, sq->xx2);
            break;
        case INF: printf("� ��������� ���������� ����� �������");
            break;
        default : printf("������, ����������� ���-�� ������");
            break;
    }
}
void Tester(void)
{
    struct equation square[9] =
    {{.aa = 0, .bb = 0,  .cc = 0,  .xx1 = 0,  .xx2 = 0,  .nnRoots = INF},
    {.aa = -4, .bb = 0,  .cc = 0,  .xx1 = 0,  .xx2 = 0,  .nnRoots = ONE},
    {.aa = 0,  .bb = -4, .cc = 0,  .xx1 = 0,  .xx2 = 0,  .nnRoots = ONE},
    {.aa = 0,  .bb = 0,  .cc = -4, .xx1 = 0,  .xx2 = 0,  .nnRoots = ZER},
    {.aa = -4, .bb = 4,  .cc = 0,  .xx1 = 1,  .xx2 = 0,  .nnRoots = TWO},
    {.aa = 0,  .bb = -4, .cc = 4,  .xx1 = 1,  .xx2 = 0,  .nnRoots = ONE},
    {.aa = -4, .bb = 0,  .cc = 4,  .xx1 = 1,  .xx2 = -1, .nnRoots = TWO},
    {.aa = 0,  .bb = 0,  .cc = 0,  .xx1 = 0,  .xx2 = 0,  .nnRoots = INF},
    {.aa = 1,  .bb = 2,  .cc = -3, .xx1 = -3, .xx2 = 1,  .nnRoots = TWO}};
    double x1Required = 0, x2Required = 0;
    nRoot nRootsRequired = ZER;

    int nTest;
    for (nTest = 0; nTest < 9; nTest++)
    {

            x1Required = square[nTest].xx1;
            x2Required = square[nTest].xx2;
            nRootsRequired = square[nTest].nnRoots;

            SolveSquare(&square[nTest]);

            if (compare_doubles(square[nTest].xx1, x1Required) == 0 ||
                compare_doubles(square[nTest].xx2, x2Required) == 0 ||
                square[nTest].nnRoots != nRootsRequired)
            {
                printf("���� �%d ��������� ������: a = %lg; b = %lg; c = %lg;"
                "x1 = %lg; x2 = %lg; nRoots = %d\n"
                "��������� ��������: x1 = %lg; x2 = %lg; nRoots = %d\n",
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
