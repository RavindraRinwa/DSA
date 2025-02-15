#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define x 'X'
#define EQ '='
#define ADD '+'
#define SUB '-'
#define Q 'Q'
char board[5][5] = {
    {x, SUB, 10, EQ, 6},
    {SUB, Q, ADD, Q, SUB},
    {x, ADD, x, EQ, 5},
    {EQ, Q, EQ, Q, EQ},
    {14, SUB, 13, EQ, x}};

bool solve()
{
    bool filled = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == x)
            {
                for (int k = 0; k <= 20; k++)
                {
                    filled = false;
                    board[i][j] = k;
                    if (solve())
                        return true;
                }
                board[i][j] = x;
            }
        }
    }
    if (filled)
    {
        bool solved = true;
        for (int i = 0; i < 5; i += 2)
        {
            int x1 = board[i][0], x2 = board[i][2], x3 = board[i][4], eq = board[i][3], op = board[i][1];
            // printf("%d %c %d %c %d\n", x1, op, x2, eq, x3);
            assert(eq == EQ);
            switch (op)
            {
            case ADD:
                if (x1 + x2 != x3)
                    solved = false;
                break;

            case SUB:
                if (x1 - x2 != x3)
                    solved = false;
            }
        }
        for (int i = 0; i < 5; i += 2)
        {
            int x1 = board[0][i], x2 = board[2][i], x3 = board[4][i], eq = board[3][i], op = board[1][i];
            // printf("%d %c %d %c %d\n", x1, op, x2, eq, x3);
            assert(eq == EQ);
            switch (op)
            {
            case ADD:
                if (x1 + x2 != x3)
                    solved = false;
                break;

            case SUB:
                if (x1 - x2 != x3)
                    solved = false;
            }
        }
        return solved;
    }
    return false;
}

int main()
{
    bool res = solve();
    printf("%d\n", res);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char val = board[i][j];
            printf(val <= 30 ? "%d " : "%c ", val);
        }
        printf("\n");
    }
}