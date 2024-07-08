#include <iostream>
using namespace std;

class complex{
public:
    complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ };
public:
    friend complex operator+(const complex & A, const complex & B);
    friend complex operator-(const complex & A, const complex & B);
    friend complex operator*(const complex & A, const complex & B);
    friend complex operator/(const complex & A, const complex & B);
    friend istream & operator>>(istream & in, complex & A);
    friend ostream & operator<<(ostream & out, complex & A);
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

//重载加法运算符
complex operator+(const complex & A, const complex &B){
  complex C;
  C.m_real = A.m_real + B.m_real;
  C.m_imag = A.m_imag + B.m_imag;
  return C;
}

//重载减法运算符
complex operator-(const complex & A, const complex &B){
  complex C;
  C.m_real = A.m_real - B.m_real;
  C.m_imag = A.m_imag - B.m_imag;
  return C;
}

//重载乘法运算符
complex operator*(const complex & A, const complex &B){
  complex C;
  C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
  C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
  return C;
}

//重载除法运算符
complex operator/(const complex & A, const complex & B){
  complex C;
  double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
  C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag)/square;
  C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag)/square;
  return C;
}

//重载输入运算符
istream & operator>>(istream & in, complex & A){
  in >> A.m_real >> A.m_imag;
  return in;
}

//重载输出运算符
ostream & operator<<(ostream & out, complex & A){
  out << A.m_real <<" + "<< A.m_imag <<" i ";;
  return out;
}

int main(){
  complex c1, c2, c3;
  cin>>c1>>c2;

  c3 = c1 + c2;
  cout<<"c1 + c2 = "<<c3<<endl;

  c3 = c1 - c2;
  cout<<"c1 - c2 = "<<c3<<endl;

  c3 = c1 * c2;
  cout<<"c1 * c2 = "<<c3<<endl;

  c3 = c1 / c2;
  cout<<"c1 / c2 = "<<c3<<endl;

  return 0;
}

//1 1
//2 2
//c1 + c2 = 3 + 3 i
//c1 - c2 = -1 + -1 i
//c1 * c2 = 0 + 4 i
//c1 / c2 = 2 + 0 i






//read
//在C++中，标准库本身已经对左移运算符<<和右移运算符>>分别进行了重载，使其能够用于不同数据的输入输出，
// 但是输入输出的对象只能是 C++ 内置的数据类型（例如 bool、int、double 等）和标准库所包含的类类型（例如 string、complex、ofstream、ifstream 等）

//如果我们自己定义了一种新的数据类型，需要用输入输出运算符去处理，那么就必须对它们进行重载。本节以前面的 complex 类为例来演示输入输出运算符的重载。

//其实 C++ 标准库已经提供了 complex 类，能够很好地支持复数运算，但是这里我们又自己定义了一个 complex 类，这样做仅仅是为了教学演示。


//下面我们以全局函数的形式重载>>，使它能够读入两个 double 类型的数据，并分别赋值给复数的实部和虚部：
//istream & operator>>(istream &in, complex &A){
//  in >> A.m_real >> A.m_imag;
//  return in;
//}

//istream 表示输入流，cin 是 istream 类的对象，只不过这个对象是在标准库中定义的。之所以返回 istream 类对象的引用，是为了能够连续读取复数，让代码书写更加漂亮，例如：
//complex c1, c2;
//cin>>c1>>c2;
//
//如果不返回引用，那就只能一个一个地读取了：
//complex c1, c2;
//cin>>c1;
//cin>>c2;
//
//另外，运算符重载函数中用到了 complex 类的 private 成员变量，必须在 complex 类中将该函数声明为友元函数：
//friend istream & operator>>(istream & in , complex &a);


//同样地，我们也可以模仿上面的形式对输出运算符>>进行重载，让它能够输出复数，请看下面的代码：
//ostream & operator<<(ostream &out, complex &A){
//  out << A.m_real <<" + "<< A.m_imag <<" i ";
//  return out;
//}
//ostream 表示输出流，cout 是 ostream 类的对象。由于采用了引用的方式进行参数传递，并且也返回了对象的引用，所以重载后的运算符可以实现连续输出。
//
//为了能够直接访问 complex 类的 private 成员变量，同样需要将该函数声明为 complex 类的友元函数：