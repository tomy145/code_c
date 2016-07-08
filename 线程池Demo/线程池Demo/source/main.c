#include <stdio.h>
#include <pthread.h>
#include "thpool.h"


void task1()
{
    printf("Thread #%u working on task1\n", (int)pthread_self());
}


void task2()
{
    printf("Thread #%u working on task2\n", (int)pthread_self());
}

void *(func)(void *t, ...)
{



    return NULL;
}


#define func(s) func1(#s)

#define test(a,b) func1(a##a)

void func1(int a , int b)
{

    printf("sll --- %d --- %d\n",a,b);

}

int main(int argc, const char *argv[])
{

    //    puts("Making threadpool with 4 threads");
//    threadpool thpool = thpool_init(1000);
//
//    puts("Adding 40 tasks to threadpool");
//    int i;
//    for (i=0; i<3; i++)
//    {
//        thpool_add_work(thpool, (void*)task1, NULL);
////        thpool_add_work(thpool, (void*)task2, NULL);
//        
//        printf("i === %d\n",i);
//    };
//
//    puts("Killing threadpool");
//
//
//    thpool_destroy(thpool);

    getchar();

    return 0;
}
