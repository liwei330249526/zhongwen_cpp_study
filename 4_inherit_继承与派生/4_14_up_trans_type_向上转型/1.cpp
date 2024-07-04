#include <iostream>
using namespace std;

//基类
class A{
public:
    A(int a);
public:
    void display();
public:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
  cout<<"Class A: m_a="<<m_a<<endl;
}

//派生类
class B: public A{
public:
    B(int a, int b);
public:
    void display();
public:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
  cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}


int main(){
  A a(10);
  B b(66, 99);
  //赋值前
  a.display();
  b.display();
  cout<<"--------------"<<endl;
  //赋值后
  a = b;
  a.display();
  b.display();

  return 0;
}

//Class A: m_a=10
//Class B: m_a=66, m_b=99
//        --------------
//Class A: m_a=66
//Class B: m_a=66, m_b=99




//read
//类其实也是一种数据类型，也可以发生数据类型转换，不过这种转换只有在基类和派生类之间才有意义，
// 并且只能将派生类赋值给基类，包括将派生类对象赋值给基类对象、将派生类指针赋值给基类指针、将派生类引用赋值给基类引用，
// 这在 C++ 中称为向上转型（Upcasting）。

//向上转型非常安全，可以由编译器自动完成；向下转型有风险，需要程序员手动干预。

//赋值的本质是将现有的数据写入已分配好的内存中，对象的内存只包含了成员变量，所以对象之间的赋值是成员变量的赋值，
// 成员函数不存在赋值问题。运行结果也有力地证明了这一点，虽然有a=b;这样的赋值过程，
// 但是 a.display() 始终调用的都是 A 类的 display() 函数。

//将派生类对象赋值给基类对象时，会舍弃派生类新增的成员，也就是“大材小用”

//赋值实际上是向内存填充数据，当数据较多时很好处理，舍弃即可；本例中将 b 赋值给 a 时（执行a=b;语句），
// 成员 m_b 是多余的，会被直接丢掉，所以不会发生赋值错误。

