#include <iostream>
using namespace std;

class A{
public:
    A(int a, int b, int c);
private:
    int m_a;
    int m_b;
    int m_c;
};
A::A(int a, int b, int c): m_a(a), m_b(b), m_c(c){ }

int main(){
//  A obj(10, 20, 30);
//  int a = obj.m_a;  //Compile Error
//  A *p = new A(40, 50, 60);
//  int b = p->m_b;  //Compile Error


  A obj(10, 20, 30);
  int a1 = *(int*)&obj;
  int b1 = *(int*)( (int*)&obj + 1 );
  int c1 = *(int*)( (int*)&obj + 2 );

  A *p = new A(40, 50, 60);
  int a2 = *(int*)p;
  int b2 = *(int*)( (int*)p + 1 );
  int c2 = *(int*)( (int*)p + 2 );

  cout<<"a1="<<a1<< ", b1="<<b1 << ", c1=" << c1 << ", a2="<<a2<< " b2=" << b2 << ", c2="<<c2<<endl;
  return 0;
}
//a1=10, b1=20, c1=30, a2=40 b2=50, c2=60


//这段代码说明了，无论通过对象变量还是对象指针，都不能访问 private 属性的成员变量。
//前面我们说 C++ 的成员访问权限仅仅是语法层面上的，是指访问权限仅对取成员运算符.和->起作用，而无法防止直接通过指针来访问。
// 你可以认为这是指针的强大，也可以认为是 C++ 语言设计的瑕疵。

//本节的目的不是为了访问到 private、protected 属性的成员变量，这种“花拳绣腿”没有什么现实的意义，
// 本节主要是让大家明白编译器内部的工作原理，以及指针的灵活运用。

