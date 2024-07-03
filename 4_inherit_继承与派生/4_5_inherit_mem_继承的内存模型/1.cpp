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

int main(){
  A obj_a(99, 10);
  B obj_b(84, 23, 95);
  obj_a.display();
  obj_b.display();

  return 0;
}

//m_a=99, m_b=10
//m_a=84, m_b=23, m_c=95

//obj_a 是基类对象，obj_b 是派生类对象。
//obj_a 内存如下
//m_a
//m_b
//
//obj_b 内存如下
//m_a
//m_b
//m_c

//可以发现，基类的成员变量排在前面，派生类的排在后面。








//read
//有继承关系时，派生类的内存模型可以看成是基类成员变量和新增成员变量的总和，而所有成员函数仍然存储在另外一个区域——代码区，由所有对象共享