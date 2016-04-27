#include <stdio.h>

int main(void)
{
    int ch[26], i, j, tmp;
    for (i = 0; i < 26; i++) {
        *(ch + i) = rand() % 26 + 97;
    }
    for (i = 1; i < 26; i++) {
        for (j = 0; j < 26 - i; j++ ) {
            if (*(ch + j + 1) < *(ch + j)) {
                tmp = *(ch + j);
                *(ch + j) = *(ch + j + 1);
                *(ch + j + 1) = tmp;
            }

        }
    }
    for (i = 0; i < 26; i++) {
        printf("%c", *(ch + i));
    }
    printf("\n");
    return 0;
}
