#define  _CRT_SECURE_NO_WARNINGS
#include	<iostream>

using namespace	std;

class	ABC
{
public:
    ABC(int	a, int	b, int	c)
    {
        _a = a;
        _b = b;
        _c = c;
        printf("ABC()	construct,	a:%d,b:%d,c:%d \n", _a, _b, _c);
    }
    ~ABC()
    {
        printf("~ABC()	construct,a:%d,b:%d,c:%d \n", _a, _b, _c);
    }
    int	getA()
    {
        return	_a;
    }
private:
    int	_a;
    int	_b;
    int	_c;
};

class	MyD
{
public:
    MyD() :abc1(1, 2, 3), abc2(4, 5, 6), m(100)
    {
        cout << "MyD()" << endl;
    }
    ~MyD()
    {
        cout << "~MyD()" << endl;
    }

    MyD(const	MyD	&	obj) :abc1(7, 8, 9), abc2(10, 11, 12), m(100)
    {
        printf("MyD(const	MyD	&	obj)\n");
    }

public:
    ABC	abc1;	//c++编译器不知道如何构造abc1
    ABC	abc2;
    const int	m;
};

int	doThing(MyD	myd1)//MyD myd1 = myd;
{
    printf("doThing()	myd1.abc1.a:%d \n", myd1.abc1.getA());

    return 0;
}

int	run()
{
    MyD	Myd;

    doThing(Myd);

    return 0;
}


int	run2()
{
    printf("run2	start..\n");
    //ABC(400, 500, 600);	
    ABC	abc	=	ABC(100,	200,	300);
    printf("run2	end\n");
    
    return 0;
}


int	main(void)
{
    run2();
    
    return 0;
}