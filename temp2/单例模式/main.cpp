//
//  main.cpp
//  单例模式
//
//  Created by Mac on 16/6/10.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <pthread.h>

typedef void (*single)();

void singleModel()
{
    std::cout << "current_Thread -- " << pthread_self() << std::endl;
}

int main(int argc, const char * argv[])
{
    pthread_once_t *pt = new pthread_once_t;

    single s1 = &singleModel;
    pthread_once(pt, s1);


    return 0;
}
