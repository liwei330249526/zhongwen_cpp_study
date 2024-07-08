#include <iostream>
using namespace std;

//复数类
class Complex{
public:
    Complex(): m_real(0.0), m_imag(0.0){ }
    Complex(double real, double imag): m_real(real), m_imag(imag){ }
    Complex(double real): m_real(real), m_imag(0.0){ }  //转换构造函数
public:
    friend Complex operator+(const Complex &c1, const Complex &c2);
//    Complex operator+(const Complex &c1, const Complex &c2);
public:
    double real() const{ return m_real; }
    double imag() const{ return m_imag; }
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2){
  Complex c;
  c.m_real = c1.m_real + c2.m_real;
  c.m_imag = c1.m_imag + c2.m_imag;
  return c;
}

int main(){
  Complex c1(25, 35);
  Complex c2 = c1 + 15.6;
  Complex c3 = 28.23 + c1;
  cout<<c2.real()<<" + "<<c2.imag()<<"i"<<endl;
  cout<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;

  return 0;
}

//40.6 + 35i
//53.23 + 35i

//第 30、31 行代码，它说明 Complex 类型可以和 double 类型相加，这很奇怪，因为我们并没有对针对这两个类型重载 +，这究竟是怎么做到的呢？

//其实，编译器在检测到 Complex 和 double（小数默认为 double 类型）相加时，会先尝试将 double 转换为 Complex，
// 或者反过来将 Complex 转换为 double（只有类型相同的数据才能进行 + 运算），如果都转换失败，或者都转换成功（产生了二义性），才报错。
// 本例中，编译器会先通过构造函数Complex(double real);将 double 转换为 Complex，再调用重载过的 + 进行计算

//30 行
//Complex c2 = c1 + 15.6;
//Complex c2 = c1 + Complex(15.6);
//Complex c2 = operator+(c1 + Complex(15.6));
//
//31 行
//Complex c3 = 28.23 + c1;
//Complex c3 = Complex(28.23) + c1;
//Complex c3 = operator+(Complex(28.23) + c1);

//也就是说，小数被转换成了匿名的 Complex 对象。在这个转换过程中，构造函数Complex(double real);
// 起到了至关重要的作用，如果没有它，转换就会失败，Complex 也不能和 double 相加。



//Complex(double real);在作为普通构造函数的同时，还能将 double 类型转换为 Complex 类型，
// 集合了“构造函数”和“类型转换”的功能，所以被称为「转换构造函数」。换句话说，
// 转换构造函数用来将其它类型（可以是 bool、int、double 等基本类型，也可以是数组、指针、结构体、类等构造类型）转换为当前类类型。


// read
//在上节的例子中，我们以全局函数的形式重载了 +、-、*、/、==、!=，以成员函数的形式重载了 +=、-=、*=、/=，而没有一股脑都写成全局函数或者成员函数，这样做是有原因的，

//在分析以前，我们先来了解一个概念，叫做「转换构造函数」。