#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2, s3;
    s1 = s2 = "1234567890";
    s3 = "aaa";
    s1.insert(5, s3);
    cout<< s1 <<endl;
    s2.insert(5, "bbb");
    cout<< s2 <<endl;
    return 0;
}
//
//12345aaa67890
//12345bbb67890


//它的一种原型为：
//string& insert (size_t pos, const string& str);
//
//pos 表示要插入的位置，也就是下标；str 表示要插入的字符串，它可以是 string 字符串，也可以是C风格的字符串



//一. 插入字符串
//insert() 函数可以在 string 字符串中指定的位置插入另一个字符串

