//
//  main.c
//  day03习题
//
//  Created by Mac on 16/5/17.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 （1）有字符串有以下特征(“abcd11111abcd2222abcdqqqqq”),求写一个函数接口, 输出以下结果。 把字符串替换成( dcba11111dcba2222dcbaqqqqq),并把结果传出。
 要求:                                                                                                 |

 1. 正确实现接口和功能

 */

 int replaceSubstr(/* in */const char *src, /* out */char** dst, /* in */char *sub,  /* in */char *new_sub)
{


    char *temp = calloc(strlen(src) + 1, sizeof(char));
    strcpy(temp, src);
    char *temp_dest = temp;
    char *temp_src = (char *)src;

    char *p1 = NULL;
    int k = 0;
    while ((p1 = strstr(temp_src, sub)) != NULL)
    {

        for (int i = 0; i < strlen(new_sub); ++i)
        {
            printf("ll -- %s\n",temp);
            temp[p1  - src + i] = new_sub[i];
            printf("pp -- %s\n",temp);

        }

        temp_src += strlen(new_sub);
        ++k;

    }


    printf("temsrc -- %p\n",temp);

    printf("%s--\n",temp_dest);

    * dst = temp_dest;

    return 0;
}

void  test1()
{

    char *src = "abcd11111abcd2222abcdqqqqq";
    char *sub = "abcd";
    char *newStr = "dcba";
    char *new = NULL;
    replaceSubstr(src, &new, sub, newStr);
    printf("new --- %s\n",new);

    free(new);


}

/*
 (2) 有一个字符串符合以下特征(“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”)
 写两个函数(API),输出以下结果
 第一个API

 1)以逗号分隔字符串,形成二维数组,并把结果传出
 2)把二维数组行数运算结果也传出



 第二个API


 1)以逗号分隔字符串,形成一个二级指针。
 2)把一共拆分多少行字符串个数传出


 要求:


 1, 能正确表达功能的要求,定义出接口。

 2, 正确实现接口和功能.

 3, 编写正确的测试用例.
 */

void getStrArray(const char *src , char***dest , int *len)
{
    char *tempsrc = (char *)src;
    int k = 0;
    char *p = NULL;
    char buf[10] = {0};

    char **str = NULL;

    str = calloc(6, sizeof(char *));

    for (int i = 0; i < 10; i++)
    {
        str[i] = calloc(10, sizeof(char));
    }

    while ((p = strstr(tempsrc, ",")) != NULL)
    {

//        char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss";
        strncpy(buf,tempsrc, p - tempsrc); //拷贝完毕
        printf("buf --- %s\n",buf);

        strncpy(str[k], buf, strlen(buf));
        printf("str --- %s\n",str[k]);


        //清空buf
        memset(buf, 0, sizeof(buf));
        p += strlen(",");
        tempsrc = p;
        k++;
        printf("p -- %p --- tem --%p\n",p,tempsrc);

    }



    int lens = (int)strlen(tempsrc);
    if (lens)
    {
        //        char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss";
        memcpy(buf,tempsrc, strlen(tempsrc)); //拷贝完毕
        printf("buf --- %s\n",buf);

        strncpy(str[k], buf, strlen(buf));
        printf("str --- %s\n",str[k]);

    }

    *len = k + 1;
    *dest = str;

}

void test2()
{
    char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss";
    int len = 0;
    char **buf = NULL;

    getStrArray(str,&buf,&len);

    //打印
    for (int i = 0; i < len; i++)
    {
        printf(" --- %s\n",buf[i]);
    }

    //释放
    for (int i = 0; i < len; i++)
    {
        if (buf[i] != NULL)
        {
            free(buf[i]);
        }
    }

    free(buf);

}



int main(int argc, const char * argv[])
{

        return 0;
}
