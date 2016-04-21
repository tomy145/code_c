#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    
     double num = 0;
    int i = 0;
    printf("请输入一个小数:\n");
    scanf("%lf",&num);
    if (num > 0)
    {
        i = (int)(num + 0.5);
    }
    else
    {
        int temp = (int)fabs(num);
        int x = -1 * (num + temp + (- 0.5));
        i = -1 * (temp + x);
        
    }

    printf("i = %d\n",i);


    return 0;
}