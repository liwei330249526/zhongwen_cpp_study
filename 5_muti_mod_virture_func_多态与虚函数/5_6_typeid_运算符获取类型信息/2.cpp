#include <iostream>
#include <typeinfo>
using namespace std;


int main(){
  char *str;
  int a = 2;
  int b = 10;
  float f;

  cout << (typeid(int) == typeid(int)) << endl;  // 1
  cout << (typeid(char*) == typeid(char)) << endl; // 0
  cout << (typeid(a) == typeid(int)) << endl;  // 1
  cout << (typeid(a) == typeid(a)) << endl;  // 1
  cout << (typeid(a) == typeid(f)) << endl;  // 0

  cout<< "" << endl;
  cout << (typeid(int) == typeid(char)) << endl;  // 0
  cout << (typeid(str) == typeid(char*)) << endl;  // 1
  cout << (typeid(b) == typeid(int)) << endl;  // 1
  cout << (typeid(a) == typeid(b)) << endl;  // 1
  cout << (typeid(a/b) == typeid(int)) << endl;  // 1


}

//1
//0
//1
//1
//0
//
//0
//1
//1
//1
//1

//typeid 返回 type_info 对象的引用，而表达式typeid(a) == typeid(b)的结果为 true，
// 可以说明，一个类型不管使用了多少次，编译器都只为它创建一个对象，所有 typeid 都返回这个对象的引用。

//需要提醒的是，为了减小编译后文件的体积，编译器不会为所有的类型创建 type_info 对象，只会为使用了 typeid 运算符的类型创建。
// 不过有一种特殊情况，就是带虚函数的类（包括继承来的），不管有没有使用 typeid 运算符，
// 编译器都会为带虚函数的类创建 type_info 对象，

