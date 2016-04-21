#include <stdio.h>

int main(void)
{

        int i = 0;

        int j = 0;

        for (i = 0; i < 4; i++)
    {
                for (j = 0; j <= 2 * i - 1; j++)
        {
                        printf("*");
                    
        }
                printf("*\n");
            
    }

        for (i = 1; i <= 3; i++)
    {
                for (j = 0; j <= 3 - (i - 1) * 2; j++)
        {
                        printf("*");
                    
        }
                printf("*\n");
            
    }



        return 0 ;

}



