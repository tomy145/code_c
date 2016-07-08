#include <iostream>

using namespace std;

int main ()
 {
    cout << "Hello, World!" << endl;
     char ch = 0;

     while((ch = cin.get()) != EOF)
     {
     	cin.clear(); //清空缓冲区 ，配合sync一起使用
        cin.sync();
        cout << "您输入的字符是 - " << ch << endl;
        
     }

     
    
    return 0;
}
