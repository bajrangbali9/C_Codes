#include <stdio.h>
#include <stdlib.h>

int binary_search(int *s, int key, int low, int high)
{
    int mid;
    if (low > high)
    {
        return (-1);
    }
    mid = (low + high) / 2;
    if (s[mid] == key)
    {
        return (mid);
    }
    if (s[mid] > key)
    {
        return (binary_search(s, key, low, mid - 1));
    }
    else
    {
        return (binary_search(s, key, mid + 1, high));
    }
}
