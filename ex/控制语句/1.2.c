#include<stdio.h>

int main(void)
{
    int i = 0 , j = 0 , k = 0;
    int count = 0;

    for( i =0; i <= 16;i++)
    {
        for(j = 0; j <= 25; j++)
        {
            for (k = 0; k <= 30; k++)
            {
                if ((50 == 3 * i + 2 * j + k) && ((k + j + i) <= 30))
                {
                    printf("k = %d , j = %d , i = %d\n",k,j,i);
                    count +=1;
                }
            }
        }
    }

    printf("总共有 -- %d 种 组合\n",count);

    return 0 ;
}
