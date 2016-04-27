//
//  main.c
//  1
//
//  Created by Mac on 16/4/26.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>





int main(int argc, const char * argv[])
{



    printf("请输入一组字符串:\n");

    char *str = (char *)calloc(INT_MAX, sizeof(char));
    gets(str);

    char *capitalCh = (char*)calloc(26, sizeof(char));
    char *lowercaseCH = (char*)calloc(26, sizeof(char));

    int i = 0;
    for (i = 0; i< 26; i++)
    {
        capitalCh[i] = 65 + i;
        lowercaseCH[i] = 97 + i;
    }

    int j = 0;
    int m = 0, len = (int)strlen(str);
    for (j = 0; j < 26; j++)
    {
        int isExist = 0,isLowerCH = 0;
        for (m = 0; m < len; m++)
        {
            if (capitalCh[j] == str[m])
            {
                isExist+=1;
            }

            if (lowercaseCH[j] == str[m])
            {
                isLowerCH +=1;
            }
        }

        if (isExist>=1 && isExist>= 1)
        {
            printf("-%c-%c-",capitalCh[j],lowercaseCH[j]);
        }
    }


    printf("\n");



    free(str);
    free(capitalCh);
    free(lowercaseCH);





       return 0;
}
