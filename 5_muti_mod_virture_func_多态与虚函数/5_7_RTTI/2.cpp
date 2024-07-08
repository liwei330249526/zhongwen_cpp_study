#include <iostream>
using namespace std;

//基类
class People{
public:
    virtual void func(){ }
};

//派生类
class Student: public People{ };

int main(){
  People *p;
  int n;

  cin>>n;
  if(n <= 100){
    p = new People();
  }else{
    p = new Student();
  }

  //根据不同的类型进行不同的操作
  if(typeid(*p) == typeid(People)){
    cout<<"I am human."<<endl;
  }else{
    cout<<"I am a student."<<endl;
  }

  return 0;
}

//10
//I am human.
//110
//I am a student.

// read
//上面是 RTTI  机制的一个具体应用，可以让代码根据不同的类型进行不同的操作：


//多态（Polymorphism）是面向对象编程的一个重要特征，它极大地增加了程序的灵活性，C++、C#、Java 等“正统的”面向对象编程语言都支持多态。
// 但是支持多态的代价也是很大的，有些信息在编译阶段无法确定下来，必须提前做好充足的准备，让程序运行后再执行一段代码获取，
// 这会消耗更多的内存和 CPU 资源。