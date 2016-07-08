//
//  main.c
//  07位运算习题
//
//  Created by Mac on 16/5/20.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>


unsigned int getBit(unsigned int x, int pos, int n)
{
    unsigned int count = 0;


    if (pos + n > 32)
    {
        printf("您输入的位置和长度出错!\n");
    }
    else
    {
        unsigned int mask = 0x01;
        unsigned sum = 0;
        for (int i = 0; i < n; i++) //左移0位
        {
            mask = 0x01 << (pos + n -1 - i);
            sum += mask;
        }

        count = sum & x;

        printf("count -- %u\n",count);
        printf("pp --- %u\n",0xf0000000);

    }


    return count;
}

/**
 *  计算1的个数
 *
 *  @param num 数字
 *
 *  @return 返回二进制中1的个数
 */
int getCnt(unsigned int num)
{
    int cnt = 0;


    for (; num != 0 ;  num = num >> 1) {
        if ((num & 0x01) ==1)
        {
            //代表最右边的一位是1
            cnt++;
        }
    }
    
    return cnt;
}



int main(int argc, const char * argv[])
{



    printf("p = %u\n",getBit(0xffffffff, 32 - 4, 4));


    return 0;
}
