//
//  main2.c
//  temp
//
//  Created by Mac on 16/5/16.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 *  缓存池结构体
 */
typedef struct
{

    void **freeBuffer; //void *数组

    unsigned long bufferLength; //数组长度


}MemoryBuffer;

void freeMem(char *p1,char *p2)
{
    if (p1 != NULL && p2 != NULL)
    {
        free(p1);
        free(p2);
    }

}


typedef void (*freeMemory)(char *,char *);

//释放池 --- 全局
MemoryBuffer *buffer;




typedef struct {

    char * mem1; //第一块内存
    unsigned int mem1_length; //第一块内存的长度

    char * mem2; //第二块内存
    unsigned int mem2_length; //第二块内存长度

    freeMemory frp;

}MemReturn;




MemReturn get_mem(void)
{

    MemReturn mem1;

    //初始化一块空间
    char *me1 = calloc(300, sizeof(char));
    strcpy(me1, "123456");

    //给结构体赋值
    mem1.mem1 = me1;
    mem1.mem1_length = 300;

//    //将开辟好的内存地址存放到缓存池里面
//    buffer->freeBuffer[0] = me1;

    //初始化第二块空间
    char *me2 = calloc(400, sizeof(char));
    strcpy(me2, "abcdef");

    mem1.mem2 = me2;
    mem1.mem2_length = 400;

//    //将开辟好的内存地址存放到缓存池里面
//    buffer->freeBuffer[1] = me2;

    printf("me1 地址 -- %p\n",me1);
    printf("me2 地址 -- %p\n",me2);

    mem1.frp = freeMem; //

    return mem1;
}


void test3()
{
    //    //初始化缓存池
    //    buffer = calloc(1, sizeof(MemoryBuffer));
    //    buffer->bufferLength = 300;
    //    buffer->freeBuffer = calloc(buffer->bufferLength, sizeof(void *));

    MemReturn memory = get_mem();
    printf("st1 -- 内容是 --- %s --- len -- %d\n",memory.mem1,memory.mem1_length);
    printf("st2 -- 内容是 --- %s --- len -- %d\n",memory.mem1,memory.mem2_length);

    memory.frp(memory.mem1,memory.mem2); //释放内存

    //    memory.p = freeMemf(memory.mem1, memory.mem2);

    //    for (int i = 0; i < buffer->bufferLength; i++)
    //    {
    //        void *tem = buffer->freeBuffer[i];
    //        printf("缓存池里面第 -- %d-- 内存地址--- %p --\n",i,buffer->freeBuffer[i]);
    //        int bre = -1;
    //        bre = (tem != NULL);
    //        if (bre)
    //        {
    //            free(tem); //内存释放出错
    //        }
    //        if (bre <= 0) break;
    //    }
    
    
    //    free(buffer);

}


char *from_src_to_get_sub_str(const char *src)
{
    char *temp = (char *)src;
    char *str = calloc(strlen(src) + 1, sizeof(char));

    int i = 0;
    while (isspace(*temp) == 0)
    {
        str[i] = *temp;
        printf("str--- %c --- %s --- %d\n",str[i],str,i);


        temp++;
        i++;


    }


    return str;
}

//int getcount( char *str)
//{
//    int count = 0;
//
//    char *temp = (char *)str;
//
//    while (temp != NULL)
//    {
//        count++;
//        temp++;
//    }
//
//    return count;
//}


int get_mem2(char **p1,int *p1_len,char **p2,int *p2_len)
{

    if (p1 == NULL || p1_len == NULL || p2 == NULL || p2_len == NULL)
    {
        printf("p1 == NULL || p1_len == NULL || p2 == NULL || p2_len == NULL\n");
    }
    else
    {
        char *temp1 = NULL;
        char *temp2 = NULL;
        int len1 = 0;
        int len2 = 0;


        temp1 = calloc(300, sizeof(char));
        temp2 = calloc(400, sizeof(char));
        strcpy(temp1, "123456");
        strcpy(temp2, "abcdefg");

        len1 = 300;
        len2 = 400;

        *p1 = temp1;
        *p2 = temp2;

        *p1_len = len1;
        *p2_len = len2;
    }


    return 0;
}

int main4(int argc, const char *argv[])
{

    //emoji 6 个字节 ，中文三个字节 24 + 12
//    char str[] = "   123 ksdl '\0'lsl 😂 lsl中文  ";

//    char *p1 = NULL;
//    char *p2 = NULL;
//    int len1 = 0;
//    int len2 = 0;
//
//    get_mem2(&p1, &len1,&p2 , &len2);
//
//    free(p1);
//    free(p2);

//    p1 = NULL;
//    p2 = NULL;

//    sleep(3);

//    printf(" -- %s --- %d -- %s --- %d\n",p1,len1,p2,len2);
//    printf("temp --- %s --- %lu --- %lu\n",str , sizeof(str),strlen(str));

//    char *st = "   lsl  irosl  ";

//    printf("l-- %lu\n",strlen(st));




    return 0;
}