#include "WorkWithDouble.h"

const double ALMOST_ZERO = 1e-6;

bool isZero(double z)
{
    if (fabs(z) < ALMOST_ZERO)
        return true;
    else
        return false;
}

bool compareDoubles(double a, double b)
{
    if (fabs((a-b)) < ALMOST_ZERO)
        return true;
    else
        return false;
}

void sortRoots(double *first_double,double *second_double)
{
    if(*first_double < *second_double)
    {
        double save_value = 0;

        save_value = *first_double;
        *first_double = *second_double;
        *second_double = save_value;
    }
}
