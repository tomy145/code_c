//
//  main.cpp
//  链表
//
//  Created by Mac on 16/6/2.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>

class Dog
{

public:

    Dog(int w)
    {
        this->weight = w;
    }

    Dog()
    {
        this->weight = 0;
    }

    int weight;

    Dog *next;

};



void printLink(Dog **list)
{
    Dog *temp = *list;

    int i = 0;
    while (temp != nullptr)
    {
        std::cout << "dg.weight -- " << temp->weight << " , i = " << i << std::endl;
        temp = temp->next;
        i++;
        if (temp == NULL)
        {
            break;
        }
    }



}


int main(int argc, const char * argv[])
{

    Dog *list = nullptr;

    for (int i = 0; i < 10; i++)
    {
        Dog *d1 = new Dog(i + 'a');

        if (list == nullptr)
        {
            list = d1;
        }
        else
        {
            Dog *current = list; //先保存初始的
            d1->next = current;
            list = d1;
        }

    }

    printLink(&list);


    return 0;
}
