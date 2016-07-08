//
//  MySTL.hpp
//  STLDemo
//
//  Created by Mac on 16/6/6.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef MySTL_hpp
#define MySTL_hpp

#include <stdio.h>
#include <iostream>

template <typename T>
class MyVector
{


public:
    void push_back();
    void clear();

private:
    T *elements;
    
};


template <typename T>
class MyAray
{


public:
    void insertIndex(int index , T &t1);
    int getSize(T *&list);
    void deleteIndex();


};


#endif /* MySTL_hpp */
