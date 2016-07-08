//
//  list.c
//  tempo
//
//  Created by Mac on 16/5/12.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include "list.h"


Data *creatList(int n)
{
    Data *list = NULL;
    if (n > 0)
    {
        list = calloc(n, sizeof(Data));
        for (int i = 0; i < n; i++)
        {
            
			if (i + 1 == n)
			{
				list[i].next = NULL;
			}
			else
			{
				list[i].next = &list[i + 1];
			}
        }
    }

	printf("len -- %d\n", n);

    return list;
}

unsigned int getListLength(Data *list)
{
    unsigned int len = 0;

    if (list!= NULL)
    {
        while (list->next != NULL)
        {
            len++;
            list++;
			printf("listadd -- %p --- %lu --- len -- %d\n", list, sizeof(list),len);

        }
    }

    return  len + 1;
}


void insertListToIndex(Data *list , int index , void *data , unsigned int dataSize)
{
    unsigned int len = getListLength(list);
	printf("huoquchangdu -- %d\n",len);
    if (list != NULL && index <= len)
    {
        printf("dataSize -- %d\n",dataSize);
        list[index].data = calloc(1, dataSize); //分配内存
        memcpy(list[index].data, data, dataSize);
        list[index].size = dataSize;
        list[index].index = index;
    }

}

Data * deleteListToIndex(Data *list , int index,unsigned int dataSize)
{
    unsigned int len = getListLength(list) - 1;

    printf("len -- %d\n",len);

    Data *temp2 = creatList(len);

    if (list != NULL)
    {
        for (int i = 0; i < getListLength(list); i++)
        {
            if (i < index)
            {
//                temp2[i] = list[i];
                insertListToIndex(temp2, i, list[i].data, dataSize);
            }
            else if (i == index)
            {

            }
            else
            {
//                temp2[i-1] = list[i+1];
                insertListToIndex(temp2, i-1, list[i+1].data, dataSize);

            }
        }
        
        freeList(list);
    }

    return temp2;
}

void updateListToIndex(Data *list , int index , Data data)
{
    if ((list != NULL) && (index < getListLength(list)))
    {
        list[index] = data;
    }
}

unsigned int selectFromList(Data *list , Data data)
{
    unsigned int index = 0;

    if ((list != NULL) && (index < getListLength(list)))
    {
        for (int i = 0; i < getListLength(list); i++)
        {
            if (list[i].data == data.data)
            {
                index = list[i].index;
                break;
            }
        }
    }

    return index;

}


void freeList(Data *list)
{
    int len = getListLength(list);

    for (int i = 0; i < len;i++)
    {
        if (list[i].data != NULL)
        {
            free(list[i].data);
        }
    }
    free(list);
}



