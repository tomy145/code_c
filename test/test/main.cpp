//
//  main.cpp
//  test
//
//  Created by Mac on 16/6/11.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:
    Student(int score,string name)
    {
        this->score = score;
        this->name = name;
    }
    Student()
    {
        this->score = 0;
        this->name  ="";
    }
    int score;
    string name;
};

int main(int argc, const char * argv[]) {

    vector<Student> v(10);
    for(vector<Student>::iterator v1=v.begin();v1!=v.end();v1++)
    {

        (*v1)=Student (10,"hello");
        cout<<(*v1).name<<endl;
    }

    return 0;
}
