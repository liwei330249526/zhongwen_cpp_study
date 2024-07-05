#include <iostream>
using namespace std;

//基类
class Base{
public:
    Base();
    ~Base();
protected:
    char *str;
};
Base::Base(){
  str = new char[100];
  cout<<"Base constructor"<<endl;
}
Base::~Base(){
  delete[] str;
  cout<<"Base destructor"<<endl;
}

//派生类
class Derived: public Base{
public:
    Derived();
    ~Derived();
private:
    char *name;
};
Derived::Derived(){
  name = new char[100];
  cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
  delete[] name;
  cout<<"Derived destructor"<<endl;
}

int main(){
  Base *pb = new Derived();
  delete pb;

  cout<<"-------------------"<<endl;

  Derived *pd = new Derived();
  delete pd;

  return 0;
}

//Base constructor
//Derived constructor
//Base destructor
//-------------------
//Base constructor
//Derived constructor
//Derived destructor
//Base destructor

//从运行结果可以看出，语句delete pb;只调用了基类的析构函数，没有调用派生类的析构函数；
// 而语句delete pd;同时调用了派生类和基类的析构函数。

//在本例中，不调用派生类的析构函数会导致 name 指向的 100 个 char 类型的内存空间得不到释放；
// 除非程序运行结束由操作系统回收，否则就再也没有机会释放这些内存。这是典型的内存泄露。

//1) 为什么delete pb;不会调用派生类的析构函数呢？
//因为这里的析构函数是非虚函数，通过指针访问非虚函数时，编译器会根据指针的类型来确定要调用的函数
//
//2) 为什么delete pd;会同时调用派生类和基类的析构函数呢？
//pd 是派生类的指针，编译器会根据它的类型匹配到派生类的析构函数，在执行派生类的析构函数的过程中，又会调用基类的析构函数。
//派生类析构函数始终会调用基类的析构函数，并且这个过程是隐式完成的



//read
//上节我们讲到，构造函数不能是虚函数，因为派生类不能继承基类的构造函数，将构造函数声明为虚函数没有意义。
//这是原因之一，另外还有一个原因：C++ 中的构造函数用于在创建对象时进行初始化工作，在执行构造函数之前对象尚未创建完成，
//虚函数表尚不存在，也没有指向虚函数表的指针，所以此时无法查询虚函数表，也就不知道要调用哪一个构造函数。

//析构函数用于在销毁对象时进行清理工作，可以声明为虚函数，而且有时候必须要声明为虚函数。