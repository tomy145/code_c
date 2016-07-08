//
//  Circle.hpp
//  temp
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <iostream>
#include "Point.hpp"

class Circle
{
public:

    Circle(Point p , double radius);
    Point getCircleP();
    double getRadius();
    bool compareDistance(Circle &c1);

private:
    Point m_circleP;
    double m_Radius;

};


#endif /* Circle_hpp */
