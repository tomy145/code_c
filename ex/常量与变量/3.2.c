/*************************************************************************
	> File Name: 3.2.c
	> Author: 
	> Mail: 
	> Created Time: 一  4/18 15:44:09 2016
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>

void superCh2LowerCh1(void)
{
	char input = 0;
    printf("Please input a character:\n");
    scanf("%c",&input);
    // printf("input -- %c\n",input);

    if(islower(input))
    {
        printf("supper character is : %c\n",(char)(input - 0x20));
    }
    else
    {
        printf("您输入的字符非法!\n");
    }
}

void superCh2LowerCh2(void)
{
	char input = 0;
    printf("Please input a character:\n");
    scanf("%c",&input);
    printf("input -- %c\n",input);

    if(((int)input >= 97) && ((int)input <= 122))
    {
        printf("supper character is : %c\n",(input - 0x20));
    }
    else
    {
        printf("您输入的字符非法!\n");
    }
}

int main(void)
{
    
    superCh2LowerCh2();
    return 0 ;

}
