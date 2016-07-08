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

    Point(double x , double y);
    Point();

    double getAPointDistance(Point p);

private:
    double m_x;
    double m_y;

};


#endif /* Point_hpp */
