//
//  cat.hpp
//  temp2
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef cat_hpp
#define cat_hpp

#include <stdio.h>
#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal
{

public:

    Cat(std::string name , int age);
    Cat();

    virtual void voice();
    virtual void run();

    
private:
    std::string name;
    int age;

};

#endif /* cat_hpp */
