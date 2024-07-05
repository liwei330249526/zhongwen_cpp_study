#include <iostream>
using namespace std;

//基类People
class People{
public:
    People(char *name, int age);
    virtual void display();  //声明为虚函数
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
  cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    virtual void display();  //声明为虚函数    子类加不加virtual  ke 都可以
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
  cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
  People *p = new People("王志刚", 23);
  p -> display();

  p = new Teacher("赵宏佳", 45, 8200);
  p -> display();

  return 0;
}

//王志刚今年23岁了，是个无业游民。
//赵宏佳今年45岁了，是一名教师，每月有8200元的收入。

//本例仅仅是在 display() 函数声明前加了一个virtual关键字，将成员函数声明为了虚函数（Virtual Function），
// 这样就可以通过 p 指针调用 Teacher 类的成员函数了

//有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。
// 换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，
// 我们将这种现象称为多态（Polymorphism）。

//C++中虚函数的唯一用处就是构成多态。