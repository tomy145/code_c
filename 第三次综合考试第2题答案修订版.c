
//二、	使用结构体嵌套，存储学生的学号和姓名，以及每个学生的C、MySQL和Python的成绩。要求：允许从键盘输入任意数量的学生，以及学生的学号、姓名和各学科成绩，最后只打印出总成绩最高的学生信息以及其各学科成绩。

#include <stdio.h>
#include <stdlib.h>
struct Score 				// 保存成绩的结构体
{
	float c;				// C语言的
	float mysql;			// MySQL的
	float python;			// Python的
};

typedef struct 				// 利用typedef 别名了一个学生信息的结构体
{
	char name[20]; 			// 存储姓名
	char id[20];			// 存储学号
	struct Score ss; 		// 结构体嵌套了一个Score结构体
} Student; 					// typedef 后的别名, 这个别名在任何地方都能代替这个结构体

int main(void)
{
	int n;			// n 是学员数量
	printf("Plz input how many student: ");
	scanf("%d", &n);

	// 不能直接定义n个元素的指针数组 Student *stu[n]; 数组里的 n 必须是常量值
	Student **stu = (Student **)calloc(n,sizeof(Student*)); 
	// 定义了一个Student**类型的二级结构体指针变量，指向 有n个一级结构体指针大小的 堆空间，这个堆空间存储了 指向所有学员信息的 堆空间指针

	Student *maxStu;	// 定义了一个Student*类型的结构体指针变量，指向存储量最高成绩的学员信息的堆空间地址

	float score = 0;			// 存储当前学生的成绩
	float maxScore = 0;			// 存储最高学生的成绩

	// 循环接受学员的信息，总共n个
	for(int i = 0; i < n; ++i)
	{
		//stu[i] = (Student *)malloc(sizeof(Student));	// 这两行意思一样
		*(stu + i) = (Student *)malloc(sizeof(Student)); // 每个一个指针都指向一个申请的堆空间，用来存储学员信息

		printf("输入第%d位学生的姓名：\n", i + 1);
		scanf("%s", stu[i]->name);

		printf("输入第%d位学生的学号：\n", i + 1);
		scanf("%s", stu[i]->id);

		printf("输入第%d位学生的C语言成绩：\n", i + 1);
		scanf("%f", &stu[i]->ss.c);

		printf("输入第%d位学生的MySQL成绩：\n", i + 1);
		scanf("%f", &stu[i]->ss.mysql);

		printf("输入第%d位学生的Python成绩：\n", i + 1);
		scanf("%f", &stu[i]->ss.python);

		score = stu[i]->ss.c + stu[i]->ss.mysql + stu[i]->ss.python;  // 存储当前学员的所有成绩总和

		if (maxScore < score) 								// 与之前的最高学员成绩进行比较，如果大于之前最高的
		{
			maxScore = score;								// 替换最高成绩 maxScore
			maxStu = stu[i];								// 指针也进行替换，指向了最高的学员
		}
	}

	printf
	(
			"\
		\n 总成绩最高的分数是：%.2f\n \
		姓名：%s \n \
		学号：%s \n \
		C语言成绩：%.2f \n \
		MySQL成绩：%.2f \n \
		Python成绩：%.2f \n",
			maxScore,
			maxStu->name,
			maxStu->id,
			maxStu->ss.c,
			maxStu->ss.mysql,
			maxStu->ss.python
	);

	for (int i = 0; i < n; ++i)		// 循环释放二级指针stu 里每个一级指针的堆空间 循环
		free(*(stu + i));

	free(stu);				// 最后释放二级指针stu
//	free(maxStu); 			// maxStu并没有分配堆空间，只是指向了某个stu[i]指向的堆空间，所以不需要进行重复释放

	return 0;
}
