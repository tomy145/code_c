//
//  Point.hpp
//  temp
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point
{
public:

    Point(double x , double y); //如果显示声明了有参构造函数，那么默认构造函数，系统就不会给你生成
    Point(); //如果在其他对象使用了该对象，那么必须显示的声明默认构造函数

    double getAPointDistance(Point &p);

private:
    double m_x;
    double m_y;

};


#endif 
