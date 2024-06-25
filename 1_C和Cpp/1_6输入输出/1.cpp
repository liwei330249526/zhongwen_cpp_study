#include<iostream>
using namespace std;
//【例1】简单的输入输出代码示例：
int main(){
    int x;
    float y;
    cout<<"Please input an int number:"<<endl;
    cin>>x;
    cout<<"The int number is x= "<<x<<endl;
    cout<<"Please input a float number:"<<endl;
    cin>>y;
    cout<<"The float number is y= "<<y<<endl;
    return 0;
}

//Please input an int number:
//1
//The int number is x= 1
//Please input a float number:
//2.0
//The float number is y= 2

//在编写 C++ 程序时，如果需要使用输入输出时，则需要包含头文件iostream，

// 它包含了用于输入输出的对象，例如常见的cin表示标准输入、cout表示标准输出、cerr表示标准错误。

//输出"Please input a int number:"这样的一个字符串，以提示用户输入整数，其中endl表示换行，与C语言里的\n作用相同。