#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "first second third";
    string s2 = "second";
    int index = s1.find(s2,5);
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}

//Found at index : 6

//find() 函数最终返回的是子字符串第一次出现在字符串中的起始下标。本例最终是在下标 6 处找到了 s2 字符串。
//如果没有查找到子字符串，那么会返回 string::npos，它是 string 类内部定义的一个静态常成员，用来表示 size_t 类型所能存储的最大值。






//find() 函数
//find() 函数用于在 string 字符串中查找子字符串出现的位置，它其中的两种原型为：
//size_t find (const string& str, size_t pos = 0) const;
//size_t find (const char* s, size_t pos = 0) const;
//
//第一个参数为待查找的子字符串，它可以是 string 字符串，也可以是C风格的字符串。
//第二个参数为开始查找的位置（下标）；如果不指明，则从第0个字符开始查找。
