
int main(void)
{
    int num = 0;
    printf("请输入一个整数 :\n");
    scanf("%d",&num);
    int count = 0;
    while (num > 0)
    {
        if((num & 1) == 1)
        {
            count += 1;
        }

        num = num >> 1 ; // 移位
    }

    printf("count -- %d\n",count);

    return 0 ;
}

