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
    virtual void display();  //声明为虚函数
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
  cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
  People p("王志刚", 23);
  Teacher t("赵宏佳", 45, 8200);

  People &rp = p;
  People &rt = t;

  rp.display();
  rt.display();

  return 0;
}

//王志刚今年23岁了，是个无业游民。
//赵宏佳今年45岁了，是一名教师，每月有8200元的收入。

//借助引用也可以实现多态。

//不过引用不像指针灵活，指针可以随时改变指向，而引用只能指代固定的对象，在多态性方面缺乏表现力，
// 所以以后我们再谈及多态时一般是说指针。本例的主要目的是让读者知道，除了指针，引用也可以实现多态。