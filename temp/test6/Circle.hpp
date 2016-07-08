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
#include "Point.hpp"

class Circle
{
public:

    Circle(Point p , double radius);
    bool isInHere(Point p);

private:
    Point m_circleP;
    double m_Radius;

};


#endif /* Circle_hpp */
