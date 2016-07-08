//
//  main.cpp
//  Conputer
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>


class Memory
{
public:
    std::string brand; //品牌
    double capacity;

    virtual double getStorage() = 0;
    virtual ~Memory()
    {
        std::cout << "Memory is Died -- brand is - " << this->brand << std::endl;
    }

};

class Card
{

public:

    double capacity; //容量
    std::string name;

    virtual ~Card()
    {
        std::cout << "card is Died -- " << std::endl;
    }

    virtual void display() = 0;


};

class Cpu
{

public:
    std::string name;
    double price;
    virtual ~Cpu()
    {
        std::cout << "Cpu died -- name is - " << this->name << std::endl;
    }

    virtual void Caculator() = 0; //能够计算

};

class Conputer
{

public:

    Cpu *cpu;
    Card *card;
    Memory *mem;

    virtual  ~Conputer()
    {
        std::cout << "Conputer - " << std::endl;
    }
};


class Intel:public Cpu
{
public:
    Intel(std::string name, double price)
    {
        this->name = name;
        this->price = price;
        std::cout << "Intel init " << std::endl;
    }

    virtual void Caculator()
    {
        std::cout << "cpu name is " << this->name << std::endl;
        std::cout << "正在计算 ..." << std::endl;
    }

};

class KinstoneCard : public Card
{
public:
    KinstoneCard(std::string name , double cap)
    {
        this->name = name;
        this->capacity = cap;
        std::cout << "KinstoneCard init " << std::endl;
        std::cout << "KinstoneCard cap is  " << this->capacity << std::endl;

    }

    virtual void display()
    {
        std::cout << "display() --- this name is - " << this->name << std::endl;
    }

};

class KinstoneMemory
{

};

int main(int argc, const char * argv[])
{


    return 0;
}
