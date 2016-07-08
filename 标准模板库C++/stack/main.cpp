//
//  main.cpp
//  stack
//
//  Created by Mac on 16/6/13.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <list>
#include <queue>
#include <set>
#include <thread>


using namespace std;

void test1()
{

    //(10010011) = 1*20  + 1*21 + 0*22 + 0*23 + 1*24 + 0*25 + 0*26 + 1*27
    //= 1 + 2 + 0 + 0 + 16+ 0 + 0 + 128 = 147


    //
    int arr[8] = {1,0,0,1,0,0,1,1};

    int value = 0;

    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++)
    {
        cout << "c = " << arr[len -1 - i] << endl;
        value = value +  (arr[len - 1 - i] * pow(2, i));
        cout << "value = " << value << endl;
    }


    string str = "12345";

    str.c_str();

    //    char *c_s = str.at(1).c_string;
    //    cout << atof(str[1].c_string) << endl;
    
    

}


void test2()
{
    //    假设字符串A=“abcdeadbecffgattbyyyyzcabllcarrrbc7ab00cabc”，
    //    字符串B="abc"
    //
    //    求字符串B在字符串A中出现的次数，不连续的也算如：“adbec”

    string str1 = "abc";
    string des = "abcdeadbecffgattbyyyyzcabllcarrrbc7ab00cabc";



}

void test3()
{
    string str = "10010011";
    stack<int> st;
    for (int i = 0; i < str.size(); ++i)
    {
        st.push(str.at(i) - '0');
    }

    // 计算
    int res = 0;
    int num = 0;
    while (!st.empty())
    {
        int top = st.top();
        res += top * pow(2, num);
        num++;
        // 弹出栈顶元素
        st.pop();
    }
    cout << "res = " << res << endl;
}



// 字符串匹配
void findSubStr()
{
    string str = "abc de a d b e c ffg a tt b yyyyz c ab ll c a rrr bc 7 ab 00 c abc";
    string sub = "abc";

    // 队列
    queue<char> q;
    for (int i = 0; i < sub.size(); ++i)
    {
        q.push(sub.at(i));
    }

    // 构造另外一个队列对象
    queue<char> q1(q);
    // q1 = q;

    int count = 0;
    // 遍历大字符串
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it == q.front())
        {
            // 弹出队头元素
            q.pop();
        }
        if (q.empty())
        {
            count++;
            q = q1;
        }
    }
    cout << "count = " << count << endl;
}

void test4()
{
    string str = "11113.141592654";

    cout << stold(str) << endl;


    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i + '1');
    }

    for (int i = 0; i < 10; i++)
    {
        int val = q.front();

        cout << "val = " << val << endl;

        q.pop();
        
    }

}



struct People
{
    string name;
};


class Person:public People
{

};

int main(int argc, const char * argv[])
{





    




    return 0;
}


