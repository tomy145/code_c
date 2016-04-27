#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int p[10], i;
    for (i = 0; i < 10; i++) {
        *(p + i) = rand();
    }
    printf("\n"); 
    for (i = 1; i <= 10; i++) {
        printf("p[%d] = %d\n", 10 - i, *(p + 10 - i));
    }
    printf("\n"); 

    return 0;
}
