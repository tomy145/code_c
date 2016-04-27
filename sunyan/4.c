#include <stdio.h>

int main(void)
{
    int i;
    char p[] = "We Are Family!";
    for (i = 0; i < sizeof(p); i++) {
        if (*(p + i) != ' ') {
            printf("%c", *(p + i));
        }
    }
    printf("\n");

    return 0;
}
