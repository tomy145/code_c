//
//  main.cpp
//  this 指针
//
//  Created by Mac on 16/5/31.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


/*
 string synopsis

 namespace std
 {

 template <class stateT>
 class fpos
 {
 private:
 stateT st;
 public:
 fpos(streamoff = streamoff());

 operator streamoff() const;

 stateT state() const;
 void state(stateT);

 fpos& operator+=(streamoff);
 fpos  operator+ (streamoff) const;
 fpos& operator-=(streamoff);
 fpos  operator- (streamoff) const;
 };

 template <class stateT> streamoff operator-(const fpos<stateT>& x, const fpos<stateT>& y);

 template <class stateT> bool operator==(const fpos<stateT>& x, const fpos<stateT>& y);
 template <class stateT> bool operator!=(const fpos<stateT>& x, const fpos<stateT>& y);

 template <class charT>
 struct char_traits
 {
 typedef charT     char_type;
 typedef ...       int_type;
 typedef streamoff off_type;
 typedef streampos pos_type;
 typedef mbstate_t state_type;

 static void assign(char_type& c1, const char_type& c2) noexcept;
 static constexpr bool eq(char_type c1, char_type c2) noexcept;
 static constexpr bool lt(char_type c1, char_type c2) noexcept;

 static int              compare(const char_type* s1, const char_type* s2, size_t n);
 static size_t           length(const char_type* s);
 static const char_type* find(const char_type* s, size_t n, const char_type& a);
 static char_type*       move(char_type* s1, const char_type* s2, size_t n);
 static char_type*       copy(char_type* s1, const char_type* s2, size_t n);
 static char_type*       assign(char_type* s, size_t n, char_type a);

 static constexpr int_type  not_eof(int_type c) noexcept;
 static constexpr char_type to_char_type(int_type c) noexcept;
 static constexpr int_type  to_int_type(char_type c) noexcept;
 static constexpr bool      eq_int_type(int_type c1, int_type c2) noexcept;
 static constexpr int_type  eof() noexcept;
 };

 template <> struct char_traits<char>;
 template <> struct char_traits<wchar_t>;

 template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> >
 class basic_string
 {
 public:
 // types:
 typedef traits traits_type;
 typedef typename traits_type::char_type value_type;
 typedef Allocator allocator_type;
 typedef typename allocator_type::size_type size_type;
 typedef typename allocator_type::difference_type difference_type;
 typedef typename allocator_type::reference reference;
 typedef typename allocator_type::const_reference const_reference;
 typedef typename allocator_type::pointer pointer;
 typedef typename allocator_type::const_pointer const_pointer;
 typedef implementation-defined iterator;
 typedef implementation-defined const_iterator;
 typedef std::reverse_iterator<iterator> reverse_iterator;
 typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

 static const size_type npos = -1;

 basic_string()
 noexcept(is_nothrow_default_constructible<allocator_type>::value);
 explicit basic_string(const allocator_type& a);
 basic_string(const basic_string& str);
 basic_string(basic_string&& str)
 noexcept(is_nothrow_move_constructible<allocator_type>::value);
 basic_string(const basic_string& str, size_type pos, size_type n = npos,
 const allocator_type& a = allocator_type());
 basic_string(const value_type* s, const allocator_type& a = allocator_type());
 basic_string(const value_type* s, size_type n, const allocator_type& a = allocator_type());
 basic_string(size_type n, value_type c, const allocator_type& a = allocator_type());
 template<class InputIterator>
 basic_string(InputIterator begin, InputIterator end,
 const allocator_type& a = allocator_type());
 basic_string(initializer_list<value_type>, const Allocator& = Allocator());
 basic_string(const basic_string&, const Allocator&);
 basic_string(basic_string&&, const Allocator&);

 ~basic_string();

 basic_string& operator=(const basic_string& str);
 basic_string& operator=(basic_string&& str)
 noexcept(
 allocator_type::propagate_on_container_move_assignment::value &&
 is_nothrow_move_assignable<allocator_type>::value);
 basic_string& operator=(const value_type* s);
 basic_string& operator=(value_type c);
 basic_string& operator=(initializer_list<value_type>);

 iterator       begin() noexcept;
 const_iterator begin() const noexcept;
 iterator       end() noexcept;
 const_iterator end() const noexcept;

 reverse_iterator       rbegin() noexcept;
 const_reverse_iterator rbegin() const noexcept;
 reverse_iterator       rend() noexcept;
 const_reverse_iterator rend() const noexcept;

 const_iterator         cbegin() const noexcept;
 const_iterator         cend() const noexcept;
 const_reverse_iterator crbegin() const noexcept;
 const_reverse_iterator crend() const noexcept;

 size_type size() const noexcept;
 size_type length() const noexcept;
 size_type max_size() const noexcept;
 size_type capacity() const noexcept;

 void resize(size_type n, value_type c);
 void resize(size_type n);

 void reserve(size_type res_arg = 0);
 void shrink_to_fit();
 void clear() noexcept;
 bool empty() const noexcept;

 const_reference operator[](size_type pos) const;
 reference       operator[](size_type pos);

 const_reference at(size_type n) const;
 reference       at(size_type n);

 basic_string& operator+=(const basic_string& str);
 basic_string& operator+=(const value_type* s);
 basic_string& operator+=(value_type c);
 basic_string& operator+=(initializer_list<value_type>);

 basic_string& append(const basic_string& str);
 basic_string& append(const basic_string& str, size_type pos, size_type n=npos); //C++14
 basic_string& append(const value_type* s, size_type n);
 basic_string& append(const value_type* s);
 basic_string& append(size_type n, value_type c);
 template<class InputIterator>
 basic_string& append(InputIterator first, InputIterator last);
 basic_string& append(initializer_list<value_type>);

 void push_back(value_type c);
 void pop_back();
 reference       front();
 const_reference front() const;
 reference       back();
 const_reference back() const;

 basic_string& assign(const basic_string& str);
 basic_string& assign(basic_string&& str);
 basic_string& assign(const basic_string& str, size_type pos, size_type n=npos); // C++14
 basic_string& assign(const value_type* s, size_type n);
 basic_string& assign(const value_type* s);
 basic_string& assign(size_type n, value_type c);
 template<class InputIterator>
 basic_string& assign(InputIterator first, InputIterator last);
 basic_string& assign(initializer_list<value_type>);

 basic_string& insert(size_type pos1, const basic_string& str);
 basic_string& insert(size_type pos1, const basic_string& str,
 size_type pos2, size_type n);
 basic_string& insert(size_type pos, const value_type* s, size_type n=npos); //C++14
 basic_string& insert(size_type pos, const value_type* s);
 basic_string& insert(size_type pos, size_type n, value_type c);
 iterator      insert(const_iterator p, value_type c);
 iterator      insert(const_iterator p, size_type n, value_type c);
 template<class InputIterator>
 iterator insert(const_iterator p, InputIterator first, InputIterator last);
 iterator      insert(const_iterator p, initializer_list<value_type>);

 basic_string& erase(size_type pos = 0, size_type n = npos);
 iterator      erase(const_iterator position);
 iterator      erase(const_iterator first, const_iterator last);

 basic_string& replace(size_type pos1, size_type n1, const basic_string& str);
 basic_string& replace(size_type pos1, size_type n1, const basic_string& str,
 size_type pos2, size_type n2=npos); // C++14
 basic_string& replace(size_type pos, size_type n1, const value_type* s, size_type n2);
 basic_string& replace(size_type pos, size_type n1, const value_type* s);
 basic_string& replace(size_type pos, size_type n1, size_type n2, value_type c);
 basic_string& replace(const_iterator i1, const_iterator i2, const basic_string& str);
 basic_string& replace(const_iterator i1, const_iterator i2, const value_type* s, size_type n);
 basic_string& replace(const_iterator i1, const_iterator i2, const value_type* s);
 basic_string& replace(const_iterator i1, const_iterator i2, size_type n, value_type c);
 template<class InputIterator>
 basic_string& replace(const_iterator i1, const_iterator i2, InputIterator j1, InputIterator j2);
 basic_string& replace(const_iterator i1, const_iterator i2, initializer_list<value_type>);

 size_type copy(value_type* s, size_type n, size_type pos = 0) const;
 basic_string substr(size_type pos = 0, size_type n = npos) const;

 void swap(basic_string& str)
 noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

 const value_type* c_str() const noexcept;
 const value_type* data() const noexcept;

 allocator_type get_allocator() const noexcept;

 size_type find(const basic_string& str, size_type pos = 0) const noexcept;
 size_type find(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type find(const value_type* s, size_type pos = 0) const noexcept;
 size_type find(value_type c, size_type pos = 0) const noexcept;

 size_type rfind(const basic_string& str, size_type pos = npos) const noexcept;
 size_type rfind(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type rfind(const value_type* s, size_type pos = npos) const noexcept;
 size_type rfind(value_type c, size_type pos = npos) const noexcept;

 size_type find_first_of(const basic_string& str, size_type pos = 0) const noexcept;
 size_type find_first_of(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type find_first_of(const value_type* s, size_type pos = 0) const noexcept;
 size_type find_first_of(value_type c, size_type pos = 0) const noexcept;

 size_type find_last_of(const basic_string& str, size_type pos = npos) const noexcept;
 size_type find_last_of(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type find_last_of(const value_type* s, size_type pos = npos) const noexcept;
 size_type find_last_of(value_type c, size_type pos = npos) const noexcept;

 size_type find_first_not_of(const basic_string& str, size_type pos = 0) const noexcept;
 size_type find_first_not_of(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type find_first_not_of(const value_type* s, size_type pos = 0) const noexcept;
 size_type find_first_not_of(value_type c, size_type pos = 0) const noexcept;

 size_type find_last_not_of(const basic_string& str, size_type pos = npos) const noexcept;
 size_type find_last_not_of(const value_type* s, size_type pos, size_type n) const noexcept;
 size_type find_last_not_of(const value_type* s, size_type pos = npos) const noexcept;
 size_type find_last_not_of(value_type c, size_type pos = npos) const noexcept;

 int compare(const basic_string& str) const noexcept;
 int compare(size_type pos1, size_type n1, const basic_string& str) const;
 int compare(size_type pos1, size_type n1, const basic_string& str,
 size_type pos2, size_type n2=npos) const; // C++14
 int compare(const value_type* s) const noexcept;
 int compare(size_type pos1, size_type n1, const value_type* s) const;
 int compare(size_type pos1, size_type n1, const value_type* s, size_type n2) const;

 bool __invariants() const;
 };

 template<class charT, class traits, class Allocator>
 basic_string<charT, traits, Allocator>
 operator+(const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs);

 template<class charT, class traits, class Allocator>
 basic_string<charT, traits, Allocator>
 operator+(const charT* lhs , const basic_string<charT,traits,Allocator>&rhs);

 template<class charT, class traits, class Allocator>
 basic_string<charT, traits, Allocator>
 operator+(charT lhs, const basic_string<charT,traits,Allocator>& rhs);

 template<class charT, class traits, class Allocator>
 basic_string<charT, traits, Allocator>
 operator+(const basic_string<charT, traits, Allocator>& lhs, const charT* rhs);

 template<class charT, class traits, class Allocator>
 basic_string<charT, traits, Allocator>
 operator+(const basic_string<charT, traits, Allocator>& lhs, charT rhs);

 template<class charT, class traits, class Allocator>
 bool operator==(const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator==(const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator==(const basic_string<charT,traits,Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator!=(const basic_string<charT,traits,Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator!=(const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator!=(const basic_string<charT, traits, Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator< (const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator< (const basic_string<charT, traits, Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator< (const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator> (const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator> (const basic_string<charT, traits, Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator> (const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator<=(const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator<=(const basic_string<charT, traits, Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator<=(const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator>=(const basic_string<charT, traits, Allocator>& lhs,
 const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator>=(const basic_string<charT, traits, Allocator>& lhs, const charT* rhs) noexcept;

 template<class charT, class traits, class Allocator>
 bool operator>=(const charT* lhs, const basic_string<charT, traits, Allocator>& rhs) noexcept;

 template<class charT, class traits, class Allocator>
 void swap(basic_string<charT, traits, Allocator>& lhs,
 basic_string<charT, traits, Allocator>& rhs)
 noexcept(noexcept(lhs.swap(rhs)));

 template<class charT, class traits, class Allocator>
 basic_istream<charT, traits>&
 operator>>(basic_istream<charT, traits>& is, basic_string<charT, traits, Allocator>& str);

 template<class charT, class traits, class Allocator>
 basic_ostream<charT, traits>&
 operator<<(basic_ostream<charT, traits>& os, const basic_string<charT, traits, Allocator>& str);

 template<class charT, class traits, class Allocator>
 basic_istream<charT, traits>&
 getline(basic_istream<charT, traits>& is, basic_string<charT, traits, Allocator>& str,
 charT delim);

 template<class charT, class traits, class Allocator>
 basic_istream<charT, traits>&
 getline(basic_istream<charT, traits>& is, basic_string<charT, traits, Allocator>& str);

 typedef basic_string<char>    string;
 typedef basic_string<wchar_t> wstring;
 typedef basic_string<char16_t> u16string;
 typedef basic_string<char32_t> u32string;

 int                stoi  (const string& str, size_t* idx = 0, int base = 10);
 long               stol  (const string& str, size_t* idx = 0, int base = 10);
 unsigned long      stoul (const string& str, size_t* idx = 0, int base = 10);
 long long          stoll (const string& str, size_t* idx = 0, int base = 10);
 unsigned long long stoull(const string& str, size_t* idx = 0, int base = 10);

 float       stof (const string& str, size_t* idx = 0);
 double      stod (const string& str, size_t* idx = 0);
 long double stold(const string& str, size_t* idx = 0);

 string to_string(int val);
 string to_string(unsigned val);
 string to_string(long val);
 string to_string(unsigned long val);
 string to_string(long long val);
 string to_string(unsigned long long val);
 string to_string(float val);
 string to_string(double val);
 string to_string(long double val);

 int                stoi  (const wstring& str, size_t* idx = 0, int base = 10);
 long               stol  (const wstring& str, size_t* idx = 0, int base = 10);
 unsigned long      stoul (const wstring& str, size_t* idx = 0, int base = 10);
 long long          stoll (const wstring& str, size_t* idx = 0, int base = 10);
 unsigned long long stoull(const wstring& str, size_t* idx = 0, int base = 10);

 float       stof (const wstring& str, size_t* idx = 0);
 double      stod (const wstring& str, size_t* idx = 0);
 long double stold(const wstring& str, size_t* idx = 0);

 wstring to_wstring(int val);
 wstring to_wstring(unsigned val);
 wstring to_wstring(long val);
 wstring to_wstring(unsigned long val);
 wstring to_wstring(long long val);
 wstring to_wstring(unsigned long long val);
 wstring to_wstring(float val);
 wstring to_wstring(double val);
 wstring to_wstring(long double val);

 template <> struct hash<string>;
 template <> struct hash<u16string>;
 template <> struct hash<u32string>;
 template <> struct hash<wstring>;

 basic_string<char>     operator "" s( const char *str,     size_t len ); // C++14
 basic_string<wchar_t>  operator "" s( const wchar_t *str,  size_t len ); // C++14
 basic_string<char16_t> operator "" s( const char16_t *str, size_t len ); // C++14
 basic_string<char32_t> operator "" s( const char32_t *str, size_t len ); // C++14

 }  // std

 */


using namespace std;

class Animal
{

public:

    Animal(int age,string name)
    {
        this->age = age;
        this->name = name;
    }

    Animal()
    {
        cout << "调用了默认构造方法 -- " << typeid(Animal).name() << endl;
    };

//    Animal & operator+=(const Animal &another)
//    {
//        this->age += another.age;
//        this->name = this->name + " -" + another.name;
//
//        return *this;
//    }

    Animal & operator-=(const Animal &ano)
    {
        this->age -= ano.age;

        this->name.find(ano.name);

        return *this;

    }

    string getName()
    {
        return this->name;
    }

    int getAge()
    {
        return this->age;
    }

//    Animal & operator++()
//    {
//        this->age = this->age + this->age;
//
//        return *this;
//        
//    }

     const Animal  operator++(int)
    {
        Animal temp(this->age,this->name);
        this->age++;

        return temp;

    }


private:
    int age;
    string name;
};


////全局的  前++
//Complex & operator++(Complex &c)
//{
//    c.a++;
//    c.b++;
//
//    return c;
//}



void test2()
{
    Animal a1 = Animal(12, "张三");

    Animal a2 = Animal(24, "李四");

//    a1 += a2 += a2 += a2;

    cout << "a1.name = " << a1.getName() << endl;
    cout << "a1.age = " << a1.getAge() << endl;

    a1++;

    cout << a1.getAge() << endl;

}

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


void test3()
{
    std::string str = "123lskdkjjhhfh123lejjjrjrri`123kjfjfkksproro123";
//    std::cout<<"Please input str:"<<std::endl;
    //std::cin>>str;
//    getline(std::cin,str);



    std::string pattern = "123";
//    std::cout<<"Please input pattern:"<<std::endl;
    //std::cin>>pattern;
//    getline(std::cin,pattern);//用于获取含空格的字符串

    std::vector<std::string> result = split(str,pattern);

    for(int i=0; i<result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

//    std::cin.get();
//    std::cin.get();

}

void test4()
{
    string str1 = "123name356name---myname";

    string str2 = "name";

    //   unsigned long s1 = str1.find(str2);
    //    str1.rfind(str2);


    cout << str1.rfind(str2) << endl;
}

int main(int argc, const char * argv[])
{

    test3();

    return 0;
}
