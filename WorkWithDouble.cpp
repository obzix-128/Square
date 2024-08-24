#include "WorkWithDouble.h"

bool isZero(double z)
{
    if (fabs(z) < 1e-6)
        return true;
    else
        return false;
}

bool compareDoubles(double a, double b)
{
    if (fabs((a-b)) < 1e-6)
        return true;
    else
        return false;
}
