//
//  Circle.cpp
//  temp
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "Circle.hpp"
#include "Point.hpp"

Circle::Circle(Point p , double radius)
{
    m_circleP = p;
    m_Radius = radius;

}

Point Circle::getCircleP()
{
    return m_circleP;
}

double Circle::getRadius()
{
    return m_Radius;
}


bool Circle::compareDistance(Circle &c1)
{
    bool isH = false;

    Point p = c1.getCircleP();
    double sum = m_circleP.getAPointDistance(p);
    double dis = m_Radius + c1.getRadius();

    if (sum == dis)
    {
        std::cout << "两个圆相切 --- \n";
    }
    else if (sum > dis)
    {
        std::cout << "两个圆不相交 -- \n";
    }
    else
    {
        std::cout << "两个圆相交 \n";
    }



    return isH;
}
