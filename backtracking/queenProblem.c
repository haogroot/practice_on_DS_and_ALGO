#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Queen's location. Index represents row
 * and value represents column.
 */
int queen[8]={0};
static int index = 1;

void printQueen()
{
    printf("Queen in checkerboard #%d:\n", index++);
    for (int i=0; i<8; i++)
        printf ("%d ", queen[i]);
    printf ("\n");
}

/**
 * Check if queen is put at (row, column) is okay.
 * Only need to check the left side of the row because
 * queen is putting from left to right.
 * 1. check (0:row-1, column)
 * 2. check two diagonal line
 */
bool checkQueen (int row, int column)
{
    int upDiagonal = column-1;
    int downDiagoanl = column+1;
    for (int i=row-1; i>=0; i--)
    {
        if (queen[i] == column)
            return false;
        if (upDiagonal >= 0)
        {
            if (queen[i] == upDiagonal)
                return false;
        }
        if (downDiagoanl <8)
        {
            if (queen[i] == downDiagoanl)
                return false;
        }

        upDiagonal--;
        downDiagoanl++;
    }
    return true;
}

void decideQueen(int row)
{
    if (row == 8)
    {
        printQueen();
        return;
    }
    /* Check if putting queen in column is ok */
    for (int i=0; i<8; i++)
    {
        if (checkQueen(row, i))
        {
            queen[row] = i;
            decideQueen (row+1);
        }
    }
}

int main()
{
    decideQueen (0);
    return 0;

}
