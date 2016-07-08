#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>

using namespace std;

class Student
{
public:
    Student(string name, double score)
    {
        this->name = name;
        this->score = score;
    }

    string getName()
    {
        return this->name;
    }
    double getScore()
    {
        return this->score;
    }

private:
    string name;	// 姓名
    double score;	// 成绩
};

void initSocre(vector<Student> &v)
{
    while (true)
    {
        cout << "请输入学生的姓名和成绩 张三  100" << endl;
        string name;
        double score;
        cin >> name >> score;
        if (name == "gameover")
        {
            break;
        }
        Student stu(name, score);
        // 将学生放入容器中
        v.push_back(stu);
    }
}

// 成绩排序
bool myComp(Student s, Student s1)
{
    // 按照成绩降序排列
    if (s.getScore() > s1.getScore())
    {
        return true;
    }
    return false;
}


bool myCount(Student s)
{
    if (s.getScore() < 60)
    {
        return true;
    }
    return false;
}

//
int myFunc(int s, Student s1)
{
    return s + s1.getScore();
}

// 计算成绩
void accuScore(vector<Student> &v)
{
    // 对成绩排序
    sort(v.begin(), v.end(), myComp);
    // 最高分
    cout << "最高分: " << v.front().getName() << " " << v.front().getScore() << endl;
    cout << "最低分: " << v.back().getName() << " " << v.back().getScore() << endl;

    // 计算总分
    double sum = accumulate(v.begin(), v.end(), 0, myFunc);
    // 计算平均分
    double avg = sum / v.size();
    cout << "平均分: " << avg << endl;

    // 挂科的人数
    long count = count_if(v.begin(), v.end(), myCount);
    cout << "挂科的人数: " << count << endl;
    cout << "通过考试的人数: " << v.size() - count << endl;
}

int main(void)
{
    // Enter your code
    vector<Student> v;
    // init
    initSocre(v);
    // score
    accuScore(v);
    
    cout << "----------- The End -----------" << endl;
    system("pause");
    return 0;
}