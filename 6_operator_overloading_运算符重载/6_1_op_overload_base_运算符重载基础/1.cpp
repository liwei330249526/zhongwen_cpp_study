#include <iostream>
using namespace std;

class complex{
public:
    complex();
    complex(double real, double imag);
public:
    //声明运算符重载
    complex operator+(const complex &A) const;
    void display() const;
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

complex::complex(): m_real(0.0), m_imag(0.0){ }
complex::complex(double real, double imag): m_real(real), m_imag(imag){ }

//实现运算符重载
complex complex::operator+(const complex &A) const{
  complex B;
  B.m_real = this->m_real + A.m_real;
  B.m_imag = this->m_imag + A.m_imag;
  return B;
}

void complex::display() const{
  cout<<m_real<<" + "<<m_imag<<"i"<<endl;
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

//本例中义了一个复数类 complex，m_real 表示实部，m_imag 表示虚部，第 10 行声明了运算符重载，第 21 行进行了实现（定义）。
//认真观察这两行代码，可以发现运算符重载的形式与函数非常类似。


//运算符重载其实就是定义一个函数，在函数体内实现想要的功能，当用到该运算符时，编译器会自动调用这个函数。
//也就是说，运算符重载是通过函数实现的，它本质上是函数重载。

//operator是关键字，专门用于定义重载运算符的函数。我们可以将operator 运算符名称这一部分看做函数名，对于上面的代码，函数名就是operator+。

//运算符重载函数除了函数名有特定的格式，其它地方和普通函数并没有区别。


//上面的例子中，我们在 complex 类中重载了运算符+，该重载只对 complex 对象有效。当执行c3 = c1 + c2;
//语句时，编译器检测到+号左边（+号具有左结合性，所以先检测左边）是一个 complex 对象，就会调用成员函数operator+()，也就是转换为下面的形式：
//c3 = c1.operator+(c2);
//c1 是要调用函数的对象，c2 是函数的实参。


// read
//所谓重载，就是赋予新的含义。函数重载（Function Overloading）可以让一个函数名有多种功能，在不同情况下进行不同的操作。
// 运算符重载（Operator Overloading）也是一个道理，同一个运算符可以有不同的功能。


//实际上，我们已经在不知不觉中使用了运算符重载。例如，+号可以对不同类型（int、float 等）的数据进行加法操作；
//<<既是位移运算符，又可以配合 cout 向控制台输出数据。C++ 本身已经对这些运算符进行了重载。