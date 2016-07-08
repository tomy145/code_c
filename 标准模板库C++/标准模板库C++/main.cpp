//
//  main.cpp
//  标准模板库C++
//
//  Created by Mac on 16/6/11.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

 
using namespace std;

/*
 vector synopsis

 namespace std
 {

 template <class T, class Allocator = allocator<T> >
 class vector
 {
 public:
 typedef T                                        value_type;
 typedef Allocator                                allocator_type;
 typedef typename allocator_type::reference       reference;
 typedef typename allocator_type::const_reference const_reference;
 typedef implementation-defined                   iterator;
 typedef implementation-defined                   const_iterator;
 typedef typename allocator_type::size_type       size_type;
 typedef typename allocator_type::difference_type difference_type;
 typedef typename allocator_type::pointer         pointer;
 typedef typename allocator_type::const_pointer   const_pointer;
 typedef std::reverse_iterator<iterator>          reverse_iterator;
 typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

 vector()
 noexcept(is_nothrow_default_constructible<allocator_type>::value);
 explicit vector(const allocator_type&);
 explicit vector(size_type n);
 explicit vector(size_type n, const allocator_type&); // C++14
 vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
 template <class InputIterator>
 vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
 vector(const vector& x);
 vector(vector&& x)
 noexcept(is_nothrow_move_constructible<allocator_type>::value);
 vector(initializer_list<value_type> il);
 vector(initializer_list<value_type> il, const allocator_type& a);
 ~vector();
 vector& operator=(const vector& x);
 vector& operator=(vector&& x)
 noexcept(
 allocator_type::propagate_on_container_move_assignment::value &&
 is_nothrow_move_assignable<allocator_type>::value);
 vector& operator=(initializer_list<value_type> il);
 template <class InputIterator>
 void assign(InputIterator first, InputIterator last);
 void assign(size_type n, const value_type& u);
 void assign(initializer_list<value_type> il);

 allocator_type get_allocator() const noexcept;

 iterator               begin() noexcept;
 const_iterator         begin()   const noexcept;
 iterator               end() noexcept;
 const_iterator         end()     const noexcept;

 reverse_iterator       rbegin() noexcept;
 const_reverse_iterator rbegin()  const noexcept;
 reverse_iterator       rend() noexcept;
 const_reverse_iterator rend()    const noexcept;

 const_iterator         cbegin()  const noexcept;
 const_iterator         cend()    const noexcept;
 const_reverse_iterator crbegin() const noexcept;
 const_reverse_iterator crend()   const noexcept;

 size_type size() const noexcept;
 size_type max_size() const noexcept;
 size_type capacity() const noexcept;
 bool empty() const noexcept;
 void reserve(size_type n);
 void shrink_to_fit() noexcept;

 reference       operator[](size_type n);
 const_reference operator[](size_type n) const;
 reference       at(size_type n);
 const_reference at(size_type n) const;

 reference       front();
 const_reference front() const;
 reference       back();
 const_reference back() const;

 value_type*       data() noexcept;
 const value_type* data() const noexcept;

 void push_back(const value_type& x);
 void push_back(value_type&& x);
 template <class... Args>
 void emplace_back(Args&&... args);
 void pop_back();

 template <class... Args> iterator emplace(const_iterator position, Args&&... args);
 iterator insert(const_iterator position, const value_type& x);
 iterator insert(const_iterator position, value_type&& x);
 iterator insert(const_iterator position, size_type n, const value_type& x);
 template <class InputIterator>
 iterator insert(const_iterator position, InputIterator first, InputIterator last);
 iterator insert(const_iterator position, initializer_list<value_type> il);

 iterator erase(const_iterator position);
 iterator erase(const_iterator first, const_iterator last);

 void clear() noexcept;

 void resize(size_type sz);
 void resize(size_type sz, const value_type& c);

 void swap(vector&)
 noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

 bool __invariants() const;
 };

 template <class Allocator = allocator<T> >
 class vector<bool, Allocator>
 {
 public:
 typedef bool                                     value_type;
 typedef Allocator                                allocator_type;
 typedef implementation-defined                   iterator;
 typedef implementation-defined                   const_iterator;
 typedef typename allocator_type::size_type       size_type;
 typedef typename allocator_type::difference_type difference_type;
 typedef iterator                                 pointer;
 typedef const_iterator                           const_pointer;
 typedef std::reverse_iterator<iterator>          reverse_iterator;
 typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

 class reference
 {
 public:
 reference(const reference&) noexcept;
 operator bool() const noexcept;
 reference& operator=(const bool x) noexcept;
 reference& operator=(const reference& x) noexcept;
 iterator operator&() const noexcept;
 void flip() noexcept;
 };

 class const_reference
 {
 public:
 const_reference(const reference&) noexcept;
 operator bool() const noexcept;
 const_iterator operator&() const noexcept;
 };

 vector()
 noexcept(is_nothrow_default_constructible<allocator_type>::value);
 explicit vector(const allocator_type&);
 explicit vector(size_type n, const allocator_type& a = allocator_type()); // C++14
 vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
 template <class InputIterator>
 vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
 vector(const vector& x);
 vector(vector&& x)
 noexcept(is_nothrow_move_constructible<allocator_type>::value);
 vector(initializer_list<value_type> il);
 vector(initializer_list<value_type> il, const allocator_type& a);
 ~vector();
 vector& operator=(const vector& x);
 vector& operator=(vector&& x)
 noexcept(
 allocator_type::propagate_on_container_move_assignment::value &&
 is_nothrow_move_assignable<allocator_type>::value);
 vector& operator=(initializer_list<value_type> il);
 template <class InputIterator>
 void assign(InputIterator first, InputIterator last);
 void assign(size_type n, const value_type& u);
 void assign(initializer_list<value_type> il);

 allocator_type get_allocator() const noexcept;

 iterator               begin() noexcept;
 const_iterator         begin()   const noexcept;
 iterator               end() noexcept;
 const_iterator         end()     const noexcept;

 reverse_iterator       rbegin() noexcept;
 const_reverse_iterator rbegin()  const noexcept;
 reverse_iterator       rend() noexcept;
 const_reverse_iterator rend()    const noexcept;

 const_iterator         cbegin()  const noexcept;
 const_iterator         cend()    const noexcept;
 const_reverse_iterator crbegin() const noexcept;
 const_reverse_iterator crend()   const noexcept;

 size_type size() const noexcept;
 size_type max_size() const noexcept;
 size_type capacity() const noexcept;
 bool empty() const noexcept;
 void reserve(size_type n);
 void shrink_to_fit() noexcept;

 reference       operator[](size_type n);
 const_reference operator[](size_type n) const;
 reference       at(size_type n);
 const_reference at(size_type n) const;

 reference       front();
 const_reference front() const;
 reference       back();
 const_reference back() const;

 void push_back(const value_type& x);
 template <class... Args> void emplace_back(Args&&... args);  // C++14
 void pop_back();

 template <class... Args> iterator emplace(const_iterator position, Args&&... args);  // C++14
 iterator insert(const_iterator position, const value_type& x);
 iterator insert(const_iterator position, size_type n, const value_type& x);
 template <class InputIterator>
 iterator insert(const_iterator position, InputIterator first, InputIterator last);
 iterator insert(const_iterator position, initializer_list<value_type> il);

 iterator erase(const_iterator position);
 iterator erase(const_iterator first, const_iterator last);

 void clear() noexcept;

 void resize(size_type sz);
 void resize(size_type sz, value_type x);

 void swap(vector&)
 noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
 allocator_traits<allocator_type>::is_always_equal::value);  // C++17
 void flip() noexcept;

 bool __invariants() const;
 };

 template <class Allocator> struct hash<std::vector<bool, Allocator>>;

 template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
 template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
 template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
 template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
 template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
 template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

 template <class T, class Allocator>
 void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
 noexcept(noexcept(x.swap(y)));

 }  // std

 */


class Person
{

public:

    Person(int age , std::string name)
    {
        this->age = age;
        this->name = name;
    }
    Person()
    {
        this->age = 0;
        this->name = "";
    }

    int age;
    std::string name;
};


void test1()
{
    int  const * p = nullptr ;

    p++;
    using namespace std;

    //    第一种初始化方式
    //    std::vector<Person>::size_type s1 = 10;  //大小
    //    vector<Person> v1 = vector<Person>(s1);

    //    第二种初始化方式
    //    vector<Person> v1 = vector<Person>(10); //直接给定大小，或者给个0 ，会自动扩充
    //    vector<Person> v1 = vector<Person>(); //不给数据，默认是0

    //    第三种初始化方式
    //    Person p1 = Person(10, "张三");
    //    vector<Person> v1 = vector<Person>(10, p1);

    Person p1 = Person(12, "王麻子");
    vector<Person> v2 = vector<Person>(10);
    for (int i = 0; i < 10; i++)
    {
        v2.insert(v2.begin() + i, p1);
    }


    for (vector<Person>::iterator it1 = v2.end(); it1 == v2.begin(); it1 --)
    {
        Person p1 = *it1;

        std::cout << p1.age << std::endl;
    }



    //    第四种初始化方式
    //    内部扩容是以2的n次方扩容的
    //    vector<Person> v1 = vector<Person>(v2);


    //    std::cout << "v1.size = " << v1.size() << std::endl; //打印vector的大小
    //    std::cout << "v1.capacity = " << v1.capacity() << std::endl; //打印vector的容量
    
    

}


void test2()
{
    vector<int> v1(10);

    for (int i = 0; i < 10; i++)
    {
        v1.at(i) = i + 'c';
    }


    v1.assign(v1.begin(), v1.end());




    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << endl;
    }
}





class A
{
public:
    A(int a)
    {
        this->num = a;
    }

    double num;
};

int main(int argc, const char * argv[])
{


    vector<A> v1;

    int arr[100] = {0};

    vector<int>v2(100);

    v2.push_back(1);

    cout << v2.at(0) << endl;


    v2.insert(v2.begin() + 50, 3);

    cout << v2.at(99) << endl;


//
//    int array[10] = {1,5,22,91,112,1,2,0,39,11};
//
//
//    for (int i = 0; i < 10; i++)
//    {
//        A a1(array[i]);
//        v1.push_back(a1);
//    }
//
//    double sum = accumulate(v1.begin(), v1.end(), 0, [](A a1,A a2){return  a1.num + a2.num;});
//
//    cout << sum << endl;

    return 0;
}
