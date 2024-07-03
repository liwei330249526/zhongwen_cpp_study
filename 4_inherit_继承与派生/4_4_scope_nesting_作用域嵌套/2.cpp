#include<iostream>
using namespace std;

//基类Base
class Base{
public:
    void func();
    void func(int);
};
void Base::func(){ cout<<"Base::func()"<<endl; }
void Base::func(int a){ cout<<"Base::func(int)"<<endl; }

//派生类Derived
class Derived: public Base{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *str){ cout<<"Derived::func(char *)"<<endl; }
void Derived::func(bool is){ cout<<"Derived::func(bool)"<<endl; }

int main(){
  Derived d;
  d.func("c.biancheng.net");
  d.func(true);
  d.func();  //compile error
  d.func(10);  //compile error
  d.Base::func();
  d.Base::func(100);

  return 0;
}

//虽然 Derived 类和 Base 类都有同名的 func 函数，但它们位于不同的作用域，Derived 类的 func 会遮蔽 Base 类的 func。
// d 是 Derived 类的对象，调用 func 函数时，编译器会先在 Derived 类中查找“func”这个名字，发现有两个，
// 也即void func(char*)和void func(bool)，这就是一组候选函数。
//
//执行到第 26 行代码时，在候选函数中没有找到匹配的函数，所以调用失败，这时编译器会抛出错误信息，而不是再到 Base 类中查找同名函数。