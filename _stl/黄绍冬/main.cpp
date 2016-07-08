//
//  main.cpp
//  黄绍冬
//
//  Created by Mac on 16/6/22.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <list>
#include <stack>




using namespace std;

/*********************第一题 start *******************************************/

//第一题
void test1()
{
    int ia[] = {0 ,1,1,2,3,5,8,13,21,55, 99};

    int len = sizeof(ia) / sizeof(int);

    vector<int>va = vector<int>(ia,ia +len);

    list<int>la = list<int>(ia, ia+len);

    vector<int>vb(len);
    for (int i = 0; i < va.size(); ++i)
    {
        if (va[i] %2 != 1)
        {
            vb.push_back(va[i]);
        }
    }

    va.swap(vb);

    for_each(va.begin(), va.end(), [](int a){

        cout << " a = " << a << endl;

    });

    int sum =  accumulate(va.begin(), va.end(), 0);

    cout << "计算的和为 = " << sum << endl;

    long cnt = count_if(la.begin(), la.end(), [](int a){
        return a > 5;
    });
    
    cout << "大于5 的个数 = " << cnt << endl;

}

/*********************第一题 end *******************************************/



/*********************第二题 start *******************************************/

template <class T>
class MyQueue
{


public:

    T temp;

    bool empty()
    {
        if (sta_in.empty() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    void push(T t1)
    {
        sta_in.push(t1);
    }

    void pop()
    {
        while (sta_in.size() != 1)
        {
            temp = sta_in.top(); //返回顶部的
            sta_out.push(temp);
            sta_in.pop(); //弹出
        }
        sta_in.pop(); //弹出最后一个

        //装回去
        while (sta_out.size() != 0)
        {
            temp = sta_out.top(); //返回顶部的
            sta_in.push(temp);
            sta_out.pop(); //弹出
        }
    }

    T & back()
    {
        return sta_in.top();
    }

    T & front()
    {
        while (sta_in.size() != 0) //交换顺序
        {
            temp = sta_in.top(); //返回顶部的
            sta_out.push(temp);
            sta_in.pop(); //弹出
        }

        return sta_out.top();
    }

protected:

    stack<T> sta_in;
    stack<T> sta_out;

};


void test2()
{
    MyQueue<int> que;

    for (int i = 0; i < 5; i++)
    {
        que.push(i);
    }

    //empty()

    cout << "empty = " << que.empty() << endl;


//
    //pop()
    que.pop();
    que.pop();
    que.pop();


    //back()
    int temp_back = que.back();
    cout << "temp_back = " << temp_back << endl;

    //front()
    int temp_front = que.front();
    cout << "temp_front = " << temp_front << endl;
}







/*********************第二题 end *******************************************/







/*********************第三题 start *******************************************/


//字符串分割函数
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;

    std::vector<std::string> result;

    str+=pattern;//扩展字符串以方便操作

    unsigned long size=str.size();

    for(unsigned long i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i = pos+pattern.size() - 1;
        }
    }

    return result;
}


//第三题
void test3()
{

    string line1 = "We were her pride of 10 she named us:";
    string line2 = "Benjamin, Phoneix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";
    string sentence = line1 + " " + line2 + " " + line3;

    cout << "sentence = " << sentence << endl;

    vector<string>vs = split(sentence, " ");

    cout << " 单词个数 = " << vs.size() << endl;

    sort(vs.begin(), vs.end(), [](string st1 , string st2){
        return st1.size() < st2.size();
    });

    for_each(vs.begin(), vs.end(), [](string str){

        cout << "string = " << str << endl;
        cout << "size = " << str.size() << endl;

    });

    cout << "最长的单词是 = "  << vs[vs.size() - 1 ] << endl;
    cout << "最短的单词是 = "  << vs[0] << endl;




}


/*********************第三题 end *******************************************/



/*********************第四题 start *******************************************/

typedef struct _tag_Node
{
    struct _tag_Node *next;

}Node;

typedef struct _tag_sLinkList
{
    Node header;

}SLinkList;


typedef struct _tag_Person
{

    Node node;

    int age;

}Person;


// 若线性表为空，返回true，否则返回false
int ListEmpty(SLinkList *list)
{
    int ret = 0;

    if (list != NULL)
    {
        ret = 1;
    }

    return ret;
}

// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SLinkList *list, Node* e)
{
    if (list == NULL)
    {
        return;
    }

    //定义游标指针
    Node *pCur = &list->header;

    //挪动指针
    for (int i = 0; i < 0; ++i)
    {
        pCur = pCur->next;
    }

    //插入节点
    e->next = pCur->next; //先把后面的节点接上,保证链表不会断掉
    pCur->next = e;

}

/**
 *  获取链表长度
 *
 *  @param list 链表
 *  @param len  长度
 */
void getListLen(SLinkList *list , int *len)
{
    int i = 0;
    if (list != NULL)
    {
        Node *pCur = &list->header;
        while (pCur != NULL)
        {
            pCur = pCur->next;
            ++i;
        }
    }

    *len = i;

}


/**
 *  获取倒数第n个节点
 *
 *  @param list 链表
 *  @param pos  第n个
 *
 *  @return 节点
 */
Node *getNode(SLinkList *list , int pos)
{
    if (list == NULL )
    {
        return nullptr;
    }

    int len = 0;
    getListLen(list, &len);

    if (pos < 0 || pos > len - 1)
    {
        return nullptr;
    }

    Node *pCur = &list->header;

    //挪动位置
    for (int i = 0; i < len - 1 - pos; ++i)
    {
        pCur = pCur->next;
    }

    return pCur->next;
}



void test4()
{
    SLinkList list;
    list.header.next = NULL;

    cout << "list init ---- " << endl;
    //头插法
    for (int i = 0; i < 10; ++i)
    {
        Person *p1 = new Person;
        p1->age = i + 'a';
        cout << "age = " << p1->age << endl;
        ListInsert(&list, &p1->node);
    }

    cout << "list init end ----- " << endl;


    int len = 0;
    getListLen(&list, &len);

    cout << len - 1 << endl;

    //获取倒数第2个节点
    Person *p1 = (Person *)getNode(&list, 2);

    cout << "获取倒数第二个的值为 = p1.age = " << p1->age << endl;


}


/*********************第四题 end *******************************************/



int main(int argc, const char * argv[])
{

    string::size_type


    test2();
    


    return 0;
}
