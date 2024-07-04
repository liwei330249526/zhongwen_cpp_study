
#include <iostream>
using namespace std;

//基类
class BaseA{
public:
    BaseA(int a, int b);
    ~BaseA();
protected:
    int m_a;
    int m_b;
};
BaseA::BaseA(int a, int b): m_a(a), m_b(b){
  cout<<"BaseA constructor"<<endl;
}
BaseA::~BaseA(){
  cout<<"BaseA destructor"<<endl;
}

//基类
class BaseB{
public:
    BaseB(int c, int d);
    ~BaseB();
protected:
    int m_c;
    int m_d;
};
BaseB::BaseB(int c, int d): m_c(c), m_d(d){
  cout<<"BaseB constructor"<<endl;
}
BaseB::~BaseB(){
  cout<<"BaseB destructor"<<endl;
}

//派生类
class Derived: public BaseA, public BaseB{
public:
    Derived(int a, int b, int c, int d, int e);
    ~Derived();
public:
    void show();
private:
    int m_e;
};
Derived::Derived(int a, int b, int c, int d, int e):BaseB(c, d), BaseA(a, b) , m_e(e){
  cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
  cout<<"Derived destructor"<<endl;
}
void Derived::show(){
  cout<<m_a<<", "<<m_b<<", "<<m_c<<", "<<m_d<<", "<<m_e<<endl;
}

int main(){
  Derived obj(1, 2, 3, 4, 5);
  obj.show();
  return 0;
}

//BaseA constructor
//BaseB constructor
//Derived constructor
//1, 2, 3, 4, 5
//Derived destructor
//BaseB destructor
//BaseA destructor

//从运行结果中还可以发现，多继承形式下析构函数的执行顺序和构造函数的执行顺序相反。
//基类构造函数的调用顺序和和它们在派生类构造函数中出现的顺序无关，而是和声明派生类时基类出现的顺序相同。






// read
//继承（Multiple Inheritance），即一个派生类可以有两个或多个基类。
//多继承的语法也很简单，将多个基类用逗号隔开即可。例如已声明了类A、类B和类C，那么可以这样来声明派生类D：
//class D: public A, private B, protected C{
//    //类D新增加的成员
//}