//
//  main.cpp
//  黄绍冬
//
//  Created by Mac on 16/6/10.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstring>
#include <ostream>
#include <istream>

////解答题
////1、指针与应用的区别？
////答：1、引用必须初始化，并且引用一经初始化完毕是不能修改方向的。指针不初始化也可以使用，指针初始化完毕后还是可以改变方向的。
////2、c++中struct和class的区别？
////答：1、struct 不能被继承，而class 可以被继承。2、struct 不能有纯虚函数，而class 可以被继承3、struct和class在使用效率来说，struct 效率要高一些
////3、对于一个频繁使用的短小函数，在C语言中应该使用什么方式实现 ？ 在C++中又应该使用什么方式实现 ？阐述这两者的优缺点?
////答：C语言中频繁使用的短小函数可以使用宏定义来实现，C++可以使用inline关键字来实现，而C语言中的使用宏来实现只是单纯的文本替换，没有严格语法校验，使用起来很危险，而C++中的实现方式则可以实现语法校验，相对来说更安全
//
////4、new和malloc的区别 ？ free和delete的区别 ?
////答：new/delete 和 malloc / free 区别是new 是C++语言中的关键字，而malloc是C语言中的标准库中的一个函数。两者操作对象不同，new 用在对象的时候能够触发构造器，而malloc不能，new 在使用的时候不用强制类型转换，而malloc要强制类型转换。
////5、多态的实现步骤
////答:1、一定要有继承关。2、子类一定要实现父类的纯虚函数， 3、在使用的时候一定要使用父类指针指向子类对象
//
//
//
////二、编程题
//
///**********************************第一题******************************************************/
////1、封装一个二维的点类，功能如下
////a、提供三种构造函数（无参构造，有参构造，拷贝构造）
////b、提供两个方法getX,getY,分别用于得到点的x坐标和y坐标。
////c、提供一个move方法移动一个点的位置
////d、提供一个方法distance计算两个点之间的距离
////e、编写测试用例，测试每一个你所写的函数
//
//class Point
//{
//
//public:
//    Point() //无参构造函数
//    {
//        std::cout << "执行了 - " << typeid(Point).name() << " - 无参构造函数 " << std::endl;
//        this->x = 0;
//        this->y = 0;
//    }
//
//    Point(double x , double y) //有参构造函数
//    {
//        std::cout << "执行了 - " << typeid(Point).name() << " - 有参构造函数 " << std::endl;
//
//        this->x = x;
//        this->y = y;
//    }
//
//    Point(const Point &other) //拷贝构造函数
//    {
//        std::cout << "执行了 - " << typeid(Point).name() << " - 拷贝构造函数 " << std::endl;
//
//        this->x = other.x;
//        this->y = other.y;
//    }
//
//    void moveToPoint(double d_x,double d_y) //移动一个点的坐标
//    {
//        std::cout << "未移动之前的坐标 - x = " << this->x << " - y = "  << this->y << std::endl;
//        this->x = this->x + d_x;
//        this->y = this->y + d_y;
//        std::cout << "移动之后的坐标 - x = " << this->x << " - y = " << this->y << std::endl;
//
//    }
//
//    double getX() //得到X的坐标值
//    {
//        return this->x;
//    }
//
//    double getY() //得到Y的坐标值
//    {
//        return this->y;
//    }
//
//
//    double distance(Point &other) //计算两个点之间的距离
//    {
//        double d_x = other.x - this->x;
//        double d_y = other.y - this->y;
//
//        double dis = sqrt(d_x * d_x + d_y * d_y);
//
//        return dis;
//
//    }
//
//private:
//    double x;
//    double y;
//
//};
//
////class Point 的测试用例
////1、Point() //无参构造函数，使用该函数能够得到一个二维的点的对象，并且坐标初始化为0，使用Demo , Point p = Point();
//
////2、Point(double x , double y) //有参构造函数，使用该函数能够得到一个二维的点的对象，并且坐标初始化x = 传入的x，y = 传入的y .使用Demo , Point p = Point(1.2,2.4);
//
////3、 Point(const Point &other) //拷贝构造函数，该函数是使用一个已经初始化好的Point对象来初始化另外一个Point.
////使用Demo , Point p = Point(1.2,2.4); Point p2 = p1;
//
//
////4、 void moveToPoint(double d_x,double d_y) //移动一个点的坐标 ，该函数的功能是移动一个点的位置，使用Demo
//// Point p = Point(1.2,2.4); p1.moveToPoint(2,3); //p1在原来的基础上x移动了2个单元，y移动了3个单元
////5、double getX() //得到点X的坐标值，该函数的功能是得到当前点的x的坐标，使用Demo Point p1 = Point(2.0,3.4); double x = p1.getX();
//
////6、double getY() //得到点Y的坐标值，该函数的功能是得到当前点的x的坐标，使用Demo Point p1 = Point(2.0,3.4); double y = p1.getY();
//
////7、double getY() //得到点Y的坐标值，该函数的功能是得到当前点的x的坐标，使用Demo Point p1 = Point(2.0,3.4); double y = p1.getY();
////8、double distance(Point &other) //计算两个点之间的距离，该函数的功能是计算当前点和另外一个点的坐标，使用Demo Point p1 = Point(2.0,3.4); Point p2 = Point(); double dis = p1.distance(p2);
//
///**********************************第一题 --- End******************************************************/
//

/**********************************第二题 ******************************************************/
/**
1、封装一个超级跑车SuperCar类  */
class SuperCar
{
public:

    SuperCar()
    {
        this->speedMax = 0;
    }

    virtual void speedup() = 0;

    virtual ~SuperCar()
    {
        std::cout << "virtual ~SuperCar() \n";
    }
protected:
    int speedMax;


};
 
 
class Car : public SuperCar
{

public:
    Car()
    {

    }

    Car(int spe)
    {
        this->speed = spe;
    }

    virtual void speedup()
    {
        std::cout << "车子飞起来了 ---- \n";
    }

private:

    int speed;


};


class Tractor : public SuperCar
{

public:
    Tractor()
    {

    }

    Tractor(int spe)
    {
        this->speed = spe;
        this->speedMax = spe;
    }

    virtual void speedup()
    {
        std::cout << " Tractor 车子飞起来了 ---- " << this->speed + this->speedMax << std::endl;
    }

private:
    
    int speed;
    
    
};


class Train : public SuperCar
{

public:
    Train()
    {

    }

    Train(int spe)
    {
        this->speedMax = spe;
        this->speed = spe;
    }

    virtual void speedup()
    {
        std::cout << " train 车子飞起来了 ---- " << this->speed + this->speedMax << std::endl;
    }

private:

    int speed;
    
    
};



void speed(SuperCar *sup_Car)
{
    sup_Car->speedup();
}

void test1() //测试多态
{
    SuperCar *s1 = new Car(13) ;
    SuperCar *s2 = new Tractor(17) ;
    SuperCar *s3 = new Train(130) ;


    speed(s1);
    speed(s2);
    speed(s3);


    delete s1;
    delete s2;
    delete s3;

}


/**********************************第二题 End ******************************************************/


/**********************************第三题  ******************************************************/
/**
 3、自己编写并实现一个string类 */


int getStrLen(const char *str)
{
    int len = 0;

    while (*str != '\0')
    {
        len+=1;
        str+=1;
    }

    return len;
}

void copyStr(char *&des ,const char *src)
{
    int len = getStrLen(src);
    for (int i = 0; i < len; i++)
    {
        des[i] = src[i];
    }
}


class MyString
{
public:

    MyString(const char *str = "")
    {
        if (getStrLen(str)!= 0)
        {
            this->m_Str = new char[getStrLen(str) + 1];

            copyStr(this->m_Str, str);
        }
    }

    MyString(const MyString &other)
    {

        this->m_Str = new char[getStrLen(other.m_Str)];
        copyStr(this->m_Str, other.m_Str);
    }

    MyString & operator =(const MyString &other)
    {

        if (this != &other)
        {

            delete [] this->m_Str;
            this->m_Str = NULL;

            this->m_Str = new char[getStrLen(other.m_Str)];
            copyStr(this->m_Str, other.m_Str);

        }

        return *this;
    }

    MyString & operator = (const char * str)
    {

        delete [] this->m_Str;
        this->m_Str = NULL;

        this->m_Str = new char[getStrLen(str)];
        copyStr(this->m_Str,str);

        return *this;
    }


    char & operator[](unsigned int index)
    {
        return this->m_Str[index];
    }



    friend MyString operator+(const MyString &s1 , const MyString &s2);

    //重载>>
    friend std::istream & operator>>(std::istream & is, MyString *other);

    //重载<<
    friend std::ostream & operator<<(std::ostream & os, MyString &other);

    ~MyString()
    {
        if (this->m_Str != nullptr)
        {
            delete this->m_Str;
        }
    }



private:
    char *m_Str;

};




MyString operator+(const MyString &s1 , const MyString &s2)
{

    if (&s1 != &s2)
    {
        int len = getStrLen(s1.m_Str) + getStrLen(s2.m_Str) + 1;
        char *str = new char[len];
        strcpy(str, s1.m_Str);
        strcat(str, s2.m_Str);

        MyString temp = MyString(str);

        delete [] str;

        return temp;
    }
    else
    {

        MyString temp = s1;

        return temp;

    }



}



std::ostream & operator<<(std::ostream & os, MyString &other)
{
    os << "string -- " << other.m_Str << std::endl;
    return os;
}



std::istream & operator>>(std::istream & is, MyString *other)
{


    //清空之前的数据
    delete [] other->m_Str;
    other->m_Str = NULL;

    //创建临时缓冲区
    std::cout << "请输入字符串 --- 字符串不能超过4096个 \n";

    //开辟临时区
    char *temp = (char *)calloc(4096, sizeof(char));

    //从键盘捕获输入
    std::cin >> temp;

    int len = getStrLen(temp) + getStrLen(other->m_Str);

    //重新开辟空间给c->str
    other->m_Str = (char *)calloc(len + 1, sizeof(char));
    strcpy(other->m_Str, temp);

    if (temp != NULL)
    {
        free(temp);
        temp = NULL;
    }
    

    
    return is;
}

/**********************************第三题 End ******************************************************/




int main(int argc, const char * argv[])
{


    using namespace std;
    MyString s1 = MyString("123");

    MyString s2 = MyString("456");

    MyString s3 =  s1 + s2;

    cout << s3 << endl;


    return 0;
}
