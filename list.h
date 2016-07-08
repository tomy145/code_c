//
//  list.h
//  tempo
//
//  Created by Mac on 16/5/12.
//  Copyright © 2016年 Mac. All rights reserved.
//

#ifndef list_h
#define list_h

struct  Data
{
    void *data;
    unsigned int size;
    unsigned int index;
    struct Data *next;

};

typedef struct Data Data;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Data *creatList(int len);

unsigned int getListLength(Data *list);

void insertListToIndex(Data *list , int index , void *data , unsigned int dataSize);

Data * deleteListToIndex(Data *list , int index,unsigned int dataSize);

void updateListToIndex(Data *list , int index , Data data);

unsigned int selectFromList(Data *list , Data data);

void freeList(Data *List);

#endif
