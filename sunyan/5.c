#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, counter = 0;
    char p[1024];
    gets(p);
    for (i = 0; i < strlen(p); i++) {
        if ( *(p + i) != *(p + strlen(p) - i -1)) {
            printf("N\n");
            counter++;
            break;
        }
    }
    if ( counter == 0)
        printf("Y\n");
}
