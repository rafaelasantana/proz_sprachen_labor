#include <stdio.h>

int main()
{
    int i = 4;
    printf("%d %d %d %p\n", 1, i, '4', &i);
    return 0;
}