#include <stdio.h>
#include <string.h>

int main(void)
{

    char p[1024] = {0};
    int q[1024] = {0};
    int i, j = 0, max = 0;
    gets(p);    
    for (i = 0; i < strlen(p); i++) {
        if (*(p + i) == ' ') {
            *(q + j) = i;
            j++;
        }
    }
    *(q + j) = strlen(p) - 1;
    for (i = 1; i < j + 1; i++) {
        *(q + i) = *(q + i) - *(q + i - 1);
    }
    for (i = 0; i < j + 1; i++ ) {
        if (max < *(q + i)) 
            max = *(q + i);
    }
    printf("%d\n", max);
    return 0;
}
