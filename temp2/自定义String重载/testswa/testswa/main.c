//
//  main.c
//  testswa
//
//  Created by Mac on 16/6/3.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    printf("start --- %s\n",__TIME__);

    for (int i = 0; i < 100000; i++)
    {
        printf("i = %d --- time --- %s \n",i,__TIME__);
    }

    printf("end ---- %s\n",__TIME__);

    return 0;
}
