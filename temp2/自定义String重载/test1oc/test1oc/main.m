//
//  main.m
//  test1oc
//
//  Created by Mac on 16/6/3.
//  Copyright © 2016年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {


    NSLog(@"start --- ");

    for (int i = 0; i < 100000; i++)
    {
        NSLog(@"i = %d" , i);
    }

    NSLog(@"end ----");


//    16:06:40.201  4654毫秒
//    16:06:35.547

    return 0;
}
