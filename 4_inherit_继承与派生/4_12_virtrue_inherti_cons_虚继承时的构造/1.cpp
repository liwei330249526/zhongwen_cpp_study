#include <iostream>
using namespace std;

//虚基类A
class A{
public:
    A(int a);
protected:
    int m_a;
};
A::A(int a): m_a(a){ cout << "cons A" << endl; }
//直接派生类C
class C: virtual public A{
public:
    C(int a, int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int a, int c): A(a), m_c(c){  cout << "cons C" << endl; }
void C::display(){
  cout<<"m_a="<<m_a<<", m_c="<<m_c<<endl;
}

//直接派生类B
class B: virtual public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){  cout << "cons B" << endl;}
void B::display(){
  cout<<"m_a="<<m_a<<", m_b="<<m_b<<endl;
}



//间接派生类D
class D: public B, public C{  // 构造函数顺序
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d):B(90, b), A(a), C(100, c), m_d(d){ cout << "cons D" << endl; }
void D::display(){
  cout<<"m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}

int main(){
//  B b(10, 20);
//  b.display();
//
//  C c(30, 40);
//  c.display();
//
  D d(50, 60, 70, 80);
  d.display();
  return 0;
}

//cons A
//cons B
//cons C
//cons D
//m_a=50, m_b=60, m_c=70, m_d=80




// read
//请注意第 50 行代码，在最终派生类 D 的构造函数中，除了调用 B 和 C 的构造函数，还调用了 A 的构造函数，
// 这说明 D 不但要负责初始化直接基类 B 和 C，还要负责初始化间接基类 A。
// 而在以往的普通继承中，派生类的构造函数只负责初始化它的直接基类，再由直接基类的构造函数初始化间接基类，
// 用户尝试调用间接基类的构造函数将导致错误

//现在采用了虚继承，虚基类 A 在最终派生类 D 中只保留了一份成员变量 m_a，
// 如果由 B 和 C 初始化 m_a，那么 B 和 C 在调用 A 的构造函数时很有可能给出不同的实参，
// 这个时候编译器就会犯迷糊，不知道使用哪个实参初始化 m_a。


//为了避免出现这种矛盾的情况，C++ 干脆规定必须由最终的派生类 D 来初始化虚基类 A，直接派生类 B 和 C 对 A 的构造函数的调用是无效的。
// 在第 50 行代码中，调用 B 的构造函数时试图将 m_a 初始化为 90，调用 C 的构造函数时试图将 m_a 初始化为 100，
// 但是输出结果有力地证明了这些都是无效的，m_a 最终被初始化为 50，这正是在 D 中直接调用 A 的构造函数的结果。