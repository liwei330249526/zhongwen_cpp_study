#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "first second third";
    string s2;
    s2 = s1.substr(6, 6);
    cout<< s1 <<endl;
    cout<< s2 <<endl;
    return 0;
}


//first second third
//second



//提取子字符串
//substr() 函数用于从 string 字符串中提取子字符串，它的原型为：
//string substr (size_t pos = 0, size_t len = npos) const;
//
//pos 为要提取的子字符串的起始下标，len 为要提取的子字符串的长度。

//系统对 substr() 参数的处理和 erase() 类似：
//如果 pos 越界，会抛出异常；
//如果 len 越界，会提取从 pos 到字符串结尾处的所有字符。