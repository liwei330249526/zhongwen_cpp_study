//【例2】cin 连续输入示例：
#include<iostream>
using namespace std;
int main(){
    int x;
    float y;
    cout<<"Please input an int number and a float number:"<<endl;
    cin>>x>>y;
    cout<<"The int number is x= "<<x<<endl;
    cout<<"The float number is y= "<<y<<endl;
    return 0;
}

//初学者可能会觉得 cout、cin 的用法非常奇怪，它们既不是类似 printf()、scanf() 的函数调用，
// 也不是关键字，请大家先保留这个疑问，我们会在《C++运算符重载》一章中为你揭开谜底。