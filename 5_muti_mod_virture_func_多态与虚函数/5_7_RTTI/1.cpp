#include <iostream>
using namespace std;

//基类
class Base{
public:
    virtual void func();
protected:
    int m_a;
    int m_b;
};
void Base::func(){ cout<<"Base"<<endl; }

//派生类
class Derived: public Base{
public:
    void func();
private:
    int m_c;
};
void Derived::func(){ cout<<"Derived"<<endl; }

int main(){
  Base *p;
  int n;

  cin>>n;
  if(n <= 100){
    p = new Base();
  }else{
    p = new Derived();
  }
  cout<<typeid(*p).name()<<endl;

  return 0;
}

//10
//4Base

//110
//7Derived


//从代码中可以看出，用户输入的数字不同，*p表示的对象就不同，typeid 获取到的类型也就不同，编译器在编译期间无法预估用户的输入，
// 所以无法确定*p的类型，必须等到程序真的运行了、用户输入完毕了才能确定*p的类型。
//
//C++ 的对象内存模型主要包含了以下几个方面的内容：
//如果没有虚函数也没有虚继承，那么对象内存模型中只有成员变量。
//如果类包含了虚函数，那么会额外添加一个虚函数表，并在对象内存中插入一个指针，指向这个虚函数表。
//如果类包含了虚继承，那么会额外添加一个虚基类表，并在对象内存中插入一个指针，指向这个虚基类表。

//如果类包含了虚函数，那么该类的对象内存中还会额外增加类型信息，也即 type_info 对象。


//编译器会在虚函数表 vftable 的开头插入一个指针，指向当前类对应的 type_info 对象。
// 当程序在运行阶段获取类型信息时，可以通过对象指针 p 找到虚函数表指针 vfptr，再通过 vfptr 找到 type_info 对象的指针，
// 进而取得类型信息。下面的代码演示了这种转换过程：
//**(p->vfptr - 1)
//程序运行后，不管 p 指向 Base 类对象还是指向 Derived 类对象，只要执行这条语句就可以取得 type_info 对象




// read
//一般情况下，在编译期间就能确定一个表达式的类型，但是当存在多态时，有些表达式的类型在编译期间就无法确定了，
// 必须等到程序运行后根据实际的环境来确定。