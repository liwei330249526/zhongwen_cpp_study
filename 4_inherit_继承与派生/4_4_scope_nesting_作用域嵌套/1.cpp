#include<iostream>
using namespace std;

class A{
public:
    void func();
public:
    int n;
};
void A::func(){ cout<<"c.biancheng.net"<<endl; }

class B: public A{
public:
    int n;
    int m;
};

class C: public B{
public:
    int n;
    int x;
};

int main(){
  C obj;
  obj.n;
  obj.func();
  cout<<sizeof(C)<<endl;

  return 0;
}

//c.biancheng.net
//20

//C::B::A 继承关系
//obj 是 C 类的对象，通过 obj 访问成员变量 n 时，在 C 类的作用域中就能够找到了 n 这个名字。
//虽然 A 类和 B 类都有名字 n，但编译器不会到它们的作用域中查找，所以是不可见的，也即派生类中的 n 遮蔽了基类中的 n。

//过 obj 访问成员函数 func() 时，在 C 类的作用域中没有找到 func 这个名字，编译器继续到 B 类的作用域（外层作用域）中查找，
//仍然没有找到，再继续到 A 类的作用域中查找，结果就发现了 func 这个名字，于是查找结束，编译器决定调用 A 类作用域中的 func() 函数。

//这个过程叫做名字查找（name lookup），也就是在作用域链中寻找与所用名字最匹配的声明（或定义）的过程。


//对于成员变量这个过程很好理解，对于成员函数要引起注意，编译器仅仅是根据函数的名字来查找的，不会理会函数的参数。
// 换句话说，一旦内层作用域有同名的函数，不管有几个，编译器都不会再到外层作用域中查找，编译器仅把内层作用域中的这些同名函数作为一组候选函数



// read
//当存在继承关系时，派生类的作用域嵌套在基类的作用域之内，如果一个名字在派生类的作用域内无法找到，
// 编译器会继续到外层的基类作用域中查找该名字的定义。
