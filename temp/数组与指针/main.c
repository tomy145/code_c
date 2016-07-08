#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int arr[10];

int func1(int a , int b)
{

    printf("this9----\n");


    return 10;
}

typedef int freesMem(int , int) ;


int main(int argc, char **argv)
{
    int a[10] = { 0 };
    int i = 0;
    int j = 0;

    //1、定义指针
    freesMem *f1;

    //2、赋值
    f1 = &func1;

    //3、执行
//    f1(10,20);

    //int a[10]  ,  a ===> int *const a;
    //					   a = &数组首元素 =  &int = &a[0] ===> int *  a++ ;a+sizeof(int) 4
    //				&a ===> 代表整个数组的地址。&a ==> &（int[10]）,  int[10]* , (&a) ++
    //    &a + sizeof(int[10]);  40

    printf("a:%p --- size --- %lu\n", &a , sizeof(&a));
    printf("a+1:%p ----- size --- %lu \n", a + 1,sizeof(a));//4
    printf("&a +1:%p ----- size --- %lu\n", &a + 1,sizeof(&a));//40

    int * p = a;

    int (*q)[10] = &a;
    p++; //4;
    q++;//40

    int aa[3][4] =
    {
        {1,2,3,4},
        {4,5,6,7}
    };

    //int aa[3][4]    aa ---->aa是数组首元素的地址。  数组首元素是谁？ 首元素的类型 int[4]
    // int[4]  aa[3]         aa ===> int[4]*   ===>  aa+1  ===>aa+ sizeof(int[4]);
    //				  &aa ----> 代表整个数组的地址。 (int[3][4])* ---> &aa+1==> &aa+ sizeof(int[3][4]);


//    for (i = 0; i < 3; i++) {
//        for (j = 0; j < 4; j++) {
//            printf("%d ", aa[i][j]); //  aa[i][j]  *(*(aa+i)+j)
//
//        }
//        printf("\n");
//    }
//    printf("\n");


    int ***ls = &aa;

    printf("&aa :%p\n", &aa);//1234
    printf("aa+1:%p\n", aa + 1);//1234+16
    printf("&aa+1:%p\n", &aa + 1);//1234+ 48
    printf("ls--- %p ---- %d\n",*(ls + 1),ls[0]);

    //(int[4])*pp = aa;
    int(*pp)[4] = aa;
    pp++;//16
    
    // (int[3][4])*qq = &aa;
    int(*qq)[3][4] = &aa;
    qq++;//48

    
    return 0;
}