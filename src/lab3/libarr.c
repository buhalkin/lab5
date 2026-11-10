#include <stdio.h>
#include <stdlib.h>
#include "dynlib.h"

#define ARR_SIZE 76

static void fill_array(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
}

static void print_array(const char *title, const int a[], int n)
{
    int i;
    printf("%s\n", title);
    for (i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

static void replace_multiples_of_three(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 3 == 0)
            a[i] = 1;
}

EXPORT void run_array(void)
{
    int a[ARR_SIZE];
    fill_array(a, ARR_SIZE);
    print_array("Array before processing:", a, ARR_SIZE);
    replace_multiples_of_three(a, ARR_SIZE);
    print_array("Array after processing:", a, ARR_SIZE);
}