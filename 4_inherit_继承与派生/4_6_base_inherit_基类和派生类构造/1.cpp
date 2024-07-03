#include<iostream>
using namespace std;

//基类People
class People{
protected:
    char *m_name;
    int m_age;
public:
    People(char*, int);
};
People::People(char *name, int age): m_name(name), m_age(age){}

//派生类Student
class Student: public People{
private:
    float m_score;
public:
    Student(char *name, int age, float score);
    void display();
};
//People(name, age)就是调用基类的构造函数
Student::Student(char *name, int age, float score): People(name, age), m_score(score){ }
void Student::display(){
  cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"。"<<endl;
}

int main(){
  Student stu("小明", 16, 90.5);
  stu.display();

  return 0;
}

//小明的年龄是16，成绩是90.5

//请注意第 23 行代码：
//People(name, age)就是调用基类的构造函数，并将 name 和 age 作为实参传递给它，m_score(score)是派生类的参数初始化表，它们之间以逗号,隔开。






//read
//前面我们说基类的成员函数可以被继承，可以通过派生类的对象访问，但这仅仅指的是普通的成员函数，类的构造函数不能被继承。

//在设计派生类时，对继承过来的成员变量的初始化工作也要由派生类的构造函数完成，但是大部分基类都有 private 属性的成员变量，
// 它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。

//这种矛盾在C++继承中是普遍存在的，解决这个问题的思路是：在派生类的构造函数中调用基类的构造函数。


//构造函数的调用顺序
//从上面的分析中可以看出，基类构造函数总是被优先调用，这说明创建派生类对象时，会先调用基类构造函数，再调用派生类构造函数
//构造函数的调用顺序是按照继承的层次自顶向下、从基类再到派生类的。