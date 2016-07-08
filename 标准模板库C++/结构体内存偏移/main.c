



#include <stdio.h>
#include <string.h>
#include <stdlib.h>






typedef struct tag_test
{
    int value;
    char name[100];
}Test;



typedef struct _tag_value
{
    Test d;
    int a;
    short b;
    char c[12];
}value;




int main()
{
    value v;
    //初始化
    v.a = 100;
    v.b = 25;
    strcpy(v.c, "Hello C++");
    v.d.value = 50;
    strcpy(v.d.name, "你们好,传智播客,C++学院!");

    //打印数据 == Test
    Test* t = (Test*)&v;
    printf("t.value = %d, t.name = %s\n", t->value, t->name);

    //打印数据 == v.a
    int va = *((int*)(((char*)&v) + sizeof(Test)));
    printf("va = %d\n", va);

    //打印数据 == v.b
    short vb = *((short*)(((char*)&v) + sizeof(Test)+sizeof(int)));
    printf("vb = %d\n", vb);

    //打印数据 == v.c
    char* vc = ((char*)&v) + sizeof(Test)+sizeof(int)+sizeof(short);
    printf("vc = %s\n", vc);

    printf ("Keyboard not found, press F1 to continue...   \n");



    return 0;
}
