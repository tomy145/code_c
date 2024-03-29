//
//  main.c
//  delegate
//
//  Created by Mac on 16/5/21.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_Person Person;
typedef struct _tag_Dog Dog;
typedef void (*Make)(Person *);
typedef void (*Play)(void *) ;
typedef void (*goToDie)(void *);


/**
 *  定义一个Dog的结构体
 */
 struct _tag_Dog
{
    Person *owner; //主人
    char hairColor[40];//狗的毛色
    Make run; //遛狗
    char name[40]; //狗的名字
    goToDie die;//自杀方法(函数),相当于C++里面的析构函数

};


/**
 *  定义一个 人的结构体
 */
struct _tag_Person
{
    char name[30]; //人的名字
    Dog *myDog; //宠物狗
    Play play; //玩方法（函数）
    goToDie die; //自杀方法(函数)

};

/**
 *  释放内存操作
 *
 *  @param p 对象的内存
 */
void die(void *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

/**
 *  狗 在 跑
 *
 *  @param person 谁的狗
 */
void run(Person *person)
{
    printf("self.name --- %s\n",person->name);
    printf("dog_name -- %s\n",person->myDog->name);
    printf("能和主人一起玩，我好开心 - --- %s-- >_<\n",person->myDog->name);

}


/**
 *  去花园游玩
 *
 *  @param p 对象，谁去花园玩
 */
void playToGarden(void *p)
{
    printf("遛狗去咯!!!!! --- \n");

    Person *per1 = (Person *)p;

    printf("我家的狗狗叫--- %s --- 毛色是--- %s \n",per1->myDog->name,per1->myDog->hairColor);

    per1->myDog->run(per1);

    printf("遛狗完毕 --- 好累啊，回家洗澡去咯!\n");

}

/**
    初始化 ， 面向对象都有这种方法
 */
 void *init(unsigned int size)
{
    return calloc(1, size);
}


/*
 
 面向对象程序设计（英语：Object-oriented programming，缩写：OOP）是种具有对象概念的程序编程范型，同时也是一种程序开发的方法。它可能包含数据、属性、代码与方法。对象则指的是类的实例。它将对象作为程序的基本单元，将程序和数据封装其中，以提高软件的重用性、灵活性和扩展性，对象里的程序可以访问及经常修改对象相关连的数据。在面向对象程序编程里，计算机程序会被设计成彼此相关的对象[1][2]。

 面向对象程序设计可以看作一种在程序中包含各种独立而又互相调用的对象的思想，这与传统的思想刚好相反：传统的程序设计主张将程序看作一系列函数的集合，或者直接就是一系列对电脑下达的指令。面向对象程序设计中的每一个对象都应该能够接受数据、处理数据并将数据传达给其它对象，因此它们都可以被看作一个小型的“机器”，即对象。目前已经被证实的是，面向对象程序设计推广了程序的灵活性和可维护性，并且在大型项目设计中广为应用。此外，支持者声称面向对象程序设计要比以往的做法更加便于学习，因为它能够让人们更简单地设计并维护程序，使得程序更加便于分析、设计、理解。反对者在某些领域对此予以否认。

 当我们提到面向对象的时候，它不仅指一种程序设计方法。它更多意义上是一种程序开发方式。在这一方面，我们必须了解更多关于面向对象系统分析和面向对象设计（Object Oriented Design，简称OOD）方面的知识。许多流行的编程语言是面向对象的,它们的风格就是会透由对象来创出实例。重要的面向对象编程语言包含Common Lisp、Python、C++、Objective-C、Smalltalk、Delphi、Java、Swift、C#、Perl、Ruby 与 PHP.
 
    
 特征[编辑]
 面向对象程序编程的定义是使用“对象”来做设计，但并非所有的编程语言都直接支持“面向对象程序编程”相关技术与结构。对于OOP的准确定义及其本意存在着不少争论。通常，OOP被理解为一种将程序分解为封装数据及相关操作的模块而进行的编程方式。有别于其它编程方式，OOP中的与某数据类型相关的一系列操作都被有机地封装到该数据类型当中，而非散放于其外，因而OOP中的数据类型不仅有着状态，还有着相关的行为。

 OOP理论，及与之同名的OOP实践相结合创造出了新的一个编程架构；OOP思想被广泛认为是非常有用的，以致一套新的编程范型被创造了出来。（其它的编程范型例如函数式编程或过程式编程专注于程序运行的过程，而逻辑编程专注于引发程序代码执行的断言）。对面向模拟系统的语言（如：SIMULA 67）的研究及对高可靠性系统架构（如：高性能操作系统和CPU的架构）的研究最终导致了OOP的诞生。其中由Deborah J. Armstrong进行的长达40年之久的计算机著作调查中，显示出了一系列面向对象程序设计的基本理论。面向对象程序特征被条列如下[3][4][5][6]
 
 
 类与对象[编辑]
 支持面向对象编程语言通常利用继承其他类达到代码重用和可扩展性的特性。而类有两个主要的概念：

 类（Class）：定义了一件事物的抽象特点。类的定义包含了数据的形式以及对数据的操作。
 对象：是类的实例。
 其中类别（Class）定义了一件事物的抽象特点。类的定义包含了数据的形式以及对数据的操作。举例来说，“狗”这个类会包含狗的一切基础特征，即所有“狗”都共有的特征或行为，例如它的孕育、毛皮颜色和吠叫的能力。类可以为程序提供模版和结构。一个类的方法和属性被称为“成员”。 我们来看一段伪代码：

     类 狗
     开始
     公有成员:
     吠叫():
     私有成员:
     毛皮颜色:
     孕育:
     结束

 在这串代码中，我们声明了一个类，这个类具有一些狗的基本特征。关于公有成员和私有成员，请参见下面的继承性一节。

 对象（Object）是类的实例。对象有时会对应到现实世界中的事物，举例来说，一个图形程序可能有圆形、矩形与画面等对象，一个在线购物系统可能有购物车、顾客与产品等类。[7]。有时对象会表示更抽象的实体，比如一个被打开的文件或是一个提供美国惯用量测转换的服务。每个对象就是一个特定类的实例（例如，名称是“玛丽”的对象可能是类雇员的一个实例）。程序在面向对象编程当中被视为方法，变量被视为成员或属性。例如，“狗”这个类列举狗的特点，从而使这个类定义了世界上所有的狗。而莱丝这个对象则是一条具体的狗，它的属性也是具体的。狗有皮毛颜色，而莱丝的皮毛颜色是棕白色的。因此，莱丝就是狗这个类的一个实例。一个具体对象属性的值被称作它的“状态”。（系统给对象分配内存空间，而不会给类分配内存空间。这很好理解，类是抽象的系统不可能给抽象的东西分配空间，而对象则是具体的。）

 假设我们已经在上面定义了狗这个类，我们就可以用这个类来定义对象：
     定义莱丝是狗
     莱丝.毛皮颜色:棕白色
     莱丝.吠叫()

 我们无法让狗这个类去吠叫，但是我们可以让对象“莱丝”去吠叫，正如狗可以吠叫，但没有具体的狗就无法吠叫。

 类和对象就好比是“实型”和“1.23”，“实型”是一种数据的类型，而“1.23”是一个真正的“实数”（即对象）。所有的“实数”都具有“实型”所描诉的特征，如“实数的大小”，系统则分配内存给“实数”存储具体的数值。

 */


int main(int argc, const char * argv[])
{

    //创建一个人的对象，为其分配内存，初始化为0
    Person *p1 = init((unsigned int)sizeof(Person));

    //拷贝姓名
    const char *name = "张三";
    strcpy(p1->name, name);

    //取函数首地址(可以把die 看成int)
    p1->die = die;

    //创建一个Dog对象 ， 为其分配sizeof(Dog) 大小的内存，初始化为0
    Dog *red_Dog = init(sizeof(Dog));

    //初始化Dog的颜色
    const char *color = "红色";
    strcpy(red_Dog->hairColor, color);

    //拷贝Dog的姓名
    const char *dg_name = "哈士奇";
    strcpy(red_Dog->name, dg_name);

    //取函数首地址
    red_Dog->die = die;

    //red_dog  的 主人是 p1;
    red_Dog->owner = p1;

    //取函数首地址
    red_Dog->run = run;

    //p1 的狗 是 red_dog
    p1->myDog = red_Dog;

    //取函数首地址
    p1->play = playToGarden;


    //人去玩
    p1->play(p1);

    //狗去跑
    red_Dog->run(red_Dog->owner);

    printf("-----------------人遛狗完毕---------------------\n");
    printf("----------------------------------------------\n");
    printf("---------------------------------------------\n");

    printf("狗狗命运开始终结---\n");
    printf("阎王爷也在催张三了，赶紧去投胎吧!\n");
    //不想玩了，肯定要死亡的，自杀身亡(哈哈，太残忍了,没办法啊,哥们，阎王爷要收你了，不能违抗啊)
    red_Dog->die(red_Dog); //释放内存
    p1->die(p1);//释放内存

    printf("程序结束 --- \n");
    getchar();


    return 0;
}
