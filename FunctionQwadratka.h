#ifndef FUNCTION_QWADRATKA
#define FUNCTION_QWADRATKA

#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Color.h"

#define MYASSERT(if) if != 0 ? 1 : \
printf(DRAW_TEXT(RED, "Error. The coefficients have an impossible value %d %s %s" \
),__LINE__, __PRETTY_FUNCTION__, __FILE__);
/**@brief Необходимо для обозначения кол-ва корней квадратного уравнения, INF обозначает бесконечность.
*/
enum nRoot{
    ZER = 0,
    ONE = 1,
    TWO = 2,
    INF = -1
};

enum error{
    NOT_ERROR = 0,
    ERROR_INPUT = 1
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
*/
error abcGet(struct equation *);

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

/**@brief Функция для выхода из программы */
void quit_check(char *);
/**@brief Функция со списком ошибок */
void ErrorList(int);

#endif // FUNCTION_QWADRATKA
