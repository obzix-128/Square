#include<TXLib.h>      /*@file Qwadratka.cpp */
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>

/**@brief Необходимо для обозначения кол-ва корней квадратного уравнения, INF обозначает бесконечность.

*/
enum nRoot{
    ZER = 0,
    ONE = 1,
    TWO = 2,
    INF = -1
};

/**@brief
    Тип структур для хранения коэффициентов, корней и кол-ва корней квадратного уравнения.
*/
struct equation{
    double aa;
    double bb;
    double cc;
    double xx1;
    double xx2;
    nRoot nnRoots;
};
/**@brief Константа равная ASCII коду <Ctrl+Z>.*/
const int winEOF = 26;

/**@brief Функция для вычисления корней уравнения.*/
void SolveSquare(struct equation *);

/**
* @brief Функция для считывания введёных данных.
* @param [in] struct equation ptr
*/
void abcGet(struct equation *);

/**@brief Функция для очистки буфера в случае неверного ввода.*/
void skipLine(void);

/**@brief Функция, определяющая является ли число типа double равным нулю.*/
bool IsZero(double);

/**@brief Функция для вывода результата вычислений на экран.*/
void print_roots(struct equation *);

/**@brief Функция, проверяющая правильность вычислений функции SolveSquare.*/
void Tester(void);

/**@brief Функция, определяющая равны ли два числа типа double.*/
bool compare_doubles(double, double);

/**@brief Главная функция.
*@param square Структура в которой хранятся коэффициенты квадратного уравнения, его корни и их кол-во.
*@return Прата сказал надо 0 вернуть.
*/
int main(void)
{
    struct equation square ={0, 0, 0, 0, 0, ZER};

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
                printf("Тест №%d обнаружил ошибку: a = %lg; b = %lg; c = %lg;"
                "x1 = %lg; x2 = %lg; nRoots = %d\n"
                "Требуемые значения: x1 = %lg; x2 = %lg; nRoots = %d\n",
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
