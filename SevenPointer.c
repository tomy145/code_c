1.	利用随机函数获取十个1-100的整数并打印，然后再反序打印一遍。(通过指针获取下标的值)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void func(int *num)						// 形参 num 接收数组首地址
{
	srand((unsigned int)time(NULL));	// 设置系统时间为随机数种子
	for (int i = 0; i < N; ++i)			// 循环十次
		printf("%d", *(num + i) = rand() % 100 + 1);	// 通过随机函数获取到十个1~100的数组，存到数组里，并打印出来
}

int main(void)
{
	int num[N] = { 0 };			// 定义一个整型数组，十个元素
	int *p = num;				// 定义一个数组指针，指向这个数组
	func(p);					// 将指针(数组首地址)作为函数参数传递给func()
	printf("\n");	
	for (p = num + N - 1; p >= num;--p)	 	// 将指针指向数组的最后一个元素下标，指针每次循环往前移动一位，直到数组首地址位置
		printf("%d ", *p);					// 每次循环，都打印指针当前指向的元素
	printf("\n");							// 换行
	return 0;
}

2.	输入年份和这一年的第N天，计算并打印出这一天是这一年的几月几日。(区分闰年)
#include <stdio.h>

int main(void)
{
	int year, month, days, leapyear;
	char ch;
	do
	{
		int num[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //先定义一个数组保存非闰年的每个月的天数

		printf("Plz input year and days :\n");		// 输入年份和总天数
		scanf("%d,%d", &year, &days);

		leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);	// 判断是否为闰年，如果是闰年，返回 1

		if(leapyear)			// 如果是闰年，将2月的天数改为29天
			*(num + 2) = 29;

		for (month = 1; days > *(num + month); ++month)		// 循环遍历数组里的每个月的天数，然后和(剩余)总天数做比较
			days -= *(num + month);			// 如果(剩余)总天数大于当前月的天数，就自减这个月的天数，然后再做比较

		// days为我们输入的天数，只要days大于第month月的天数，就减去这个月的天数，剩下的天数再和下个月的天数比较
		// 如果依然大于下个月的天数，那么继续减去下个月的天数，直到剩余天数小于或等于第month月的天数
		// 2000,100: 100 - 31 = 69, 69 - 29 = 40, 40 - 31 = 9  ，即 4月9日

		printf("year = %d, month = %d, days = %d\n", year, month, days);

		getchar();		// 接收 之前输入年份和总天数的 回车符
		printf("If you want again, plz input 'Y'(other for quit): ");
		scanf("%c", &ch);		
	} while(ch == 'Y');

	printf("\n\nThank you for using! See you again ^_^\n");
	return 0;
}

3.	利用随机函数获取到所有的小写英文字母，存储到字符数组char ch[26]里，且按字母表顺序打印出来。(a b c d ... z)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 26

void func(char *s)
{
	srand((unsigned int)time(NULL));		// 设定系统时间为随机数种子
	int i = 0;								// 自增量i，初始化为0
	while(i < N)							// 只要i 小于 26，就一直循环获取随机数
	{
		int temp = rand() % N;				// 获取的随机数在 0 ~ 25之间（对应数组0 ~ 25的下标）
		if(*(s + temp) == 0)				// 每次获取一个随机数，就对应到数组里的值，如果值是0，说明没有存储过字母
		{
			*(s + temp) = temp + 'a';		// 那么，就用这个随机数 加上 'a' 的ASCII码，再存储到数组对应的下标里
			//putchar(*(s + temp));
			++i;							// 每次成功存取一个值，i 就自增 1
		}
		// 如果随机数temp是0，那么就加上'a'的ASCII码，在放到数组第0个下标的位置里，
		// 如果随机数temp又是0，那么if条件不成立，重新循环获取随机数，直到获取对应数组下标不为0的随机数
	}
}

int main(void)
{
	char ch[N] = { 0 };
	func(ch);
	printf("\n");
	for(int i = 0; i < N; ++i)		// 循环打印数组里的字符，总共26个
		putchar(*(ch + i));
	printf("\n");
	return 0;
}


4.	将字符串"We Are Family!"，去除空格后打印出来。（WeAreFamily!）
	// We Are Family!
	// WeAreFamily!\0!
#include <stdio.h>

char *delp(char *p)		 		// 用数组指针p来接收字符数组str的首地址
{
	int i =0, j = 0;			// 定义两个自增量，来控制字符串内字符读取位置
	while(*(p + i))				// 循环遍历字符串，直到字符串结尾 '\0'
	{
		if(*(p + i) != ' ')		// 如果数组第i个小标的元素不为' '，则执行下面的语句
			*(p + j++) = *(p + i);	// 数组第i个小标的元素 替换 数组第j个小标的元素，替换成功后，j自增
		++i;					// 不管替换是否成功，i都会自增
	}
	*(p + j) = '\0';			// 遍历到字符串结尾，并全部替换完成后，将字符串的第j个下标的元素置为'\0'，表示字符串到这里结束
	return p;					// 返回指针p，给调用函数main()
}

int main(void)
{
	char str[] = "We Are Family!";				// 定义一个数组类型的字符串，这样就可以修改里面的值了。
	printf("Now, this string is = %s\n", str);	
	printf("After delete spaces = %s\n", delp(str));	// 这里调用指针函数delp();参数是数组首地址,接收返回值并打印字符串
	return 0;
}

5.	输入一个字符串，判断其是否是回文。(回文：即正读和反读都一样，如abcba，abba) 
#include <stdio.h>
#include <string.h>
#define N 20

int func(char *p, int len)
{			// abccba
	for(int i = 0; i < len / 2; ++i)			// 所以只要循环字符串长度的一半足矣
		if(*(p + i) != *(p + len - i - 1))		// 比较字符串第一个和最后一个字符， -1是防止比较'\0'
			return 0;							// 一旦字符不相等，就返回0
	return 1;									// 直到循环结束都没有返回0，说明字符串是回文，就返回1
}

int main(void)								// 普通版本
{
	char str[N] = { 0 };					// 定义一个数组类型的字符串
	printf("Plz input a string : ");
	gets(str);								// gets()接收字符串

	if(func(str, strlen(str)))				// 将字符串首地址和字符串长度当做参数传递给func()函数
		printf("Yes! %s is huiwen!\n", str);		// 并根据返回值来选择输出结果
	else
		printf("Noo! %s is not huiwen!\n", str);	
	return 0;
}

int main2(int argc, char *argv[])			// main()命令行参数版本
{
	printf("%d\n", argc);
	if(func(argv[1], strlen(argv[1])))
		printf("Yes! %s is huiwen!\n", argv[1]);
	else
		printf("Noo! %s is not huiwen!\n", argv[1]);
	return 0;
}

6.	输入一段字符串，无论是否有重复元素出现，都只打印一次出现过的大写字母和小写字母，且按字母表顺序打印。（如输入AaAa!<-11->!zZzZ， 打印A Z a z）

#include <stdio.h>
#define N 100

void func(char *str, char *temp)		// 获取两个数组的首地址
{
	for (int i = 0; *(str + i) != '\0'; ++i) // 循环遍历str里的字符，直到字符串结尾
		if(*(str + i) >= 'A' && *(str + i) <= 'Z' || *(str + i) >= 'a' && *(str + i) <= 'z')
		// 如果字符是在A 到 Z 之间，或者 a 到 z 之间，
			*(temp + (*(str + i) - 65)) = *(str + i);
			// 就把这个字符和大写字母A的ASCII码差值，对应到temp里的下标，同时在把这个字符存储进去
}
int main(void)
{
	char str[N] = { 0 };		// 定义一个数组类型的字符串，接收用户输入的字符串
	int n = 'z' - 'A' + 1;		// 获取大写字母A到小写字母z的范围，尽可能减少数组的大小，减少内存消耗
	char temp[n] = { 0 };		// 存储需要打印的大写字母和小写字母

	printf("Plz input a string: \n");	
	gets(str);					// gets()获取一个字符串
	func(str, temp);			// 把两个字符串的首地址当做参数传递给函数func()
	for(int i = 0; i < n; ++i)	// 循环打印temp数组里的字符
		if(*(temp + i))			// 如果temp的第i个小标里有值 （之前是初始化为0的）
			putchar(*(temp + i));	// 就打印这个下标的值
	printf("\n");
	return 0;
}

7.	输入一个用空格分隔的字符串，通过程序计算出最长的那段字符串占多少位。（如输入 1234 12345 123 12，最后得出5）
#include <stdio.h>
#define N 30

int func(char *str)		// 字符指针str指向数组首地址
{
	int max = 0, temp = 0;		// 定义两个变量，max存储最长的子串长度，temp存储每遍历一个子串长度
	while(*str++)			// 循环遍历字符串，直到字符串结尾'\0'为止
	{
		if(*str != ' ')		// 如果当前字符不是空格，就让temp一直自增，
			temp++;
		else				// 如果当前字符是空格，就把temp的值和max的值做比较，
		{
			if(temp > max)	// 如果temp 大于 max，就替换掉max
				max = temp;
			temp = 0;		// 然后把temp重置为0，参与下一个子串的长度统计，直到字符串结尾
		}
	}
	return temp > max ? temp : max;	// 最后判断temp和max的值，返回最大的那个，就是最长的子串长度
}

int main(void)
{
	char str[N] = { 0 };			// 定义一个数组类型的字符串
	printf("Plz input a string: ");
	gets(str);						// 通过gets() 获取用户输入的字符串
	printf("The long strings word have %d letter! \n", func(str));	// 将字符串首地址当做参数传递给func()函数
	return 0;
}
