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

/// 普通圆
class Circle
{

public:
    void setRadius(double r);
    double getCircleArea();
    double getCircleDistance();

private:
    double radius;

};


/// 立方体
class Cube
{
public:
    void setLength(double l);
    void setWidth(double w);
    void setHeight(double h);

    double getCubeArea();
    double getCubeSolidity();
    bool isEqualCube(Cube src,Cube dest);

private:
    double length; //长
    double wdith; //宽
    double height; //高

};



class Point
{

public:
    Point(double x,double y);
    double getPointX();
    double getPointY();
private:
    double locationX;
    double locationY;

};


class ADVCircle
{

private:

    double circlePointX;
    double circlePointY;
    double radius;

public:
    ADVCircle(double x,double y);
    bool isInTheCircle(Point p);
    void setRadius(double r);

    
    
};



#endif /* Circle_hpp */
