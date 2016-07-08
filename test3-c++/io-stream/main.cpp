//
//  main.cpp
//  io-stream
//
//  Created by Mac on 16/6/9.
//  Copyright © 2016年 Mac. All rights reserved.
//

#include <iostream>
#include <istream>
#include <ostream>
#include <iomanip>


// 27.7.1.1.3 Prefix/suffix:
//class _LIBCPP_TYPE_VIS_ONLY sentry;
//
//// 27.7.1.2 Formatted input:
//basic_istream& operator>>(basic_istream& (*__pf)(basic_istream&));
//basic_istream& operator>>(basic_ios<char_type, traits_type>&
//                          (*__pf)(basic_ios<char_type, traits_type>&));
//basic_istream& operator>>(ios_base& (*__pf)(ios_base&));
//basic_istream& operator>>(basic_streambuf<char_type, traits_type>* __sb);
//basic_istream& operator>>(bool& __n);
//basic_istream& operator>>(short& __n);
//basic_istream& operator>>(unsigned short& __n);
//basic_istream& operator>>(int& __n);
//basic_istream& operator>>(unsigned int& __n);
//basic_istream& operator>>(long& __n);
//basic_istream& operator>>(unsigned long& __n);
//basic_istream& operator>>(long long& __n);
//basic_istream& operator>>(unsigned long long& __n);
//basic_istream& operator>>(float& __f);
//basic_istream& operator>>(double& __f);
//basic_istream& operator>>(long double& __f);
//basic_istream& operator>>(void*& __p);
//
//// 27.7.1.3 Unformatted input:
//_LIBCPP_INLINE_VISIBILITY
//streamsize gcount() const {return __gc_;}
//int_type get();
//basic_istream& get(char_type& __c);
//basic_istream& get(char_type* __s, streamsize __n);
//basic_istream& get(char_type* __s, streamsize __n, char_type __dlm);
//basic_istream& get(basic_streambuf<char_type, traits_type>& __sb);
//basic_istream& get(basic_streambuf<char_type, traits_type>& __sb, char_type __dlm);
//
//basic_istream& getline(char_type* __s, streamsize __n);
//basic_istream& getline(char_type* __s, streamsize __n, char_type __dlm);
//
//basic_istream& ignore(streamsize __n = 1, int_type __dlm = traits_type::eof());
//int_type peek();
//basic_istream& read (char_type* __s, streamsize __n);
//streamsize readsome(char_type* __s, streamsize __n);
//
//basic_istream& putback(char_type __c);
//basic_istream& unget();
//int sync();
//
//pos_type tellg();
//basic_istream& seekg(pos_type __pos);
//basic_istream& seekg(off_type __off, ios_base::seekdir __dir);

void test1()
{
    std::cin.clear();
    std::cin.sync();
    char ch = -1;

    while ((ch = std::cin.get()) != EOF)
    {
        std::cin >> ch ;
        std::cout << "ch = " << ch << std::endl;
        //        std::cin.ignore();
        //        std::cin.sync();
    }
    

}

void test2()
{
    char ch;

    for (int i = 0; i < 10; i++)
    {
        std::cin.get(ch);
        std::cout << "ch = " << ch << std::endl;
        std::cin.ignore();
        std::cin.sync();
    }

}

void test4()
{

    using namespace std;
    cout << "Please, enter a number or a word: ";

    char c = cin.get();

    while (c != 'q')
    {
        c = cin.get();
        cout << c << endl;
        cin.ignore(1,'\n');
    }

    //    if ( (c >= '0') && (c <= '9') ) //享     都把
    //    {
    //        int n; //          这   cin >>n
    //        cin.putback (c);
    //        cin >> n;
    //        cout << "You entered a number: " << n << '\n';
    //    }
    //    else
    //    {
    //        string str;
    //        cin.putback (c);
    //        getline (cin,str); // //都把这
    //        cout << "You entered a word: " << str << '\n';
    //    }

}

void test3()
{

    char buf[1024] = {0};


    //    std::cin.getline(buf, 10); //读取10个字符,敲回车键会刷新缓冲区，终止读取
    //    std::cin.getline(buf, 10, '.'); //读取10个字符串，遇到"."就不会读取了


    //    std::cin.read(buf, 10); //读取10个字符

    //    std::cin.getline(buf, 1);

    //    std::cin.readsome(buf, 10);
    std::cin.getline(buf, 10);

    std::cin.ignore(' ');

    //    std::cout << std::cin.gcount() << std::endl; //获取输入流有效字符的长度
    
    std::cout << "buf = " << buf << std::endl;
}

//
//// 27.7.2.7 Unformatted output:
//basic_ostream& put(char_type c);
//basic_ostream& write(const char_type* s, streamsize n);
//basic_ostream& flush();
//
//// 27.7.2.5 seeks:
//pos_type tellp();
//basic_ostream& seekp(pos_type);
//basic_ostream& seekp(off_type, ios_base::seekdir);
//protected:
//basic_ostream(const basic_ostream& rhs) = delete;
//basic_ostream(basic_ostream&& rhs);
//// 27.7.3.3 Assign/swap
//basic_ostream& operator=(basic_ostream& rhs) = delete;
//basic_ostream& operator=(const basic_ostream&& rhs);
//void swap(basic_ostream& rhs);


void test5()
{
    using namespace std;
    cout << "hello world" << endl;
    cout.put('h').put('e').put('l').put('\n');
    cout.write("hello world", 4); //享
    char buf[] = "hello world";
    printf("\n");
    cout.write(buf, strlen(buf));
    printf("\n");

    cout.write(buf, strlen(buf) );

    printf("\n");
    

}


int main(int argc, const char * argv[])
{

    std::cout << "main  --- start --- \n";

    using namespace std;

    //  后
    cout << "<start>";
    cout.width(30);
    cout.fill('*');
    cout.setf(ios::showbase); //#include <iomanip>
    cout.setf(ios::internal); //
    cout << hex << 123 << "<End>\n";
    cout << endl;
    cout << endl;
    //     把   把
    cout << "<Start>"
    << setw(30)
    << setfill('*')
    << setiosflags(ios::showbase) //
    << setiosflags(ios::internal)
    << hex
    << 123
    << "<End>\n"
    << endl;

    cout <<   setbase(10) << endl;

    std::cout << "main  --- end --- \n";

    return 0;
}



