
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char *word;
    unsigned int trans_len;
    char **trans;

}Word;

/**
 *  获取长度
 *
 *  @param fp 文件指针
 *
 *  @return 长度
 */
int get_count(FILE *fp)
{
    int len = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        ++len;
    }
    rewind(fp);


    return len / 2;
}

/**
 *  获取单词解释个数
 *
 *  @param buffer 读取缓冲
 *
 *  @return 有多少个解释
 */
int get_transLen(char *buffer)
{
    int n = 0;
    char *p = buffer;
    while ((p = strchr(p, '@')) != NULL) {
        n++;
        p = p+1;
        while (*p == '@')
            p = p+1;
    }

    return n+1;
}


/**
 初始化解释

 */
void init_trans(char **trans,char *buffer,int len)
{

    unsigned long temLen = 0;
    int i = 0;

    char *del = "@";
    char *token;

    token = strtok(buffer, del);
    temLen = strlen(token);
    trans[i] = malloc(temLen + 1);
    strcpy(trans[i], token);
    i++;

    while(((token = strtok(NULL, del)) != NULL) && i < len)
    {

        temLen = strlen(token);
        trans[i] = calloc(temLen + 1, sizeof(char));
        strcpy(trans[i], token);
        i++;

    }

}



/**
 初始化单词

 */
void init_words(Word *words,int len,FILE *fp)
{
    unsigned long word_len = 0; //单词长度
    unsigned long trans_Len = 0;

    char buffer[1024];
    for (int i = 0; i < len; i++)
    {
        fgets(buffer, sizeof(buffer), fp);
        word_len = strlen(buffer+1);
        words[i].word = calloc(word_len,sizeof(char));
        strcpy(words[i].word, buffer+1); //拷贝单词

        printf("spp --- %s\n",words[i].word);

        //拷贝解释
        fgets(buffer, sizeof(buffer), fp);
        words[i].trans_len = get_transLen(buffer);;
        words[i].trans = calloc(trans_Len, sizeof(char *));
        init_trans(words[i].trans,buffer + 6,len);

//        printf("trab --- %s\n",*words[i].trans);


    }

}


void show_word(Word w)
{
    int i;
    for (i = 0; i < w.trans_len; i++)
        printf("%s", w.trans[i]);
}


void search_words(Word *words,int len)
{
    int i = 0;

    char buf[100] = {0};
    while (1)
    {
        i ++ ;
        printf("请输入一个单词\n");
        fgets(buf, sizeof(buf) ,stdin);

        if (strcmp("#q\n", buf) == 0) //退出
        {
            printf("退出\n");
            break;
        }
        else
        {
            for (int j = 0; j < len; j++)
            {
                if (strcmp(words[j].word, buf) == 0)
                {
                    show_word(words[j]);
                    break;
                }
            }
        }

        if (i == len)
        {
            printf("未找到--\n");
        }

    }

}


void free_words(Word *words,int len)
{

    for (int i = 0; i < len; i++)
    {
        free(words[i].word);

        for (int j = 0; j < words[i].trans_len; j++)
        {
            free(words[i].trans[j]);
        }

        free(words[i].trans);
    }

    free(words);

}


int main(int argc,const char *argv[])
{
    const char *dir = "/Users/Mac/Desktop/temp/main/main/cc.txt";
    FILE *fp;
    unsigned int len = 0;
    Word *words = NULL;

    fp = fopen(dir, "r");
    //打开文件
    if (fp == NULL)
    {
        printf("打开失败!\n");
    }
    else
    {
        //获取单词数量
        len = get_count(fp);
        words = (Word *)calloc(len, sizeof(Word));

        //初始化数据
        init_words(words,len,fp);

        //搜索单词
        search_words(words,len);
//
//        //释放内存
        free_words(words,len);

    }

    fclose(fp);






    return 0;
}
