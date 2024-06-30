//但是这里并没有说明 m_engine 该如何处理。在这种情况下，编译器就认为 m_engine 应该用 Engine 类的无参构造函数初始化。

//当封闭类对象消亡时，先执行封闭类的析构函数，然后再执行成员对象的析构函数，
// 成员对象析构函数的执行次序和构造函数的执行次序相反，即先构造的后析构，这是 C++ 处理此类次序问题的一般规律。


#include<iostream>
using namespace std;
class Tyre {
public:
    Tyre() { cout << "Tyre constructor" << endl; }
    ~Tyre() { cout << "Tyre destructor" << endl; }
};
class Engine {
public:
    Engine() { cout << "Engine constructor" << endl; }
    ~Engine() { cout << "Engine destructor" << endl; }
};
class Car {
private:
    Engine engine;
    Tyre tyre;
public:
    Car() { cout << "Car constructor" << endl; }
    ~Car() { cout << "Car destructor" << endl; }
};
int main() {
    Car car;
    return 0;
}

//Engine constructor
//Tyre constructor
//Car constructor
//Car destructor
//Tyre destructor
//Engine destructor