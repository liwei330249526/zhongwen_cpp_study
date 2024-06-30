#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4 (5, 's');

    string s = "http://c.biancheng.net";
    int len = s.length();  //22  输出结果为22。由于 string 的末尾没有'\0'字符，所以 length() 返回的是字符串的真实长度，而不是长度 +1。
    cout<<len<<endl;
    return 0;
}
//变量 s1 只是定义但没有初始化，编译器会将默认值赋给 s1，默认值是""，也即空字符串。
//
//变量 s2 在定义的同时被初始化为"c plus plus"。与C风格的字符串不同，string 的结尾没有结束标志'\0'。
//
//变量 s3 在定义的时候直接用 s2 进行初始化，因此 s3 的内容也是"c plus plus"。
//
//变量 s4 被初始化为由 5 个's'字符组成的字符串，也就是"sssss"。


//C++ 大大增强了对字符串的支持，除了可以使用C风格的字符串，还可以使用内置的 string 类


//虽然 C++ 提供了 string 类来替代C语言中的字符串，但是在实际编程中，有时候必须要使用C风格的字符串（例如打开文件时的路径），
//为此，string 类为我们提供了一个转换函数 c_str()，该函数能够将 string 字符串转换为C风格的字符串，
//并返回该字符串的 const 指针（const char*）。请看下面的代码：
//string path = "D:\\demo.txt";
//FILE *fp = fopen(path.c_str(), "rt");
