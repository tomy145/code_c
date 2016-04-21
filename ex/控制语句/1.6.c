 
 #include<stdio.h>

int main(void)
{

    int i = 0 , j = 0 , m = 0;
    int count = 0;

    for (i = 1; i<= 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            for (m = 1; m <= 4; m++)
            {

                if( (i != j && i != m && j != m ))
                {
                    printf("i = %d , j = %d , m = %d \n",i , j , m);
                    ++count;
                }
            }
        }
    }

    printf("总共有%d种组合\n",count);

    return 0;
}
 