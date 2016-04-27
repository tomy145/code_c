/*************************************************************************
	> File Name: feipolaqi.c
	> Author: 
	> Mail: 
	> Created Time: 日  4/24 14:53:17 2016
 ************************************************************************/

#include<stdio.h>


#define NUM 12 

#define FETCH 1000 //每月取出的金额
#define RATE 0.0171 //存款利率

void feipolaqishuli(void)
{
	unsigned int fib[NUM] = {1,1};
    int i = 0;
    for(i = 2; i < NUM;i++ )
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int i = 0; i < sizeof(fib)/sizeof(unsigned int);i++)
    {
        printf("%d 月兔子总数为:--%d\n",i,fib[i]);
    }
}

void cunkuan(void)
{
	double corpus[49] = {0};

	corpus[48] = (double)FETCH; //保证最后一个月有1000
	int i = 0;

	for (i = 47; i > 0; --i)
	{
		/* code */
		corpus[i] = (corpus[i+1] + FETCH) / (1 + RATE / 12);
	}

	int j = 0;
	for (j = 0; j < 49; ++j)
	{
		/* code */
		printf("%d 个月末连本带息合计:  %.8f\n",i,corpus[i]);
	}
}


int main(void)
{
  
    cunkuan();

    return 0;
}
