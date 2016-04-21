/*************************************************************************
	> File Name: mu.c
	> Author: 
	> Mail: 
	> Created Time: 三  4/20 10:57:53 2016
 ************************************************************************/

#include<stdio.h>

int main( void )
{
    int i = 1, j = 1;
    for(i = 1; i <= 9; i++)
    {
        for(j = 1;j <= 9; j++)
        {
            if(i >= j)
            {
                printf("%d x %d = %d\t",i,j,i*j);
            }
        }
        printf("\n");
    }

    return 0 ;
}
