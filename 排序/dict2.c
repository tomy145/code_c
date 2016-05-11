#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WORD
{
    char *key;
    int n_trans;
    char **trans;
};

int count_word(FILE *fp)
{
    int i = 0;
    char buf[1024];

    while (fgets(buf, sizeof(buf), fp))
        i++;

    return i/2;
}

int count_item(char *buf)
{
    int n = 0;
    char *p = buf;
    while ((p = strchr(p, '@')) != NULL) {
        n++;
        p = p+1;   
        while (*p == '@')
            p = p+1;
    }

    return n+1;
}

void cmd_trans(char *buf, char **trans, int n_trans)
{
    int i = 0, len;
    char *p;
    char *delim = "@";

    p = strtok(buf, delim);
    len = strlen(p);
    trans[i] = malloc(len+1);
    strcpy(trans[i], p);

    i++;
    while (((p = strtok(NULL, delim)) != NULL) && (i < n_trans)) {
        len = strlen(p);
        trans[i] = malloc(len+1);
        strcpy(trans[i], p);
        i++;
    }
}
int init_words(struct WORD *words, int n, FILE *fp)
{
    int i, len;
    char buf[1024]; 
    for (i = 0; i < n; i++)
    {
        //单词
        fgets(buf, sizeof(buf), fp);
        len = strlen(buf);
        words[i].key = (char *)malloc(len);
        strcpy(words[i].key, buf+1);

        //解释
        fgets(buf, sizeof(buf), fp);
        words[i].n_trans = count_item(buf);
        words[i].trans = malloc(words[i].n_trans * sizeof(char *));
        cmd_trans(buf+6, words[i].trans, words[i].n_trans);


    }
    return 0;
}
void show_word(struct WORD word)
{
    int i;
    for (i = 0; i < word.n_trans; i++)
        printf("%s", word.trans[i]);
}

int binaray_search(struct WORD *words, int n, char *buf)
{
    int l = 0, r = n-1, m, res;

    while (r >= l) {
        m = (l+r)/2;
        res = strcmp(words[m].key, buf);
        if (res == 0)
            return m;
        else if (res > 0)
            r = m-1;
        else if (res < 0)
            l = m+1;
    }

    return -1;
}
void search_word(struct WORD *words, int n)
{
    char buf[1024];
    int i, j ,res;

    while (1) {
        printf("please input a word\n");
        fgets(buf, sizeof(buf), stdin);

        if (strcmp(buf, "#exit\n") == 0) 
            break;
        res = binaray_search(words, n, buf);
        if (res == -1)
            printf("un find\n");
        else
            show_word(words[res]);
    }
    return ;
}
void free_words(struct WORD*words, int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        free(words[i].key);
        for (j = 0; j < words[i].n_trans; j++) 
            free(words[i].trans[j]);
        free(words[i].trans);
    }

    free(words);
}
void sort_words(struct WORD *words, int n)
{
    int i, j;
    struct WORD tmp;
    for (i = 0; i < n; i++)
        for (j = 1; j < n-i; j++)
            if (strcmp(words[j-1].key, words[j].key) > 0) {
                tmp = words[j-1];
                words[j-1] = words[j];
                words[j] = tmp;
            }
}
int main(void)
{
    FILE *fp;
    int n;
    struct WORD *words;

    fp = fopen("/Users/Mac/Desktop/temp/main/main/bb.txt", "r");
    n = count_word(fp);
    rewind(fp);
    words = (struct WORD*)malloc(n * sizeof(struct WORD));
    init_words(words, n, fp);
//    sort_words(words, n);
    search_word(words, n);

    fclose(fp);
    free_words(words, n);

    return 0;
}
