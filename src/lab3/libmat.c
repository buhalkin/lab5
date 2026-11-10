#include <stdio.h>
#include <stdlib.h>
#include "dynlib.h"

#define ROWS 5
#define COLS 6

static void fill_matrix(int m[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            m[i][j] = rand() % 101 - 50;
}

static void print_matrix(const char *title, int m[ROWS][COLS])
{
    int i, j;
    printf("%s\n", title);
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
}

static void replace_multiples_of_three(int m[ROWS][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            if (m[i][j] % 3 == 0)
                m[i][j] = 1;
}

EXPORT void run_matrix(void)
{
    int m[ROWS][COLS];
    fill_matrix(m);
    print_matrix("Matrix before processing:", m);
    replace_multiples_of_three(m);
    print_matrix("Matrix after processing:", m);
}