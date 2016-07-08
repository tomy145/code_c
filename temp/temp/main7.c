



#include <stdio.h>
#include<string.h>
#include <stdlib.h>

/*
 1、有一个字符串“1a2b3d4z” ；
 要求写一个函数实现如下功能：
 功能1：把偶数位字符挑选出来，组成一个字符串1。
 功能2：把奇数位字符挑选出来，组成一个字符串2。
 功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
 功能4：主函数能测试通过。
 int	getStr1Str2(char	*source, char	*buf1, char	*buf2);
 */


int getStr1Str2(char *source , char **buf1 , char **buf2)
{

    int ret = -1;
    char *tem = source;
    if (buf1 == NULL || buf2 == NULL || source == NULL)
    {
        printf("buf1 == NULL || buf2 == NULL || source == NUL error\n");
        ret = -1;
    }
    else
    {
        ret = 0;
    }

    int len = (int)strlen(source);

    char tempBuf1[100] = {0};
    char tempBuf2[100] = {0};

    int j = 0 , k = 0;
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0 )
        {
            tempBuf1[j] = *tem;
            ++j;
            printf("buff1--- %s --- %d --- %c \n",tempBuf1,i,*tem);
        }
        else
        {
            tempBuf2[k] = *tem;
            ++k;
            printf("buff2--- %s --- %d --- %c \n", tempBuf2, i, *tem);

        }
        ++tem;
    }

    tempBuf1[len/2] = '\0';
    tempBuf2[len - len/2] = '\0';

    strncpy(*buf1, tempBuf1, 100);
    strncpy(*buf2, tempBuf2, 100);


    printf("**str1--- %s --- **str2 --- %s\n", *buf1, *buf2);

    return ret;

}

void test1()
{
    char src[] = "1234kskdl22pl";

    char *str1 = calloc(100, sizeof(char));
    char *str2 = calloc(100, sizeof(char));

    getStr1Str2(src,&str1,&str2);

    printf("str1--- %s --- str2 --- %s\n",str1,str2);

    free(str1);
    free(str2);

}

/*
2、键值对（“key = value”）字符串，在开发中经常使用.
要求1：请自己定义一个接口，实现根据key获取.
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格
注意：键值对字符串格式可能如下：
"key1	=	value1"
"key2	=							value2"
"key3		=	value3"
"key4								=	value4"
"key5			=			"
"key6			="
int	getKeyByValue(char	*keyvaluebuf,		char	*keybuf,		char	*valuebuf,	int	*
                  valuebuflen);
*/


int getKeyValue(const char *keyValueBuf, char **keyBuf1 , char **valuebuf ,int *valuebuflen)
{

    int ret = -1;
    char *temp = (char *)keyValueBuf;

    char *sub = "=";

    if (keyValueBuf == NULL || keyBuf1 == NULL ||  valuebuf == NULL || valuebuflen == NULL)
    {
        printf("keyValueBuf == NULL || keyBuf1 == NULL ||  valuebuf == NULL || valuebuflen == NULL error! \n");
        return -1;
    }
    else
    {
        int i = 0;
        char *p = NULL;
        while ((p = strstr(temp, sub)) != NULL) //检查字符串是否合法
        {
            printf("p -- %s\n",p);
            ++i;
            temp = p + 1;
        }

        char *p2 = NULL;
        if (i == 1)
        {
            p2 = strstr(temp, sub);
//            char *p2

        }


    }


    return ret;
}

void test2()
{

    char *str1 = "123 = llsl   ss";
    char str2[100] = {0};
    char str3[100] = {0};
    int len = 0;


    getKeyValue(str1, &str2, &str3, &len);


}

int main7(int argc, const char *argv[])
{
    

    char **p = NULL;
    //开辟
    p = calloc(4, sizeof(char *));
    for (int i = 0; i < 4; i++)
    {
        p[i] = calloc(6, sizeof(char));
    }


    char *str[5] =
    {

        "bbbb",
        "aaaa",
        "dddd",
        "cccc"
    };

    for (int i = 0; i < 4; i++)
    {
        strcpy(p[i], str[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("ss --- %s\n",p[i]);
    }


    printf("---------------------\n");

    char buf[6] = {0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            if (strcmp(p[i], p[j]) > 0)
            {
                strcpy(buf, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], buf);
            }
        }
    }


    for (int i = 0; i < 4; i++)
    {
        printf("ss --- %s\n",p[i]);
    }

    //释放内存
    for (int i = 0; i < 4; i++)
    {
        if (p[i] != NULL)
        {
            free(p[i]);
        }
    }


    free(p);

    
    return 0;
}