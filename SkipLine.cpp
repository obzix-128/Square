#include "SkipLine.h"
#include "SolvingQuadraticEquation.h"

/**@brief A constant equal to the ASCII code <Ctrl+Z>.*/
const int winEOF = 26;

void skipLine(void)
{
        int ch = 0;
        while (((ch = getchar()) != '\n') && (ch != winEOF) && (ch != EOF));
}
