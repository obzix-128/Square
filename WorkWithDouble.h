#ifndef WORKWITHDOUBLE_H
#define WORKWITHDOUBLE_H

#include<math.h>
#include<stdbool.h>

/**@brief A function that determines whether a double number is equal to zero.
*/
bool isZero(double);

/**@brief A function that determines whether two numbers of the double type are equal.
*/
bool compareDoubles(double, double);
/**@brief The function sorts the roots so that the first
one is greater than or equal to the second one.
*/
void sortRoots(double*, double*);

#endif // WORKWITHDOUBLE_H
