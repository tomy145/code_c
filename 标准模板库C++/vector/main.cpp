#include <iostream>
#include <deque>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

// 选手
class Persion
{
public:
    Persion(string name, int score)
    {
        this->name = name;
        this->score = score;
    }

    ~Persion(){};

    void setScore(int c)
    {
        this->score = c;
    }

    int getScore()
    {
        return score;
    }
    string getName()
    {
        return name;
    }

private:
    string name;
    int score;	// 最终的得分
};

void createPersion(deque<Persion> &p)
{
    string str = "ABCDE";
    // 取字符串中的字符
    // 1. at(index)
    // 2. [index]
    // 3. 迭代器 string::iterator it = str.begin();  *it
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        string name = "选手";
        name = name + *it;
        Persion per(name, 0);
        // 将选手放入容器中
        p.push_back(per);
    }
}

void pingweiScore(deque<Persion> &p)
{
    // 遍历选手容器
    // 遍历方式 -- 2: 1. 迭代器 2. 遍历数组的方式
    for (deque<Persion>::iterator it = p.begin(); it != p.end(); ++it)
    {
        // 评委打分操作
        // 容器存储评委的分数
        deque<int> groupScore;
        for (int i = 0; i < 10; ++i)
        {
            int score = rand() % 15;
            groupScore.push_back(score);
        }
        // 排序
        sort(groupScore.begin(), groupScore.end());	// 升序
        // 去掉最高分
        groupScore.pop_back();
        // ...低..
        groupScore.pop_front();
        // 平均分
        int avg = accumulate(groupScore.begin(), groupScore.end(), 0) / groupScore.size();

        it->setScore(avg);
    }
}


class A
{

public:

    A(int n)
    {
        this->number = n;
    }

    int number;

};

void test1()
{

    // Enter your code
    deque<Persion> d;	// 选手列表
    // 创建选手
    createPersion(d);

    // 评委打分环节
    pingweiScore(d);

    for (deque<Persion>::iterator it = d.begin(); it != d.end(); ++it)
    {
        // string -> char*
        // c_str()   data()
        cout << it->getName().data() << " " << it->getScore() << endl;
    }

    cout << "----------- The End -----------" << endl;
    

}



int main(void)
{


    deque<A> dq1;

    for (int i = 0 ; i < 10000; i++)
    {
        A a1(i);

    }




    system("pause");
    return 0;
}