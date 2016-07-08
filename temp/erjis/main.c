#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void print_array(char*  *array,  int len)//char **array = my_array;
//void print_array(char array[][6], int len)
//void print_array(char array[4][6], int len)
void print_array(char (*array)[6], int len)    //array+1== > array + sizeof(char[6])

{
    int i = 0;

    for (i = 0; i < len; i++)
    {
        printf("%s\n", array[i]);
    }

    if (strcmp(array[0], array[1]) > 0)
    {

    }
}


int sort_array(char array[][6], int len)
{
    int i = 0;
    int j = 0;

    char temp_buf[6] = { 0 };


    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                strcpy(temp_buf, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp_buf);
            }
        }
    }


    return 0;
}



int main(int argc, char **argv)
{
    char my_array[4][6] = { "aaa", "ccc", "bbb", "111" };

    int len = 4;
    
    
    print_array(my_array, len);
    
    sort_array(my_array, len);
    printf("----\n");
    
    print_array(my_array, len);
    
    
    return 0;
}