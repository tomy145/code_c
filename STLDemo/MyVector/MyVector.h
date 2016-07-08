


#ifndef MyVector_h
#define MyVector_h

#include <iostream>



template <class T>
class MyVector
{

public:


    MyVector()
    {
        std::cout << "MyVector ( )  --- init " << std::endl;
    }

    MyVector(int len)
    {
        this->length = len;
        if (this->length != 0)
        {
            this->array = new T[this->length];
        }

        std::cout << " MyVector(int len) --- len = " << this->length << std::endl;

    }

    MyVector(const MyVector & another)
    {

        this->length = another.length;

        if (this->length != 0) //开辟空间
        {
            this->array = new T[this->length];
        }

        for ( int i = 0; i < this->length; i++) //拷贝
        {
            this->array[i] = another.array[i];
        }

    }

    MyVector & operator= (const MyVector &another) //= 号操作符重载
    {
        if (this != &another)
        {

            //先清除之前的数据
            this->length = 0;
            if (this->array != nullptr)
            {
                delete [] this->array;
            }


            //赋值
            this->length = another->lenght;

            if (this->length != 0) //开辟空间
            {
                this->array = new T[this->length];
            }

            
            for ( int i = 0; i < this->length; i++) //拷贝
            {
                this->array[i] = another->array[i];
            }

        }

        return *this;
    }

    //[]重载
    T & operator[](int index)
    {
        return this->array[index];
    }

    //<<
    std::ostream & operator<< (std::ostream & os) ;

    T * & getArray()
    {
        return this->array;
    }

    int getLength()
    {
        return this->length;
    }

    std::string getTypeName()
    {
        return typeid(this).name();
    }

    ~MyVector()
    {
        this->length = 0;
        if (this->array != nullptr)
        {
            delete[] this->array;
        }
    }
    
private:
    int length;
    T *array;
    
    
};


template <class T>
std::ostream & operator<< (std::ostream & os , MyVector<T> &another )
{

    for (int i = 0; i < another.getLength(); i++)
    {
        os << "another->array[" << i << "] = " << another.getArray()[i] << std::endl;
    }

    return os;
    
}



#endif /* MyVector_h */
