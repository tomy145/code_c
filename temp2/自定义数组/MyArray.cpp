//
//  MyArray.cpp
//  temp2
//
//  Created by Mac on 16/5/31.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "MyArray.hpp"



MyArray::MyArray()
{
    this->len = 0;
    this->space = (int *)calloc(0, sizeof(int));
}


MyArray::MyArray(int len)
{
    this->len = len;
    this->space = (int *)calloc(len, sizeof(int));

}


MyArray::~MyArray()
{
    if (this->space != nullptr)
    {
        delete this->space;
        this->space = nullptr;
        this->len = 0;
    }
}

//实现深拷贝
MyArray::MyArray(const MyArray &another)
{



    this->space = new int[another.len];
    this->len = another.len;

    for (int i = 0; i < another.len; i++)
    {
        this->space[i] = another.space[i];
    }

}

 void MyArray::setData(int index, int value)
{
    if (checkOverStep(index) == true)
    {
        this->space[index] = value;
    }

}

int MyArray::getData(int index)
{

    if (checkOverStep(index) == true)
    {
        return this->space[index];
    }
    else
    {
        return 0;
    }

}


/**
 *  检查数组是否越界
 *
 *  @param index 索引
 *
 *  @return 是否越界，越界，则会抛出错误
 */
bool MyArray::checkOverStep(int index)
{

    bool check = false;

    if (index <= this->len)
    {
        check = true;
    }
    else
    {
        printf("数组越界  -- index = %d  ， 数组长度是--- %d\n",index,this->len);
        assert(!(index > this->len));
    }

    return check;
}


int MyArray::getLen()
{
    return this->len;
}