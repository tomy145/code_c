#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    unsigned char sex; //性别
    int id; //学生编号
    int score; //学生分数
    char name[20];//学生名字

}Student;

void inputInfo(Student (*s)[],int count)
{
    char temp[20] = {0};
    for(int i = 0; i < count; i++)
    {
        printf("请输入学生的相关信息，学生性别，学生编号，学生分数，学生名字\n");
        scanf("%c", &((*s)[i]).sex);
        scanf("%d",&((*s)[i]).id);
        scanf("%d",&((*s)[i]).score);
        getchar();
        char *p =  fgets( temp,sizeof((*s)[i].name),stdin);
        temp[strlen(temp) - 1] = '\0';//去除'\n'
        strcpy((*s)[i].name,temp);
    }

}

void printStudents(Student *stus,int count)
{
    for (int j = 0; j < count ; j++)
    {
        printf("第%d位学生的信息: 学生姓名--- %s , 学生编号 --- %d,学生分数 -- %d,学生性别 --- %c\n",j,stus[j].name,stus[j].id,stus[j].score,stus[j].sex);
    }
}

void writeToDisk(Student *stu, int count)
{
    FILE *fp;
    fp = fopen("stu.txt","r+");
    size_t si;
    if(fp != NULL) //文件存在
    {
        //直接写入文件
        //先创建FP，在写入
        fp = fopen("stu.txt","r+");
        //直接写入文件
        si = fwrite(stu,sizeof(Student),count,fp); //第一种方式实现
        //第二种方式实现--------------------------------------------------
        /*
        int i = 0;
        for(i = 0; i < count; i++)
        {
            si = fprintf(fp,"%s\t %d\t %d\t %d\t\n",stu[i].name,stu[i].id,stu[i].sex,stu[i].score);
        }
        */
       
    }
    else
    {
        //先创建FP，在写入
        fp = fopen("stu.txt","w");
        //直接写入文件
        
        si = fwrite(stu,sizeof(Student),count,fp); //第一种方式实现
       
        //第二种方式实现--------------------------------
        /*
        int i = 0;
        for(i = 0; i < count; i++)
        {
            si = fprintf(fp,"%s\t %d\t %d\t %d\t\n",stu[i].name,stu[i].id,stu[i].sex,stu[i].score);
        }
        */
        
    }

    if(si != EOF)
    {
        printf("写入成功...\n");
    }
    else
    {
        printf("写入失败...\n");
    }

    fclose(fp);
}

Student * readStudent(const char *fileDir,int count)
{
    
}

int main(int argv, const char *argc[])
{
    Student stus[5];
    Student stu[1];
    inputInfo(&stus,1);//录入五位学生成绩
    printStudents(stus,1);//打印五位学生成绩信息
    writeToDisk(stus,1);//写入到磁盘里面
    stu = readStudent();
    getchar();//等待

    

    return 0;
}

