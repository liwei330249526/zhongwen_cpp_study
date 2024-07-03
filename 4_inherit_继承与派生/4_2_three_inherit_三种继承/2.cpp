#include<iostream>
using namespace std;

//基类People
class People {
public:
    void show();
protected:
    char *m_name;
    int m_age;
};
void People::show() {
    cout << m_name << "的年龄是" << m_age << endl;
}

//派生类Student
class Student : public People {
public:
    void learning();
public:
    using People::m_name;  //将protected改为public
    using People::m_age;  //将protected改为public
    float m_score;
private:
    using People::show;  //将public改为private
};
void Student::learning() {
    cout << "我是" << m_name << "，今年" << m_age << "岁，这次考了" << m_score << "分！" << endl;
}

int main() {
    Student stu;
    stu.m_name = "小明";
    stu.m_age = 16;
    stu.m_score = 99.5f;
    stu.show();  //compile error
    stu.learning();

    return 0;
}

//error: ‘void People::show()’ is inaccessible within this context



//代码中首先定义了基类 People，它包含两个 protected 属性的成员变量和一个 public 属性的成员函数。
// 定义 Student 类时采用 public 继承方式，People 类中的成员在 Student 类中的访问权限默认是不变的。
//
//不过，我们使用 using 改变了它们的默认访问权限，如代码第 21~25 行所示，将 show() 函数修改为 private 属性的，
// 是降低访问权限，将 name、age 变量修改为 public 属性的，是提高访问权限。
//
//因为 show() 函数是 private 属性的，所以代码第 36 行会报错



//使用 using 关键字可以改变基类成员在派生类中的访问权限，例如将 public 改为 private、将 protected 改为 public
