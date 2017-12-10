#include <stdio.h>
#define TRUE    1
#define FALSE   0

int buffer[100] ;

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i])
    }
    printf("\n");
}

bool IsValid(int lastIndex, int value)
{
    for (int i = 0; i < lastIndex; i++)
    {
        if (buffer[i] >= value)
            return FALSE;
    }
    return TRUE;
}

void Select(int t, int n, int m)
{
    if (t == m)
        PrintArray(buffer, m);
    else
    {
        for (int i = 1; i <= n; i++)
        {
            buffer[t] = i;
            if (IsValid(t, i))
                Select(t + 1, n, m);
        }
    }
}

