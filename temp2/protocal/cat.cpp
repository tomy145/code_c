//
//  cat.cpp
//  temp2
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "cat.hpp"

using namespace std;
Cat::Cat(std::string name , int age)
{
    this->name = name;
    this->age = age;
}

Cat::Cat()
{
    this->name = "";
    this->age = 0;
}

 void Cat::voice()
{
    std::cout << "Cat Name is - " << this->name << " -- age is --" << this->age << " --- voice voice " << std::endl;
}

void Cat::run()
{
    std::cout << "Cat Name is - " << this->name << " -- age is --" << this->age << " --- run run " << std::endl;
}
