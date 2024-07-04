#include <iostream>
using namespace std;

//基类A
class A{
public:
    A(int a);
public:
    void display();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
  cout<<"Class A: m_a="<<m_a<<endl;
}

//中间派生类B
class B: public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
  cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}

//基类C
class C{
public:
    C(int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int c): m_c(c){ }
void C::display(){
  cout<<"Class C: m_c="<<m_c<<endl;
}

//最终派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d): B(a, b), C(c), m_d(d){ }
void D::display(){
  cout<<"Class D: m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}

int main(){
  D d(4, 40, 400, 4000);

  A &ra = d;
  B &rb = d;
  C &rc = d;

  ra.display();
  rb.display();
  rc.display();

  return 0;
}

//Class A: m_a=4
//Class B: m_a=4, m_b=40
//Class C: m_c=400

//将派生类引用赋值给基类引用

//ra、rb、rc 是基类的引用，它们都引用了派生类对象 d，并调用了 display() 函数，
// 从运行结果可以发现，虽然使用了派生类对象的成员变量，但是却没有使用派生类的成员函数，这和指针的表现是一样的。