#include<stdio.h>

int main(void)
{

    int num = 0;
    printf("请输入一个整数: \n");
    scanf("%d", &num);

    int index = 0;
    if ((num % 2) == 0)
    {
        index = (num / 2) - 1;
    }
    else
    {
        index = num / 2;
    }

    int i = 0;

    for (i = 1; i <= index; i++)
    {
        printf("%d 拆分的组合为: %d --- %d\n",num,i , num - i);
    }

    return 0 ;
}

