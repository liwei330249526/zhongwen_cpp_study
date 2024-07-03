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
    int m_b;  //遮蔽A类的成员变量
    int m_c;  //遮蔽B类的成员变量
    int m_d;  //新增成员变量
};
C::C(char a, int b, int c, int d): B(a, b, c), m_b(1), m_c(2), m_d(3){ }
void C::display(){
  printf("A::m_a=%d, A::m_b=%d, B::m_c=%d\n", m_a, A::m_b, B::m_c);
  printf("a=%d C::m_b=%d, C::m_c=%d, C::m_d=%d\n", m_a, m_b, m_c, m_d);
}

int main() {
  //创建C类对象obj_c
  C obj_c(84, 23, 95, 60);
  obj_c.display();
  return 0;
}

//A::m_a=84, A::m_b=23, B::m_c=95
//a=84 C::m_b=1, C::m_c=2, C::m_d=3

//obj_c  内存模型
//A::m_a  94
//A::m_b  23
//
//B::m_c  95
//
//C::m_b  1
//C::m_c  2
//C::m_d  3

//当基类 A、B 的成员变量被遮蔽时，仍然会留在派生类对象 obj_c 的内存中，C 类新增的成员变量始终排在基类 A、B 的后面。