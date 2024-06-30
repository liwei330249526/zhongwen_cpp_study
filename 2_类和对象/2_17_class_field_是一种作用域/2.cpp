#include<iostream>
using namespace std;

class A{
public:
    typedef char* PCHAR;
public:
    void show(PCHAR str);
    PCHAR show2(PCHAR str);
    A::PCHAR show3(PCHAR str);
private:
    int n;
};
void A::show(PCHAR str){
    cout<<str<<endl;
    n = 10;
}

int main(){
    A obj;
    obj.show("http://c.biancheng.net");
    obj.show3("http://c.biancheng.net");
    return 0;
}

//http://c.biancheng.net
//http://c.biancheng.net


//我们在定义 show() 函数时用到了类 A 中定义的一种类型 PCHAR，因为前面已经指明了当前正位于 A 类的作用域中，
//所以不用再使用A::PCHAR这样的冗余形式。同理，编译器也知道函数体中用到的变量 n 也位于 A 类的作用域。


//另一方面，函数的返回值类型出现在函数名之前，当成员函数定义在类的外部时，
//返回值类型中使用的名字都位于类的作用域之外，此时必须指明该名字是哪个类的成员。

//PCHAR A::show2(PCHAR str){  ///error: ‘PCHAR’ does not name a type
//    cout<<str<<endl;
//    n = 10;
//    return str;
//}


//这种写法是错误的。因为返回值类型 PCHAR 出现在类名之前，所以事实上它是位于 A 类的作用域之外的。
//这种情况下要想使用 PCHAR 作为返回值类型，就必须指明哪个类定义了它，正确的写法如下所示：
A::PCHAR A::show3(PCHAR str){
    cout<<str<<endl;
    n = 10;
    return str;
}