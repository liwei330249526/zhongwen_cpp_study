#include <iostream>
using namespace std;

class complex{
public:
    complex();
    complex(double real, double imag);
public:
    void display() const;
    //声明为友元函数
    friend complex operator+(const complex &A, const complex &B);
private:
    double m_real;
    double m_imag;
};

complex operator+(const complex &A, const complex &B);

complex::complex(): m_real(0.0), m_imag(0.0){ }
complex::complex(double real, double imag): m_real(real), m_imag(imag){ }
void complex::display() const{
  cout<<m_real<<" + "<<m_imag<<"i"<<endl;
}

//在全局范围内重载+
complex operator+(const complex &A, const complex &B){
  complex C;
  C.m_real = A.m_real + B.m_real;
  C.m_imag = A.m_imag + B.m_imag;
  return C;
}

int main(){
  complex c1(4.3, 5.8);
  complex c2(2.4, 3.7);
  complex c3;
  c3 = c1 + c2;
  c3.display();

  return 0;
}

//6.7 + 9.5i

//运算符重载函数不是 complex 类的成员函数，但是却用到了 complex 类的 private 成员变量，所以必须在 complex 类中将该函数声明为友元函数。
//当执行c3 = c1 + c2;语句时，编译器检测到+号两边都是 complex 对象，就会转换为类似下面的函数调用：
//c3 = operator+(c1, c2);




//read
//在全局范围内重载运算符
// 运算符重载函数不仅可以作为类的成员函数，还可以作为全局函数。更改上面的代码，在全局范围内重载+，实现复数的加法运算：

//虽然运算符重载所实现的功能完全可以用函数替代，但运算符重载使得程序的书写更加人性化，易于阅读。
//运算符被重载后，原有的功能仍然保留，没有丧失或改变。通过运算符重载，扩大了C++已有运算符的功能，使之能用于对象。