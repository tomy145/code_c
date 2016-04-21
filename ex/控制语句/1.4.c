#include<stdio.h>
#include <string.h>

int main(void)
{

    char ch[10] = {'A','B','C','D','E','a','b','c','d','e'};
    int isExist = 0;
    char i = 0;
    char input = '0';
    unsigned int countA = 0, countB = 0 , countC = 0, countD = 0,countE = 0;

    while (1)
    {
        printf("请输入五分制成绩:A,B,C,D,E,a,b,c,d,e\n");
        input = getchar();
        if (35 == input)
        {
            break;
        }

        for(i = 0; i <= 9; i++)
        {
            if (input == ch[i])
            {
                isExist = ch[i];
            }
        }

        if ( isExist >= 0 )
        {
            switch (isExist)
            {
                case 'a':
                case 'A':
                {
                    ++countA;
                    printf("当前分数等级是:90 - 100\n");
                }
                    break;
                case 'b':
                case 'B':
                {
                    ++countB;
                    printf("当前分数等级是:80 - 90\n");


                }
                    break;
                case 'C':
                case 'c':
                {
                    ++countC;
                    printf("当前分数等级是:70 - 80\n");


                }
                    break;

                case 'd':
                case 'D':
                {
                    ++countD;
                    printf("当前分数等级是:60 - 70\n");

                }
                    break;
                case 'E':
                case 'e':
                {
                    ++countE;
                    printf("当前分数等级是:<= 60\n");
                    
                }
                    break;
                    
                default:
                {

                }
                    break;
            }
        }
        else
        {
            printf("please input again\n");
            input = -1;
        }
        scanf("%*[^\n]"); //清空缓冲区
        scanf("%*c");//清空空格
    }


    printf(" END --- 总共输入的次数有:countA -- %d, countB -- %d, countC -- %d,countD -- %d,countE --  %d\n",countA,countB,countC,countD,countE);

    return 0 ;
}

