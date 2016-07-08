//
//  Circle.cpp
//  temp
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "Circle.hpp"


/**
    圆 相关
*/
void Circle::setRadius(double r)
{
    this->radius = r;
}

double Circle::getCircleArea()
{
    return this->radius * this->radius * 3.1415;
}

double Circle::getCircleDistance()
{
    return this->radius * 2 * 3.1415;
}



/** 正方体相关 --- */
void Cube::setLength(double l)
{
    this->length = l;
}

void Cube::setWidth(double w)
{
    this->wdith = w;
}

void Cube::setHeight(double h)
{
    this->height = h;

}

double Cube::getCubeArea()
{
    return 2 * (height * wdith + height * length + wdith * length);
}

double Cube::getCubeSolidity()
{
    return height * wdith * length;
}

/**
 *  判断两个立方体类是否相等
 *
 *  @param src  原立方体
 *  @param dest 比较的立方体
 *
 *  @return 是否相等
 */
bool Cube::isEqualCube(Cube src,Cube dest)
{
    bool isEqual = false;

    if (src.height == dest.height && src.length == dest.length && src.wdith == dest.wdith)
    {
        isEqual = true;
    }

    return isEqual;
}



Point::Point(double x,double y)
{
    locationX = x;
    locationY = y;
};

double Point::getPointX()
{
    return locationX;
}

double Point::getPointY()
{
    return locationY;
}


ADVCircle::ADVCircle(double x,double y)
{
    circlePointX = x;
    circlePointY = y;
};

void ADVCircle::setRadius(double r)
{
    radius = r;
}


bool ADVCircle::isInTheCircle(Point p)
{
    bool isInHere = false;
    double sum = (circlePointX - p.getPointX()) * (circlePointX - p.getPointX()) + ((circlePointY - p.getPointY()) * (circlePointY - p.getPointY()));

    if (sum <= radius * radius)
    {
        isInHere = true;
    }

    return isInHere;
}





