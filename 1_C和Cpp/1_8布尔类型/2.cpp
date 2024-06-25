//bool 是类型名字，也是 C++ 中的关键字，它的用法和 int、char、long 是一样的，请看下面的例子
#include <iostream>
using namespace std;
int main(){
    int a, b;
    bool flag;  //定义布尔变量
    cin>>a>>b;
    flag = a > b;
    cout<<"flag = "<<flag<<endl;
    return 0;
}

//10
//20
//flag = 0

//遗憾的是，在 C++ 中使用 cout 输出 bool 变量的值时还是用数字 1 和 0 表示，而不是 true 或 false