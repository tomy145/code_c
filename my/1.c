#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define kArraySize 10

int main(int argc, const char * argv[])
{

    unsigned int  ts = (unsigned int)time(NULL);
    srand(ts);

    int j = 0;
    int *p = (int *)calloc(kArraySize, sizeof(int));

    for (j = 0; j < kArraySize; j++)
    {
        p[j] = rand()%10;
        printf("正序 --- j -- %d, --- *p -- %d\n",j,p[j]);
        p++;
    }

    int i = 0;

    for (i = 9; i >= 0; i--)
    {
        printf("逆序 --- i -- %d, --- *p -- %d\n",i,p[i-1]);
        p--;
    }


    printf("ts --- %u\n",ts);

    free(p);


    return 0;
}
