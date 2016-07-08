//
//  Employee.hpp
//  temp
//
//  Created by Mac on 16/6/6.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>
#include <iostream>


class Employee
{
    Employee()
    {

    };

    virtual ~Employee()
    {
        std::cout << "virtual ~Employee() ....." << std::endl;
    }

protected:
//    姓名、编号、级别、当月薪水
    std::string name;

};

#endif /* Employee_hpp */



