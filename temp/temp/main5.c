#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//C±ê×¼¿â


int get_non_space_cnt(/*int*/char *src,/*out*/ int *cnt_p)
{
    char *p = NULL; //×ó±ßµÄÖ¸Õë
    char *q = NULL; //ÓÒ±ßµÄÖ¸Õë
    int cnt = 0;

    if (src == NULL || cnt_p == NULL) {
        printf("src == NULL || cnt_p == NULL\n");
        return -1;
    }

    //¸øpºÍq³õÊ¼»¯
    p = src;
    q = src + strlen(src) - 1; //q²»ÊÇÖ¸Ïò\0 ÊÇ×îºóÒ»¸ö×Ö·û

    //×ó±ßÖ¸Õë´Ó×óÏòÓÒ±éÀú ÖªµÀÓö¼ûºÏ·¨×Ö·û »òÕß\0ÎªÖ¹
    while (isspace(*p) && *p != '\0') {

        //while ((*p == ' ') && *p != '\0') {
        p++;
    }

    //ÓÒ±ßÖ¸Õë´ÓÓÒÏò×ó±éÀú£¬ Ö±µ½Óö¼ûºÏ·¨×Ö·û »òÕß=qÎªÖ¹
    //while ((*q == ' ') && (q > p)) {
    while (isspace(*q) && *p != '\0')
    {

        q--;
    }

    cnt = q - p + 1;

    *cnt_p = cnt;

    return 0;
}

int getstrCount(const char *str)
{
    unsigned int count = 0;

    char *temp = (char *)str;
    while (*temp != '\0')
    {
        if (isspace(*temp) == 0)
        {
            ++count;
        }
        temp+=1;
    }


    return count;
}

int main6(int argc, char **argv)
{
    char *str = "     zhan g3     ";
    int cnt = 0;
    
//    if (get_non_space_cnt(str, &cnt) == -1) {
//        printf("get_non_space_cnt error\n");
//    }
//    
//    printf("%s:%d\n", str, cnt);

    printf("stjk-- %d\n",getstrCount(str));
    
    return 0;
}