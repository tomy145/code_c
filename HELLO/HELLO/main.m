//
//  main.m
//  HELLO
//
//  Created by Mac on 16/5/16.
//  Copyright © 2016年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        NSObject *op1 = [[NSObject alloc] init];

        Person *p1 = [[Person alloc] init];
        p1.name =  @"张三";


        NSLog(@"ops -- size %lu\n",sizeof(p1));

        NSLog(@"Hello, World!");

        sleep(3);

    }
    return 0;
}
