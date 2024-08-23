#ifndef FUNCTION_QWADRATKA
#define FUNCTION_QWADRATKA

#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "Color.h"
/**@brief A macro that checks for an error and, if there is one, displays the line,
*function, and file in which the error occurred.
*/
#define MYASSERT(f) if (f == 0) \
fprintf(stderr, DRAW_TEXT(RED, "Error. %d %s %s" \
),__LINE__, __PRETTY_FUNCTION__, __FILE__); if (f == 0) exit(1);
/**@brief It is necessary to denote the number of roots of a quadratic equation,
* INF denotes infinity.
*/
enum nRoot{
    ZER = 0,
    ONE = 1,
    TWO = 2,
    INF = -1
};
/**@brief This is necessary to conveniently indicate an error.
 */
enum error{
    NOT_ERROR = 0,
    ERROR_INPUT = 1
};

/**@brief
*    The type of structures for storing coefficients, roots,
*    and the number of roots of a quadratic equation.
*/
struct equation{
    double aa;
    double bb;
    double cc;
    double xx1;
    double xx2;
    nRoot nnRoots;
};

/**@brief A constant equal to the ASCII code <Ctrl+Z>.*/
const int winEOF = 26;

/**@brief A function for calculating the roots of an equation.*/
void SolveSquare(struct equation *);

/**@brief A function for reading the entered data.
*/
error abcGet(struct equation *);

/**@brief A function to clear the buffer in case of incorrect input.*/
void skipLine(void);

/**@brief A function that determines whether a double number is equal to zero.*/
bool IsZero(double);

/**@brief A function for displaying the result of calculations on the screen.*/
void print_roots(struct equation *);

/**@brief A function that verifies the correctness of the calculations of the
* function SolveSquare.*/
void Tester(void);

/**@brief A function that determines whether two numbers of the double type are equal.*/
bool compare_doubles(double, double);

/**@brief Function to exit the program.*/
void quit_check(char *);
/**@brief A function with a list of errors.*/
void ErrorList(int);

void FileSolveSquare(char**);

void ChoiceMain(int, char**);

#endif // FUNCTION_QWADRATKA
