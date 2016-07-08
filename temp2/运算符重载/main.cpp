#include <iostream>

using namespace std;


class Complex
{
public:

    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void printC()
    {
        cout << "(" << this->a << "+" << this->b << "i" << ")"<<endl;//(1+2i)
    }

    Complex AddComplex(Complex &another)
    {
        Complex temp(this->a + another.a, this->b + another.b);

        return temp;
    }

    Complex operator+(Complex &another)
    {
        Complex temp(this->a + another.a, this->b + another.b);

        return temp;
    }

    friend Complex AddComplex(Complex&c1, Complex &c2);
    //friend Complex operator+(Complex &c1, Complex &c2);

private:
    int a;//实数
    int b;//虚数
};

//全局

Complex AddComplex(Complex&c1, Complex &c2)
{
    Complex temp(c1.a + c2.a, c1.b + c2.b);

    return temp;
}

//operator 操作符重载的关键字
#if 0
Complex operator+(Complex &c1, Complex &c2)
{
    Complex temp(c1.a + c2.a, c1.b + c2.b);

    return temp;
}
#endif


class Student
{
public:

    Student(int age, int score)
    {
        this->age = age;
        this->score = score;
    }
    Student()
    {
        cout << "默认构造函数 --- " << endl;
    }

    Student  operator+(const Student &stu)
    {
        Student st1 = Student(this->age + stu.age , this->score + stu.score);

        return st1;
    }

    void print()
    {
        cout << "this -> age = " << this->age << endl;
        cout << "this -> score = " << this->score << endl;

    }

private:
    int age;
    int score;


};


int main(void)
{
//    Complex c1(1, 2);
//    Complex c2(2, 3);
//
//
//    //Complex c3 = AddComplex(c1, c2);
//    //Complex c3 = c1.AddComplex(c2);
//    //Complex c3 = operator+(c1, c2); 调用全局的方式
//    //Complex c3 = c1.operator+(c2); 调用成员的方式
//    Complex c3 = c1 + c2;
//    
//    c3.printC();

    Student st1 = Student(19, 83);
    Student st2 = Student(23, 94);

    Student st3 = st1 + st2;

    st3.print();
    
    return 0;
}