#include<stdio.h>

int main(void)
{
    int i = 0 , j = 1 ;

    int k = 0;
    for(k = 1; k < 10 ; k++)
    {
        printf("\t%d",k);
    }

    printf("\n");

    for(k = 1;k < 10;k++)
    {
        printf("\t-");
    }
    printf("\n");

    for( i = 1; i < 10;i++)
    {
        for(j = 1; j < 10; j++)
        {
            if (i >= j)
            {
                printf("\t%d",j*i);
            }
        }
        printf("\n");

    }

    return 0 ;
}
