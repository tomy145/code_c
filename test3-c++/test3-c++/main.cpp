#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void divide(int x, int y)
{
    if (y == 0)
    {
        std::cout << "除数不能为0" << std::endl;
        char *str = "除数不能为0";
        throw str ;
    }
    cout <<"x/y = " << x / y << endl;
}

//1 异常的捕获是按照类型匹配的
//2 如果异常捕获不到，这个异常将会继续抛给上一层 ，加入说知道main函数都捕获不到
//	 那么此异常会继续往上抛， 最终将会给操作系统处理，操作系统处理异常的默认方式就是崩溃
//3 如果异常被捕获到，异常就会在当前的层级终止，因为已经可以认为该异常已经被处理了


//写一个中间层
void use_divide(int x, int y)
{
    try {
        divide(10, 0);

    }
    catch (char e)
    {
        cout << "use_divide函数捕获到了异常char e=" << e << endl;

    }
    catch (int e) {
        cout << "use_divide函数捕获到了异常int e=" << e << endl;
    }
}

int main(void)
{
    try
    {
        divide(10, 0);

    }
    catch (int e)
    {
        cout << "main函数捕获到了异常int e=" << e << endl;
    }
    catch (char e)
    {
        cout << "main函数捕获到了异常char e=" << e << endl;
    }
    catch (std::string exp) //表示捕获全部的所有类型的异常
    {
        cout << "main函数捕获到了...异常 --" << exp << endl;
    }
    
    return 0;
}