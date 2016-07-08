//
//  main.cpp
//  delegate
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>

class People
{

public:
    People(std::string name)
    {
        this->name = name;
    }

    virtual void liugou() = 0;

private:
    std::string name;

};


class Dog
{

public:
    Dog(std::string name)
    {
        this->name = name;
    }



private:
    std::string name;

};

int main(int argc, const char * argv[])
{

    People p1 = People("张三");
    Dog d1

    p1.liugou =



    return 0;
}
