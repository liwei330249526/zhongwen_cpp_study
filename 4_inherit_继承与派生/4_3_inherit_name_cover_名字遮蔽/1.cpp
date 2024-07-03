#include<iostream>
using namespace std;

//基类People
class People{
public:
    void show();
protected:
    char *m_name;
    int m_age;
};
void People::show(){
  cout<<"嗨，大家好，我叫"<<m_name<<"，今年"<<m_age<<"岁"<<endl;
}

//派生类Student
class Student: public People{
public:
    Student(char *name, int age, float score);
public:
    void show();  //遮蔽基类的show()
private:
    float m_score;
};
Student::Student(char *name, int age, float score){
  m_name = name;
  m_age = age;
  m_score = score;
}
void Student::show(){
  cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
  Student stu("小明", 16, 90.5);
  //使用的是派生类新增的成员函数，而不是从基类继承的
  stu.show();
  //使用的是从基类继承来的成员函数
  stu.People::show();

  return 0;
}

//小明的年龄是16，成绩是90.5
//嗨，大家好，我叫小明，今年16岁

//本例中，基类 People 和派生类 Student 都定义了成员函数 show()，它们的名字一样，会造成遮蔽。
//第 37 行代码中，stu 是 Student 类的对象，默认使用 Student 类的 show() 函数。
//
//但是，基类 People 中的 show() 函数仍然可以访问，不过要加上类名和域解析符，如第 39 行代码所示。










//如果派生类中的成员（包括成员变量和成员函数）和基类中的成员重名，那么就会遮蔽从基类继承过来的成员。
// 所谓遮蔽，就是在派生类中使用该成员（包括在定义派生类时使用，也包括通过派生类对象访问该成员）时，
// 实际上使用的是派生类新增的成员，而不是从基类继承来的。
