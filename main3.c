//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct Number {
//    char ctr[50];
//    int count;
//};
//
//int countline(FILE *fp)
//{
//    int count = 0;
//    char tmp[1024];
//    while(fgets(tmp,sizeof(tmp),fp))
//    {
//        count++;
//    }
//    return count;
//}
//void CTR(FILE *fp, struct Number *id,int n)
//{
//    char *p;
//    char buf[50];
//    int x = 0,j;
//    while ((p = fgets(buf, sizeof(buf), fp)))
//    {
//        j = 0;
//        for (int i = 0; i <= x; i++)
//        {
//
//            if (strcmp(p, id[i].ctr) == 0)
//            {
//                id[i].count++;
//                j++;
//            }
//        }
//        if (j == 0)
//        {
//            id[x].count = 0;
//            strcpy(id[x].ctr, p);
//            id[x++].count++;
//        }
//    }
//}
//
//void Sort(struct Number *id,int n)
//{
//    int i, j;
//    struct Number tmp;
//    for (i = 0; i < n; i++)
//        for (j = 1; j < n - i; j++)
//        {
//            if (id[j - 1].count < id[j].count)
//            {
//                tmp = id[j - 1];
//                id[j - 1] = id[j];
//                id[j] = tmp;
//            }
//        }
//}
//
//int main(void)
//{
//    FILE *fp;
//    int res;
//    struct Number *id;
//    fp = fopen("D:\\就业班开班练习题\\id.txt", "r");
//    res = countline(fp);
//    rewind(fp);
//    id = (struct Number*)malloc(sizeof(struct Number)* res);
//    CTR(fp, id,res);
//    Sort(id,res);
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%s\t%d\n", id[i].ctr, id[i].count);
//    }
//    system("pause");
//    
//}
