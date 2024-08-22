#ifndef FUNCTION_QWADRATKA
#define FUNCTION_QWADRATKA

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

#endif // FUNCTION_QWADRATKA
