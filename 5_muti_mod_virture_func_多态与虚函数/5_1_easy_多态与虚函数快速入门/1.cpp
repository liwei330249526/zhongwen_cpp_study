#include <iostream>
using namespace std;

//基类People
class People{
public:
    People(char *name, int age);
    void display();
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
    void display();
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
//赵宏佳今年45岁了，是个无业游民。

//我们直观上认为，如果指针指向了派生类对象，那么就应该使用派生类的成员变量和成员函数，这符合人们的思维习惯。
// 但是本例的运行结果却告诉我们，当基类指针 p 指向派生类 Teacher 的对象时，虽然使用了 Teacher 的成员变量，但是却没有使用它的成员函数

//换句话说，通过基类指针只能访问派生类的成员变量，但是不能访问派生类的成员函数。


//换句话说，通过基类指针只能访问派生类的成员变量，但是不能访问派生类的成员函数。