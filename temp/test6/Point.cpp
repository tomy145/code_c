//
//  Point.cpp
//  temp
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "Point.hpp"
#include <math.h>

Point::Point(double x , double y)
{
    m_x = x;
    m_y = y;
}

Point::Point()
{
    m_x = 0;
    m_y = 0;
}

double Point::getAPointDistance(Point p)
{
    double distance = 0.00;

    distance =  sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));

    return distance;
}
