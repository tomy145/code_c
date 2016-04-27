#include <stdio.h>
#include <string.h>

int main(void)
{
    char p[1024];
    int i, j, tmp;
    gets(p);    
    for (i = 0; i < strlen(p); i++) {
        for (j = i + 1; j < strlen(p); j++) {
            if (*(p + i) == *(p + j))
                *(p + j) = '0';
        }
    }
    for (i = 1; i < strlen(p); i++) {
        for (j = 0; j < strlen(p) - i; j++ ) {
            if (*(p + j + 1) < *(p + j)) {
                tmp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = tmp;
            }

        }
    }
    for (i = 0; i < strlen(p); i++) {
        if (*(p + i) >= 'A' && *(p + i) <= 'Z' ||
                *(p + i) >= 'a' && *(p + i) <= 'z')
            printf("%c\t", *(p + i));
    }
    printf("\n");
    return 0;
}
