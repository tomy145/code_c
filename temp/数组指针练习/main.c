

#include<stdio.h>


using namespace std;


//方法一 定义一个数组类型
typedef int(ARRAY_INT_10)[10];

//方法二 定义一个数组指针类型
typedef int(*ARRAY_INT_10_P)[10];

int main(void)
{
//    int array[10];
//    ARRAY_INT_10 *array_p = NULL;
//
//
//    array_p = &array;
//
//    for (int i = 0; i < 10; i++) {
//        (*array_p)[i] = i + 10;
//    }
//
//
//    ARRAY_INT_10_P array_p2 = NULL;
//
//    array_p2 = &array;
//
//    for (int i = 0; i < 10; i++) {
//        cout << (*array_p2)[i] << " ";
//    }
//    cout << endl;
//
//
//    int(*array_p3)[10] = NULL;
//
//    array_p3 = &array; //所有指针的级别都是一级， 只不过区别，指针所指向的数据类型。
//
//    array_p3++; // + sizeof(int[10)
//
//    for (int i = 0; i < 10; i++) {
//        cout << (*array_p3)[i] << " ";
//    }
//    cout << endl;
//    


//    int arr[3][4] = {{1,2,3,4} , { 5,6,7,8} , {9 , 10 , 11 , 12}};




    
    return 0;
}