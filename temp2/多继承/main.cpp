#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//床类
class Bed
{
public:
    Bed(int b)
    {
        this->b = b;
    }
    void sleep() {
        cout << "在床上睡觉" << endl;
    }
private:
    int b;
};

//沙发类
class Sofa
{
public:
    Sofa(int s)
    {
        this->s = s;
    }
    void sit()
    {
        cout << " 在 沙发坐下" << endl;
    }
private:
    int s;
};



//沙发床
class SofaBed : public Sofa , public Bed
{
public:
    SofaBed(int s, int b) :Bed(b), Sofa(s) {

    }
    void sleep_and_sit() {
        sleep();
        sit();
    }
};


class Animal
{

public:
    Animal(int age)
    {
        this->age = age;
    }

    Animal()
    {
        this->age = 0;
    }


    ~Animal()
    {

        std::cout << "Animal died --- " << typeid(this).name() << std::endl;

    }

   virtual void growth()
    {
        std::cout << " Animal growth " << std::endl;
    }

private:

    int age;

};


class Person:public Animal
{

public:
    Person(int idNum,int age):Animal(age)
    {
        this->idNumber = idNum;
    }

    Person()
    {
        this->idNumber = 0;
    }


    void growth()
    {
        std::cout << "Person growth " << std::endl;
    }

private:
    int idNumber;

};


class Student:public Animal, public Person
{
public:
    Student(int age , int idNu):Animal(age),Person(age,idNu)
    {

    }
private:


};

void test1()
{
    Bed b(10);
    b.sleep();

    Sofa s(20);
    s.sit();

    SofaBed sb(10,20);
    sb.sleep_and_sit();

}


void make(Animal *ani)
{
    ani->growth();
}


int main(void)
{


    //多态形成的三个条件
    //1、父类，和子类 必须有相同的，方法
    //2、传递参数，必须要使用父类的指针接收
    //3、父类中的方法必须使用Virtual 修饰该函数


    Animal *ani = new Animal(13);


    Person *p1 = new Person(1273,18);

    make(p1);

    make(ani);


    return 0;
}