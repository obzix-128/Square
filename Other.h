#ifndef OTHER_H
#define OTHER_H

#include<stdio.h>
#include<stdlib.h>
#include "Color.h"

/**@brief A macro that checks for an error and, if there is one, displays the line,
*function, and file in which the error occurred.
*/
#define MYASSERT(f) if (f == 0) \
fprintf(stderr, DRAW_TEXT(RED, "Error. %d %s %s" \
),__LINE__, __PRETTY_FUNCTION__, __FILE__);// TODO: аппорт?

/**@brief It is necessary to denote the number of roots of a quadratic equation,
* INF denotes infinity.
*/
enum NumberOfRoots{
    ZERO_ROOTS = 0,
    ONE_ROOTS = 1,
    TWO_ROOTS = 2,
    INFINITY_ROOTS = -1
};

/**@brief This is necessary to conveniently indicate an error.
 */
enum ErrorNumber{
    NOT_ERROR = 0,
    ERROR_INPUT = 1,
    READING_ERROR = 2,
    SCANNING_ERROR = 3,
    TEST_ERROR = 4
};

/**@brief
*    The type of structures for storing coefficients, roots,
*    and the number of roots of a quadratic equation.
*/
struct Equation{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    NumberOfRoots number_of_roots;
};

/**@brief A function for calculating the roots of an Equation.*/
void solveSquare(struct Equation *);

/**@brief A function for displaying the result of calculations on the screen.*/
void printRoots(struct Equation *);

/**@brief A function that verifies the correctness of the calculations of the
* function solveSquare.*/
ErrorNumber testing(void);

ErrorNumber fileSolveSquare(char**);

/**@brief A function with a list of errors.*/
void errorList(ErrorNumber);

#endif // OTHER_H
