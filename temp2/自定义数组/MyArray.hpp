//
//  MyArray.hpp
//  temp2
//
//  Created by Mac on 16/5/31.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


class MyArray
{
public:

    MyArray();
    MyArray(int len);
    ~MyArray();

    //实现深拷贝
    MyArray(const MyArray &another);

    void setData(int index, int value);

    int getData(int index);

    int getLen();

    bool checkOverStep(int index);

private:
    int len;//表示数组元素的个数
    int *space; //应该指向一个堆空间， 这个空间应该存放len个int元素
};





#endif /* MyArray_hpp */
