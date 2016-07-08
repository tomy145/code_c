#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64

struct teacher
{
    int id;
    char *name;
};


void creat_teacher(struct teacher **tpp , int len)
{

    struct teacher *tp = NULL;

    tp = (struct teacher *)calloc(len, sizeof(struct teacher));

    for (int i = 0; i < len; i++)
    {
        tp[i].name = calloc(NAME_LEN, sizeof(char));
    }

    *tpp = tp;

}

int main(void)
{
    struct teacher*tp = NULL;
    int num = 2;

    creat_teacher(&tp,num);

    return 0;
}