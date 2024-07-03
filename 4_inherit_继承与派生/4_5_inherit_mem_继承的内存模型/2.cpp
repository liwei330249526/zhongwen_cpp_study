#include <cstdio>
using namespace std;

//基类A
class A{
public:
    A(int a, int b);
public:
    void display();
protected:
    int m_a;
    int m_b;
};
A::A(int a, int b): m_a(a), m_b(b){}
void A::display(){
  printf("m_a=%d, m_b=%d\n", m_a, m_b);
}

//派生类B
class B: public A{
public:
    B(int a, int b, int c);
    void display();
protected:
    int m_c;
};
B::B(int a, int b, int c): A(a, b), m_c(c){ }
void B::display(){
  printf("m_a=%d, m_b=%d, m_c=%d\n", m_a, m_b, m_c);
}

//声明并定义派生类C
class C: public B{
public:
    C(char a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
C::C(char a, int b, int c, int d): B(a, b, c), m_d(d){ }
void C::display(){
  printf("m_a=%d, m_b=%d, m_c=%d, m_d=%d\n", m_a, m_b, m_c, m_d);
}



int main(){
//  A obj_a(99, 10);
//  B obj_b(84, 23, 95);
//  obj_a.display();
//  obj_b.display();

  //创建C类对象obj_c
  C obj_c(84, 23, 95, 60);
  obj_c.display();

  return 0;
}

//m_a=84, m_b=23, m_c=95, m_d=60

//obj_c 内存
//m_a
//m_b
//m_c
//m_d   新增成员变量

//成员变量按照派生的层级依次排列，新增成员变量始终在最后。
