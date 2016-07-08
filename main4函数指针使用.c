//
//  main4.c
//  temp
//
//  Created by Mac on 16/5/16.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

int add(int a, int b)
{
    printf("%d\n",a+b);
    return a+b;
}

void sum(int a, int b)
{
    printf("a + b = %d\n",a+b);
}

typedef int (*pf)(int,int);
typedef void (*su)(int , int);

struct myStruct
{
    int a;
    int b;
    su s1;

};

void example_one()
{

    // Define a pointer to a function that takes 2 ints.
    int (*ptr)(int,int);
    pf p1 = add;
    // Assign it to 'add'
    ptr = &add;

    su s1 = sum;



    printf("lls--- %d\n",p1(3,4));

    // Call our function pointer
    int result = ptr(32,4);

}

void example_two(){

    /*
     * We can also type-cast function return values
     */

    void (*ptr)(int,int);

    ptr = (void *)&add;

    ptr(32,4);
}

void example_three( int (*callback)(int,int) ){
    // Now lets try callbacks :)
    callback(99,1);
}

// This part is a little tricky, note the '()' within the first expression
int (*example_four_func())(int,int){
    return &add;
}

void example_four(){
    int (*ptr)(int,int);
    ptr = example_four_func();
    ptr(4,3);
}

int main(int argc, char **argv)
{

    printf("Example One: ");
    example_one();

    printf("Example Two: ");
    example_two();

    printf("Example Three: ");
    example_three( &add );
    
    printf("Example Four: ");
    example_four();
    
    return 0;
}
