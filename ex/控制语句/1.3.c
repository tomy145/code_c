
#include<stdio.h>

int main(void)
{
    int i = 0;
    int num = 0;
    for( i =0; i <= 10;i++)
    {
        printf("请输入一个数字\n");
        scanf("%d",&num);
        if (num > 0)
        {
            /* code */
            printf("您输入的数字是:%d\n", num);
        }
        else
        {
            printf("Program is over!\n");
            break;
        }
    }
    return 0 ;
}
