#include <iostream>
using namespace std;
class Complex
{
    double real, imag;
public:
    Complex(double r = 0, double i = 0) :real(r), imag(i) {};
    operator double() { return real; }  //重载强制类型转换运算符 double
};
int main()
{
  Complex c(1.2, 3.4);
  cout << (double)c << endl;  //输出 1.2
  double n = 2 + c;  //等价于 double n = 2 + c. operator double()
  cout << n;  //输出 3.2
}

//1.2
//3.2

//第 8 行对 double 运算符进行了重载。重载强制类型转换运算符时，不需要指定返回值类型，因为返回值类型是确定的，就是运算符本身代表的类型，在这里就是 double。
//
//重载后的效果是，第 13 行的(double)c等价于c.operator double()。



//read
//在 C++ 中，类型的名字（包括类的名字）本身也是一种运算符，即类型强制转换运算符。
//类型强制转换运算符是单目运算符，也可以被重载，但只能重载为成员函数，不能重载为全局函数。
//经过适当重载后，(类型名)对象这个对对象进行强制类型转换的表达式就等价于对象.operator 类型名()，即变成对运算符函数的调用。