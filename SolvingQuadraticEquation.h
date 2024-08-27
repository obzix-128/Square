#ifndef SOLVINQQUADRATICEQUATION_H
#define SOLVINGQUADRATICEQUATION_H

#include<stdio.h>
#include<stdlib.h>
#include "Color.h"
#include "ErrorNumber.h"

/**@brief A macro that checks for an error and, if there is one, displays the line,
*function, and file in which the error occurred.
*/
#define MYASSERT(f) if (f == 0) do \
                                { \
                                fprintf(stderr, DRAW_TEXT(RED, "Error. %d %s %s" \
                                ),__LINE__, __PRETTY_FUNCTION__, __FILE__); abort(); \
                                } while(0);
/**@brief It is necessary to denote the number of roots of a quadratic equation,
* INF denotes infinity.
*/
enum NumberOfRoots{
    ZERO_ROOTS     =  0,
    ONE_ROOTS      =  1,
    TWO_ROOTS      =  2,
    INFINITY_ROOTS = -1
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

/**@brief A function for calculating the roots of an Equation.
*/
void solveSquare(Equation *);

/**@brief A function for displaying the result of calculations on the screen.
*/
void printRoots(Equation *);

/**@brief A function that verifies the correctness of the calculations of the
* function solveSquare.
*/
ErrorNumber testingSolveSquare(void);
/**@brief The function takes the coefficients
*from the specified file and solves the quadratic equation using them.
*/
ErrorNumber fileSolveSquare(const char*);

/**@brief A function with a list of errors.
*/
void errorList(ErrorNumber);

/**@brief A function for reading and writing values from a file "Test.txt ",
*for the testingSolveSquare function
*/
ErrorNumber parseFile(Equation *square, int*);

/**@brief A function for solving linear man
*/
void solvingLinearEquation(Equation *);

#endif // SOLVINGQUADRATICEQUATION_H
