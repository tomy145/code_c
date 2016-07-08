#include <iostream>
#include <vector>
// 算法函数需要引用的三个头文件
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;


void print(vector<int> &v)
{
	// 迭代器
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	// 用遍历数组的方式
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}



// 构造函数
void test1()
{
	// 内存空间是连续的
	vector<int> v;	// 默认构造, 容器为空

	// 迭代器为随机访问迭代器
	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v1(array, array+5);	// 区间 [beg, end)
	vector<int> v2(v1.begin()+2, v1.begin()+4);
	vector<int> v3(10);	// 容器中有10个元素, 默认值为0
	vector<int> v4(10, 6);	// 容器中10个元素, 默认值6

	print(v);
	print(v1);
	print(v2);
	print(v3);
	print(v4);

}

// 大小
void test2()
{
	// 内存空间是连续的
	vector<int> v;	// 默认构造, 容器为空

	// 迭代器为随机访问迭代器
	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v1(array, array + 5);	// 区间 [beg, end)
	
	if (v.empty())
	{
		cout << "v is empty vector" << endl;
	}

	// resize
	v1.resize(10, 99);
	print(v1);
	v1.resize(3, 88);
	print(v1);
}

void test3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v1(array, array + 5);	// 区间 [beg, end)
	
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());
	print(v2);

	vector<int> v3;
	v3 = v2;
	print(v3);

	vector<int> v4;
	v4.assign(8, 99);
	print(v4);

	vector<int> v5(19, 6);
	v5.swap(v1);
	print(v5);
	print(v1);
}

void test4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v1(array, array + 5);	// 区间 [beg, end)
	
	// 头部元素
	v1.front() = 100;
	cout << "front = " << v1.front() << endl;

	// 尾部元素
	v1.back() = 900;
	cout << "back = " << v1.back() << endl;
	print(v1);
}

// 添加插入删除操作
void test5()
{
	vector<int> v;
	// 尾部添加元素
	v.push_back(4);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	print(v);

	// 中间位置插入
	v.insert(v.begin() + 3, 4, 44);
	print(v);

	// 删除
	v.erase(v.begin() + 1, v.begin() + 3);
	print(v);

	// 删除最后一个元素
	v.pop_back();
	print(v);
}


// 排序回调函数
// 返回值 bool
bool myComp(int a, int b)
{
	if (a < b)
	{
		return true;
	}
	return false;
}

// 排序
void  test6()
{
	int array[] = { 10, 2, 13, 4, 15, 7 };
	vector<int> v1(array, array + 5);	// 区间 [beg, end)
	
	// 升序
	sort(v1.begin(), v1.end());
	print(v1);

	// 降序
	sort(v1.begin(), v1.end(), myComp);
	cout << "降序..." << endl;
	print(v1);

	// 打乱顺序
	random_shuffle(v1.begin(), v1.end());
	print(v1);
	random_shuffle(v1.begin(), v1.end());
	print(v1);
}

// 合并和反转
void test7()
{
	int array[] = { 10, 2, 13, 4, 15, 7 };
	vector<int> v1(array, array + 5);	// 区间 [beg, end)
	sort(v1.begin(), v1.end());

	int array1[] = { 11, 22, 133, 54, 175, 87 };
	vector<int> v2(array1, array1 + 5);	// 区间 [beg, end)
	sort(v2.begin(), v2.end());

	vector<int> v3(v1.size()+v2.size());
	//v3.resize();

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	print(v3);
	print(v2);
	print(v1);

	// 反转
	reverse(v3.begin(), v3.end());
	print(v3);
}

// 查找的条件
bool myFunc(int a)
{
	if (a > 100)
	{
		return true;
	}
	return false;
}

typedef struct 
{
	int id;
	string name;
	string tel;
}Persion;

void test8()
{
	int array1[] = { 11, 22, 133, 54, 175, 87 };
	vector<int> v1(array1, array1 + 5);	// 区间 [beg, end)

	int sum = accumulate(v1.begin(), v1.end(), 100);
	int sum1 = accumulate(v1.begin(), v1.end(), 0);
	cout << "sum = " << sum << endl;
	cout << "sum1 = " << sum1 << endl;

	// 填充
	//fill(v1.begin(), v1.end(), 133);
	//print(v1);

	// 查找指定范围内 == emem的元素的个数
	int num = count(v1.begin(), v1.end(), 133);
	cout << "num = " << num << endl;

	// 按照用户指定的条件查找
	num = count_if(v1.begin(), v1.end(), myFunc);
	cout << "num = " << num << endl;
}

int main(void)
{
	// Enter your code
	// test1();
	// test2();
	// test3();
	// test6();
	// test7();
	test8();
	
	cout << "----------- The End -----------" << endl;
	system("pause");
}