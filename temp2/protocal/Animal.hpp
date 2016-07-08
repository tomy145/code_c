//
//  Animal.hpp
//  temp2
//
//  Created by Mac on 16/6/4.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>

class Animal
{

public:
    virtual void voice() = 0;
    virtual void run() = 0;

   virtual ~ Animal();

};

#endif
