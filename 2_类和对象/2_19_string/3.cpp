#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "1234567890";
    for(int i=0,len=s.length(); i<len; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    s[5] = '5';
    cout<<s<<endl;
    return 0;
}

//1 2 3 4 5 6 7 8 9 0
//1234557890


//访问字符串中的字符
//string 字符串也可以像C风格的字符串一样按照下标来访问其中的每一个字符。string 字符串的起始下标仍是从 0 开始。
//
//本例定义了一个 string 变量 s，并赋值 "1234567890"，之后用 for 循环遍历输出每一个字符。借助下标，
//除了能够访问每个字符，也可以修改每个字符，s[5] = '5';就将第6个字符修改为 '5'，所以 s 最后为 "1234557890"。

