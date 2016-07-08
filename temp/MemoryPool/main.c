//
//  main.c
//  MemoryPool
//
//  Created by Mac on 16/5/21.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_MemoryPoolObject MemoryPoolObject; //缓存池
typedef void freeMemory(MemoryPoolObject *pool);
typedef int (*IsOverflow)(MemoryPoolObject *pool);

//定义一个缓存池结构体
struct _tag_MemoryPoolObject
{
    unsigned int poolCount; //缓存池数量
    void **pool;  //缓存池
    unsigned int total; //缓存池总共装了多少个万能指针

    freeMemory *freePool; //释放内存方法(函数)

};


/**
 *  释放缓存池
 *
 *  @param memoryPool 缓存池结构体
 */
void freeMemoryPool(MemoryPoolObject *memoryPool)
{
    int num = 0;

    if (memoryPool->pool != NULL && memoryPool->poolCount > 0 && memoryPool != NULL)
    {
        for (int i = 0; i < memoryPool->poolCount; i++)
        {
            if (memoryPool->pool[i] != NULL)
            {
                num += 1;
                free(memoryPool->pool[i]);
            }
        }

        free(memoryPool->pool);
        free(memoryPool);
        num +=1;

    }

    printf("释放次数--- %d\n",num);
}

/**
 *  检查缓存池是否已满
 *
 *  @param pool 缓存池
 *
 *  @return 1 代表已满，需要重新扩容，否则表示还未满，不需要开辟内存
 */
int checkMemoryIsOverflow(MemoryPoolObject *pool)
{
    int ret = -1;
    if (pool->total >= pool->poolCount)
    {
        ret = 1;
    }

    return ret;
}

/**
 *  扩充缓存池容量
 *
 *  @param pool 缓存池
 */
void enlargeMemoryPool(MemoryPoolObject *pool)
{
    if (checkMemoryIsOverflow(pool) == 1 && pool != NULL)
    {
        pool->poolCount *= 2;//扩充一倍
        pool->pool = realloc(pool->pool, pool->poolCount);
    }
}







int main(int argc, const char * argv[])
{




    return 0;
}
