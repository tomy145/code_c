
#include <iostream>


using namespace std;

class Base
{
public:

    Base(int i) :baseI(i){};

    virtual void print(void){ cout << "调用了虚函数Base::print()"; }

    virtual void setI(){cout<<"调用了虚函数Base::setI()";}

    virtual ~Base(){}

    int getBaseI()
    {
        return baseI;
    }

private:

    int baseI;
    
};

void test1()
{
    int **p = (int **)new int*[10];

    for (int i = 0; i < 10; i++)
    {
        p[i] = new int[10];

        for (int j = 0; j < 10; j++)
        {
            p[i][j] = j + 2;
        }
    }

    for (int i = 0;i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            cout << "p[i][j] = " << p[i][j] << endl;
        }

        cout << "行--- " << i << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        delete [] p[i];
    }
    
    delete [] p;

}


void test2()
{
    Base *b1 = (Base *)malloc(sizeof(Base));

    cout << "i == " << b1->getBaseI() << endl;

    free(b1);

    Base *b2 = (Base *)new Base(3);

    cout << b2->getBaseI() << endl;

}

class Dog
{

public:


    static int age;
    static void print()
    {
        cout << "print \n" ;
    }

    void printName()
    {
        cout << "name - " << name << endl;
    }


private:
    static string name;


};

int Dog::age = 19;
string Dog::name = "nams";

void test3()
{
    Dog d1;
    cout << d1.age << endl;
    cout << Dog::age << endl;
    Dog::print();

}


class Student
{
public:
    Student(double sc)
    {
        score = sc;
        totalScore += score;
        count +=1;
    }

    static double getAV()
    {
        return totalScore / count;
    }

private:
    double score; //分数
    static int count; //人数
    static double totalScore;


};

int Student::count = 0;
double Student::totalScore = 0.0;

int main(void)
{
    Student st1(94);
    Student st2(84);

    cout << "av -- " << Student::getAV() << endl;;


//    Base b(1000);
//    int * vptrAdree = (int *)(&b);
//    cout << "虚函数指针（vprt）的地址是：\t"<<vptrAdree << endl;



//    typedef void(*Fun)(void);
//    Fun vfunc = (Fun)*((int *)*(int*)(&b));
//
//    cout << "第一个虚函数的地址是：" << (int *)*(int*)(&b) << endl;
//    cout << "通过地址，调用虚函数Base::print()：";
//    vfunc();

}