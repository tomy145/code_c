/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 六  4/16 14:42:04 2016
 ************************************************************************/

#include<stdio.h>

int main(void)
{
    /*
    double r = 0.00,  area = 0.00;
    printf("请输入圆的半径 ... \n");
    scanf("%lf",&r);
    area = r * r * 3.141592654;
    printf("r = %lf,area = %lf \n",r,area);

    int i = 19;
    char c = 'S';
    
    int *p = &i;
    char *cp = &c;

    printf("*p size = %ld\n , *cp size = %ld \n",sizeof(p),sizeof(cp));

    */
    /*
    char a[] = {0};

    for (char i = 0;i < 100; i ++)
    {
        a[i] = i;
        printf("i = %d\n",i);
    }
    */
    /*
    unsigned num = 0;
    char ch = 0, ch1 = 0, ch2 = 0, ch3 = 0;
    printf("请输入一个四位的正整数:\n");
    scanf("%u",&num);
    ch = num % 10 + '0';
    ch1 = num / 10 % 10 + '0';
    ch2 = num / 100 % 10 + '0';
    ch3 = num / 1000 + '0';

    printf(" %c - %c - %c - %c \n",ch,ch1,ch2,ch3);
    */

    /*
    int i = 6 , a , b ;
    printf("%d\n",++i);
    printf("%d\n",i++);
    a = --i; 
    printf("%d\n",a);
    b = i--;
    printf("%d\n",b);
    printf("%d\n",-i++);
    printf("i = %d\n",i);
    */
    char ch = '0';
    ch = getchar();
    
    if(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    {
        printf("%c is a letter.",c);
    }
    else if((c >= '0') && (c <= '9'))
    {
        
    }

    return 0;
}

