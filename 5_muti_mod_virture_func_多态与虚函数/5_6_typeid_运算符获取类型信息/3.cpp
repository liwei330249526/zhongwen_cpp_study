#include <iostream>
#include <typeinfo>
using namespace std;
class Base{};
class Derived: public Base{};

int main() {
  Base obj1;
  Base *p1;
  Derived obj2;
  Derived *p2 = new Derived;
  p1 = p2;

  cout << (typeid(obj1) == typeid(p1)) << endl;  // 0
  cout << (typeid(&obj1) == typeid(p1)) << endl; // 1
  cout << (typeid(obj1) == typeid(Base)) << endl; // 1
  cout << (typeid(p1) == typeid(Base*)) << endl; // 1

  cout << "" << endl;
  cout << (typeid(obj1) == typeid(*p1)) << endl; // 1
  cout << (typeid(obj1) == typeid(obj2)) << endl; // 0
  cout << (typeid(*p1) == typeid(Base)) << endl;  // 1
  cout << (typeid(p1) == typeid(Derived*)) << endl; // 0


  return 0;
}

//0
//1
//1
//1
//
//1
//0
//1
//0



//表达式typeid(*p1) == typeid(Base)和typeid(p1) == typeid(Base*)的结果为 true 可以说明：
// 即使将派生类指针 p2 赋值给基类指针 p1，p1 的类型仍然为 Base*。