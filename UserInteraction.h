#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include<math.h>
#include<string.h>
#include "ErrorNumber.h"

/**@brief Function to exit the program.
*/
void checkQuit(char *);

/**@brief A function for reading the entered data.
*/
ErrorNumber abcGet(struct Equation *);

/**@brief  A function for standard program startup.
*/
ErrorNumber startSolveSquare(void);

#endif // USERINTERACTION_H
