
#include <iostream>

class MyString
{


public:


    MyString(const char *str = "")
    {
        this->m_Str = new char(0);
    }

    MyString(const MyString &other)
    {

        this->m_Str = new char[getStrLen(other.m_Str)];
        copyStr(this->m_Str, other.m_Str);
    }

    MyString & operator =(const MyString &other)
    {

        if (this != &other)
        {

            delete [] this->m_Str;
            this->m_Str = NULL;

            this->m_Str = new char[getStrLen(other.m_Str)];
            copyStr(this->m_Str, other.m_Str);

        }

        return *this;
    }

    MyString & operator =(const char * str)
    {

        delete [] this->m_Str;
        this->m_Str = NULL;

        this->m_Str = new char[getStrLen(str)];
        copyStr(this->m_Str,str);

        return *this;
    }


    char & operator[](unsigned int index)
    {
        return this->m_Str[index];
    }

    int getStrLen(const char *str)
    {
        int len = 0;

        while (*str != '\0')
        {
            len+=1;
            str+=1;
        }

        return len;
    }

    void copyStr(char *&des ,const char *src)
    {
        int len = getStrLen(src);
        for (int i = 0; i < len; i++)
        {
            des[i] = src[i];
        }
    }


    friend MyString operator+(const MyString &s1 , const MyString &s2);


    ~MyString()
    {
        if (this->m_Str != nullptr)
        {
            delete this->m_Str;
        }
    }


private:
    char *m_Str;

};

//
//MyString operator+(const MyString &s1 , const MyString &s2)
//{
//
//    MyString temp = MyString();
////    if (&s1 != &s2)
////    {
////        //先回收自己的内存
////        char *temp = this->str;
////
////        int len = this->length + another.length;
////
////        char *buf = (char *)calloc(len + 1, sizeof(char));
////        strcpy(buf, temp);
////        strcat(buf, another.str);
////
////        //回收自己的内存
////        MyString::deleteThis(this);
////
////        this->str = buf;
////        this->length = len;
////        
////    }
//
//
//    return temp;
//
//}





int main(int argc, const char * argv[])
{

    MyString st1 = MyString();


    return 0;
}