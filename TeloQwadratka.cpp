#include "FunctionQwadratka.h"

void SolveSquare(struct equation * sq)
{
    if (IsZero(sq->aa))
    {
        if(IsZero(sq->bb))
        {
            sq->nnRoots = (IsZero(sq->cc))? INF : ZER;
        }
        else
        {
            sq->xx1 = -sq->cc/sq->bb;
            sq->nnRoots = ONE;

            MYASSERT(isfinite(sq->xx1));
        }
    }
    else
    {
        double d = sq->bb*sq->bb - 4*sq->aa*sq->cc;

        if (IsZero(d))
        {
            sq->xx1 = sq->xx2 = -sq->bb/(2*sq->aa);
            sq->nnRoots = ONE;

            MYASSERT(isfinite(sq->xx1));
            MYASSERT(isfinite(sq->xx2));
        }
        else if (d > 0)
        {
            double sqrt_d = sqrt (d);

            sq->xx1 = (-sq->bb - sqrt_d)/(2*sq->aa);
            sq->xx2 = (-sq->bb + sqrt_d)/(2*sq->aa);

            MYASSERT(isfinite(sq->xx1));
            MYASSERT(isfinite(sq->xx2));

            sq->nnRoots = TWO;
        }
        else
        {
            sq->nnRoots = ZER;
        }
    }
}
bool IsZero(double z)
{
    if (fabs(z) < 1e-6)
        return true;
    else
        return false;
}
error abcGet(struct equation * sq)
{
    int attempt = 0;

    while (scanf("%lf %lf %lf", &sq->aa, &sq->bb, &sq->cc) != 3)
    {
        skipLine();

        if(attempt >= 3)
            return ERROR_INPUT;

        printf(DRAW_TEXT(RED, "Input error. Enter the values of the coefficients a, b, c using numbers: "));

        attempt++;
    }
    MYASSERT(isfinite(sq->aa));
    MYASSERT(isfinite(sq->bb));
    MYASSERT(isfinite(sq->cc));

    printf(DRAW_TEXT(GREEN, "The values are accepted: a = %lg; b = %lg; c = %lg\n"), sq->aa, sq->bb, sq->cc);

    return NOT_ERROR;
}
void skipLine(void)
{
        int ch = 0;
        while (((ch = getchar()) != '\n') && (ch != winEOF) && (ch != EOF));
}
void print_roots(struct equation * sq)
{
        switch(sq->nnRoots)
    {
        case ZER: printf(DRAW_TEXT(GREEN, "The equation has no roots\n"));
            break;
        case ONE: printf(DRAW_TEXT(GREEN, "The equation has one root equal to:") "%lg\n", sq->xx1);
            break;
        case TWO: printf(DRAW_TEXT(GREEN, "The equation has two roots: x1 = %lg x2 = %lg\n"), sq->xx1, sq->xx2);
            break;
        case INF: printf(DRAW_TEXT(GREEN, "The equation has infinitely many solutions\n"));
            break;
        default : fprintf(stderr, DRAW_TEXT(RED, "Error, impossible number of roots\n"));
            break;
    }
}
void Tester(void)
{
    const int COUNT = 9, LINE_LENGTH = 128;

    struct equation square[COUNT];

    char row[LINE_LENGTH];

    int quantity = 0;

    FILE *fp = fopen("Test.txt", "r");
    if(fp)
    {
        fgets(row, LINE_LENGTH, fp);
        sscanf(row, "%d", &quantity);
        for(int i = 0; fgets(row, LINE_LENGTH, fp) != NULL; i++)
        {
            sscanf(row, "%lf %lf %lf %lf %lf %d", &square[i].aa,
            &square[i].bb, &square[i].cc, &square[i].xx1, &square[i].xx2, &square[i].nnRoots);
        }
        fclose(fp);
    }

    double x1Required = 0, x2Required = 0;
    nRoot nRootsRequired = ZER;

    int nTest;
    for (nTest = 0; nTest < 9; nTest++)
    {

            x1Required = square[nTest].xx1;
            x2Required = square[nTest].xx2;
            nRootsRequired = square[nTest].nnRoots;

            SolveSquare(&square[nTest]);

            if (compare_doubles(square[nTest].xx1, x1Required) == 0 ||
                compare_doubles(square[nTest].xx2, x2Required) == 0 ||
                square[nTest].nnRoots != nRootsRequired)
            {
                fprintf(stderr, DRAW_TEXT(RED, "The test №%d found an error:")
                " a = %lg; b = %lg; c = %lg; x1 = %lg; x2 = %lg; nRoots = %d\n"
                "Required values: x1 = %lg; x2 = %lg; nRoots = %d\n",
                nTest, square[nTest].aa, square[nTest].bb, square[nTest].cc, square[nTest].xx1,
                square[nTest].xx2, square[nTest].nnRoots, x1Required, x2Required, nRootsRequired);
                exit(1);
            }
    }
}

bool compare_doubles(double a, double b)
{
    if (fabs((a-b)) < 1e-6)
        return true;
    else
        return false;
}

void quit_check(char * quit)
{
    printf(DRAW_TEXT(BLUE, "Type [enter] to exit the program or any other character to contiune:\n"));
    skipLine();
    scanf("%c", quit);
}
void ErrorList(int nomber)
{
    switch(nomber)
    {
    case NOT_ERROR:
                break;
    case ERROR_INPUT: fprintf(stderr, DRAW_TEXT(RED, "ERROR: The limit of input attempts has been exceeded\n"));
                exit(1);
                break;
    default: fprintf(stderr, DRAW_TEXT(RED, "Unknown error\n"));
                break;
    }
}
void FileSolveSquare(char **argv)
{
    const int LINE_LENGTH = 128;

    struct equation square = {NAN, NAN, NAN};

    char row[LINE_LENGTH];

    FILE *fp = fopen(*argv, "r");
    if(fp)
    {
        while(fgets(row, LINE_LENGTH, fp) != NULL)
        {
            sscanf(row, "%lf %lf %lf", &square.aa,
            &square.bb, &square.cc);
        }
        fclose(fp);
    }
    if (isfinite(square.aa) ==0 || isfinite(square.bb) == 0 || isfinite(square.cc) == 0)
    {
        printf(DRAW_TEXT(RED,"Error reading the file."));
        exit(1);
    }
    SolveSquare(&square);
    print_roots(&square);
}
void ChoiceMain(int argc, char **argv)
{
    int choice = 0;

    if ((argc < 2) || strlen(argv[1]) > 1 || \
    ((argv[1][0] != 'h') && (argv[1][0] != 's') && (argv[1][0] != 't') && (argv[1][0] != 'f')))
        {
        printf("To work with the program, select a mode, to view the list of modes, "
        "enter [h] after the program name.");
        exit(1);
        }
    for(int count = 1; argc > count ; count++)
    {
        switch (argv[count][0])
        {
        case 'h': printf(DRAW_TEXT(ORANGE, "[h] - Help with the program\n"
                    "[t] - Start the program testing mode\n"
                    "[s] - The standard operating mode of the program\n"
                    "[f] - Use this flag and immediately after it write the name of the "
                    "file from which you want to take the coefficients "
                    "\"f coefficients.txt \"\n"));
            break;
        case 't': Tester();
                printf(DRAW_TEXT(PURPLE, "Test done.\n"));
            break;
        case 's': choice = 1;
            break;
        case 'f': FileSolveSquare(&argv[count+1]);
                count++;
            break;
        default : printf(DRAW_TEXT(RED, "Unknown error."));
            break;
        }
    }
    if (choice == 0)
        exit(1);
}
