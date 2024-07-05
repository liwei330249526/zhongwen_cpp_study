#include <iostream>
using namespace std;

//基类
class Base{
public:
    Base();
    virtual ~Base();
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
//Derived destructor
//Base destructor
//-------------------
//Base constructor
//Derived constructor
//Derived destructor
//Base destructor


//将基类的析构函数声明为虚函数：

//将基类的析构函数声明为虚函数后，派生类的析构函数也会自动成为虚函数。这个时候编译器会忽略指针的类型，而根据指针的指向来选择函数；
//也就是说，指针指向哪个类的对象就调用哪个类的函数。pb、pd 都指向了派生类的对象，所以会调用派生类的析构函数，继而再调用基类的析构函数。
//如此一来也就解决了内存泄露的问题。
//
//在实际开发中，一旦我们自己定义了析构函数，就是希望在对象销毁时用它来进行清理工作，比如释放内存、关闭文件等，如果这个类又是一个基类，
//那么我们就必须将该析构函数声明为虚函数，否则就有内存泄露的风险。也就是说，大部分情况下都应该将基类的析构函数声明为虚函数。