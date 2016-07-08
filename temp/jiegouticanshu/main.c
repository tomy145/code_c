
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void freem(void *p)
{
    if (p != NULL)
    {
        free(p);
    }
}

typedef void (* fre)(void *);

struct teacher
{
    int id;
    char name[60];
    char *words;
    fre freeMemo;
};



void print_struct(struct teacher t1)
{

    const char *t = "zhangsan";
    strcpy(t1.name,t);
    t1.id = 29;

    printf("t1.name -- %s --- t1.id --- %d\n",t1.name , t1.id);

};

void creat_teacher(struct teacher **p, int len)
{
    struct teacher *temp = *p;

    temp = (struct teacher *)calloc(len, sizeof(struct teacher));

  for (int i = 0; i < len; i++)
  {
      temp[i].words = calloc(10, sizeof(char));
      temp[i].id = i + len ;
      strcpy(temp[i].name, "slpe");
      strcpy(temp[i].words, "oo");
      temp[i].freeMemo = freem;
      printf("tempss --- %p\n",temp[i].freeMemo);
  }

    *p = temp;

}

void copy_teacher(struct teacher *to , struct teacher *from)
{
    *to = *from;
}

void test2(void)
{
    char *p = calloc(100, sizeof(char));
    char *p2 = calloc(4096, 1);

    fre fp1 = freem;
    fp1(p);

    fre fp2 = freem;
    fp2(p2);


    struct teacher *t1 = NULL;

    creat_teacher(&t1,10);

    for (int i = 0; i < 10; ++i)
    {
        printf("t1.name --- %s --- id --- %d --- words --- %s\n",t1[i].name,t1[i].id,t1[i].words);
    }

    for (int i = 0; i < 10; i++)
    {
        void *p = t1[i].words;
        t1[i].freeMemo(p);
        printf("psl --- %p\n",t1[i].freeMemo);
    }
    
    free(t1);

}

typedef  struct _tag_Manager Manager ;

typedef void (*freeMan)(Manager *man);


struct _tag_Manager
{
    unsigned long idNumber;
    char *name;
    unsigned int workerNumer;
    char **workers;
    freeMan freeAManager;

};

void freeManager(Manager *man)
{

    if (man->name != NULL && man->workers != NULL)
    {
        free(man->name);

        for (int i = 0; i < man->workerNumer; i++)
        {
            free(man->workers[i]);
        }
        free(man->workers);
    }
}


void test3()
{
    Manager *managers = NULL;
    managers = calloc(2, sizeof(Manager));

    int len = 2;

    for (int i = 0; i < len; i++)
    {
        Manager man;
        man.idNumber = i + 'z';
        man.name = calloc(60, sizeof(char));
        strcpy(man.name, "zhangsan");
        man.workerNumer = 2;
        man.workers = calloc(2, sizeof(char *)); //先开辟数组
        for (int j = 0; j < man.workerNumer; j++)
        {
            man.workers[j] = calloc(100, sizeof(char)); //数组里面的数据长度
            strcpy(man.workers[j], "赵六");
        }

        man.freeAManager = freeManager;

        managers[i] = man;

    }

    for (int i = 0; i < len; i++)
    {
        printf("id --- %lu --- name --- %s -- wokernumber -- %d\n",managers[i].idNumber,managers[i].name,managers[i].workerNumer);

        for (int j = 0; j < managers[i].workerNumer; j++)
        {
            printf("wokerName --- %s\n",managers[i].workers[j]);
        }
    }

    for (int i = 0; i < len; i++)
    {
        Manager man = managers[i];
        man.freeAManager(&man);
    }
    
    
    free(managers);

}


typedef struct _tag_MemoryPoolObject MemoryPoolObject; //缓存池

typedef void freeMemory(MemoryPoolObject *pool);

struct _tag_MemoryPoolObject
{
    unsigned int poolCount; //缓存池数量
    void **pool;
    unsigned int total;
    freeMemory *freePool;

    
};

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


void test4()
{

    //缓存池
    MemoryPoolObject *memoryPool = NULL;
    memoryPool = calloc(1, sizeof(MemoryPoolObject));

    memoryPool->freePool = freeMemoryPool;

    memoryPool->poolCount = 300;
    memoryPool->pool = calloc(memoryPool->poolCount, sizeof(memoryPool->pool));


    Manager *managers = NULL;
    managers = calloc(2, sizeof(Manager));

    memoryPool->pool[0] = managers; //存储一个
    memoryPool->total +=1;


    int len = 2;

    for (int i = 0; i < len; i++)
    {
        Manager man;
        man.idNumber = i + 'z';
        man.name = calloc(60, sizeof(char));

        memoryPool->pool[memoryPool->total + i] = man.name; //循环存储
        memoryPool->total +=1;

        strcpy(man.name, "zhangsan");
        man.workerNumer = 2;
        man.workers = calloc(2, sizeof(char *)); //先开辟数组

        memoryPool->pool[memoryPool->total + i] = man.workers; //循环存储
        memoryPool->total +=1;

        for (int j = 0; j < man.workerNumer; j++)
        {
            man.workers[j] = calloc(100, sizeof(char)); //数组里面的数据长度
            strcpy(man.workers[j], "赵六");
            memoryPool->pool[memoryPool->total + j] = man.workers[j]; //循环存储
            memoryPool->total +=1;

        }

        managers[i] = man;

    }

    for (int i = 0; i < len; i++)
    {
        printf("id --- %lu --- name --- %s -- wokernumber -- %d\n",managers[i].idNumber,managers[i].name,managers[i].workerNumer);

        for (int j = 0; j < managers[i].workerNumer; j++)
        {
            printf("wokerName --- %s\n",managers[i].workers[j]);
        }
    }


    //两层释放
    memoryPool->freePool(memoryPool);
    free(memoryPool);

}



struct{
    short a1;
    short a2;
    short a3;
}A;
struct{
    long a1;
    short a2;
}B;


int main(void)
{


    printf("size --- %lu --- %lu\n",sizeof(A),sizeof(B));

    return 0 ;
}