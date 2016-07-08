//
//  main.cpp
//  test5
//
//  Created by Mac on 16/5/28.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <array>
#include <random>
#include "Circle.hpp"


using namespace std;

//void printArray(array<arr> arr)
//{
//
//}

void test2()
{
    array<int, 10> arr1;

    for (int i = 0; i < 10; i++) //根据索引赋值
    {
        arr1[i] = i + 'a';
    }



}



//class Circle
//{
//
//    double radius;
//
//public:
//    void setRadius(double r)
//    {
//        this->radius = r;
//    }
//
//    double getCircleArea()
//    {
//        return this->radius *  this->radius * 3.141592654;
//    }
//
//    double getCircleDistance()
//    {
//        return this->radius * 2 * 3.141592654;
//    }
//
//};


void test1()
{
    Circle c1 = Circle();
    c1.setRadius(12.0);

    cout << "circle.area = " << c1.getCircleArea() << endl;
    cout << "circle.distance = " << c1.getCircleDistance() << endl;

}

void test3()
{
    Cube cu1 = Cube();
    Cube cu2 = Cube();

    cu1.setWidth(13.0);
    cu1.setHeight(29.8);
    cu1.setLength(26.5);

    cu2.setWidth(13.0);
    cu2.setHeight(29.8);
    cu2.setLength(26.5);

    cout << "cu1.area = " << cu1.getCubeArea() << endl;
    cout << "cu2.area = " << cu2.getCubeArea() << endl;

    cout << "cu1.solidity = " << cu1.getCubeSolidity() << endl;
    cout << "cu2.solidity = " << cu2.getCubeSolidity() << endl;


    cout << "cu1 is Equal cu2 = " << cu1.isEqualCube(cu1, cu2) << endl;

}

void test4()
{
//    int i = 0;
//   int a =  [=]{ cout << i << endl;}(int a); /* 'i' is not captured */


}

void test5()
{

    ADVCircle c2 = ADVCircle(2, 2);
    c2.setRadius(14.0);

    Point p1 = Point(19, 19);

    cout << "是否在圆内 --- " << c2.isInTheCircle(p1) << endl;

}



int main(int argc, const char * argv[])
{

    test5();


    return 0;
}
