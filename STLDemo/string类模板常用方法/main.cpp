//
//  main.cpp
//  string类模板常用方法
//
//  Created by Mac on 16/6/11.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


//string类的初始化方式
void test1()
{
    string str1; //默认初始化为空字符串
    string str2 = string();
    string str3 = string("hello ") ;; //直接从一个C_string初始化
    string str4 = string(10,'h');
    string str5 = string(str3);
    str5 += "你好";

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    cout << "str5 = " << str5 << endl;


}


//string 的赋值方式
void test2()
{
    string str1 = "你好 世界 !!!";
}

int main(int argc, const char * argv[])
{






    return 0;
}
