#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* 
    将字符串数组进行排序。
    要求把第一种模型的结果 加上第二种模型的结果 放在第三种模型中,并且排 序。最后输出结果
 */

/**
 *  打印字符串数组
 *
 *  @param str 字符串数组
 *  @param len 长度
 */
void print_StrArray(char **str, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf(" --- %s\n",str[i]);

    }
}

/**
 *  排序
 *
 *  @param str 字符串数组
 *  @param len 长度
 */
void sortArr(char **str , int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (strcmp(str[i], str[j]) >0)
            {
                char  *temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

}



//
//#define IN
//#define OUT
//
//int sort(IN char **array1, IN int num1,IN char (*array2)[30], IN int num2,OUT char ***myp3, OUT int *num3)
//{
//
//    int total = num1 + num2;
//    char **p = calloc(total, sizeof(char *));
//    for (int i = 0; i < total; i++)
//    {
//        p[i] = calloc(30, sizeof(char));
//    }
//
//    for (int i = 0; i < num1; i++)
//    {
//        strcpy(p[i], array1[i]);
//    }
//    for (int i = 0; i < num2; i++)
//    {
//        strcpy(p[num1 + i], array2[i]);
//    }
//
//    sortArr(p, total);
//
//    print_StrArray(p, total);
//
//    *myp3 = p;
//    *num3 = total;
//
//    return 0;
//}



//int main(int argc , const char *argv[])
//{
//
//
//    int ret = 0;
//
//    char *p1[] = {"aa", "ccccccc", "bbbbbb"};
//
//    char buf2[10][30] = {"111111", "3333333", "222222"};
//
//
//    char **p3 = NULL;
//
//    int len1, len2, len3;
//
//    len1 = sizeof(p1)/sizeof(*p1);
//    len2 = 3;
//
//    ret = sort(p1, len1, buf2, len2, &p3, &len3);
//
//    for (int i = 0; i < len3; i++)
//    {
//        if (p3[i]!= NULL)
//        {
//            free(p3[i]);
//        }
//    }
//
//    if (p3 != NULL)
//    {
//        free(p3);
//    }
//
//    return  0 ;
//}




//void swap(int array[], int i, int j)
//{
//    int temp = array[i];
//
//    array[i] = array[j];
//
//    array[j] = temp;
//}
//
//void BubbleSort(int array[], int len) // O(n*n)
//{
//    int i = 0;
//    int j = 0;
//    int exchange = 1;
//
//    for(i=0; (i<len) && exchange; i++)
//    {
//        exchange = 0;
//
//        for(j=len-1; j>i; j--)
//        {
//            if( array[j] < array[j-1] )
//            {
//                swap(array, j, j-1);
//
//                exchange = 1;
//            }
//        }
//    }
//}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array);

    println(array, len);

    BubbleSort(array, len);

    println(array, len);

    return 0;
}


