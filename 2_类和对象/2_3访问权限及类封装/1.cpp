//C++通过 public、protected、private 三个关键字来控制成员变量和成员函数的访问权限，
//它们分别表示公有的、受保护的、私有的，被称为成员访问限定符。所谓访问权限，就是你能不能使用该类中的成员。
//
//在类的内部（定义类的代码内部），无论成员被声明为 public、protected 还是 private，都是可以互相访问的，没有访问权限的限制。
//
//在类的外部（定义类的代码之外），只能通过对象访问成员，并且通过对象只能访问 public 属性的成员，不能访问 private、protected 属性的成员

#include <iostream>
using namespace std;
//类的声明
class Student{
private:  //私有的
    char *m_name;
    int m_age;
    float m_score;
public:  //共有的
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
//成员函数的定义
void Student::setname(char *name){
    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
int main(){
    //在栈上创建对象
    Student stu;
    stu.setname("小明");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();
    //在堆上创建对象
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();
    return 0;
}

//小明的年龄是15，成绩是92.5
//李华的年龄是16，成绩是96
//
//
//类的声明和成员函数的定义都是类定义的一部分，在实际开发中，我们通常将类的声明放在头文件中，而将成员函数的定义放在源文件中。
//
//成员变量大都以m_开头，这是约定成俗的写法，不是语法规定的内容。以m_开头既可以一眼看出这是成员变量，又可以和成员函数中的形参名字区分开。

//因为三个成员变量都是私有的，不能通过对象直接访问，所以必须借助三个 public 属性的成员函数来修改它们的值。


//这种将成员变量声明为 private、将部分成员函数声明为 public 的做法体现了类的封装性。
//所谓封装，是指尽量隐藏类的内部实现，只向用户提供有用的成员函数。

//声明为 private 的成员和声明为 public 的成员的次序任意，既可以先出现 private 部分，
// 也可以先出现 public 部分。如果既不写 private 也不写 public，就默认为 private。
//
//在一个类体中，private 和 public 可以分别出现多次。每个部分的有效范围到出现另一个访问限定符或类体结束时（最后一个右花括号）为止。
// 但是为了使程序清晰，应该养成这样的习惯，使每一种成员访问限定符在类定义体中只出现一次。