//在 C++ 中，一个类中可以有 public、protected、private 三种属性的成员，通过对象可以访问 public 成员，
//只有本类中的函数可以访问本类的 private 成员。
//现在，我们来介绍一种例外情况——友元（friend）。
//借助友元（friend），可以使得其他类中的成员函数以及全局范围内的函数访问当前类的 private 成员。

//
//在当前类以外定义的、不属于当前类的函数也可以在类中声明，但要在前面加 friend 关键字，这样就构成了友元函数。
//友元函数可以是不属于任何类的非成员函数，也可以是其他类的成员函数。
//
//友元函数可以访问当前类中的所有成员，包括 public、protected、private 属性的。
//
//1) 将非成员函数声明为友元函数。

#include <iostream>
using namespace std;
class Student{
public:
    Student(char *name, int age, float score);
public:
    friend void show(Student *pstu);  //将show()声明为友元函数  // 如果去掉， error: ‘int Student::m_age’ is private within this context
private:
private:
private:
    char *m_name;
    int m_age;
    float m_score;
};
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
//非成员函数
void show(Student *pstu){
    cout<<pstu->m_name<<"的年龄是 "<<pstu->m_age<<"，成绩是 "<<pstu->m_score<<endl;
}
int main(){
    Student stu("小明", 15, 90.6);
    show(&stu);  //调用友元函数
    Student *pstu = new Student("李磊", 16, 80.5);
    show(pstu);  //调用友元函数
    return 0;
}

//小明的年龄是15，成绩是90.6
//李磊的年龄是16，成绩是80.5

//show() 是一个全局范围内的非成员函数，它不属于任何类，它的作用是输出学生的信息。m_name、m_age、m_score 是 Student 类的 private 成员，
//原则上不能通过对象访问，但在 show() 函数中又必须使用这些 private 成员，所以将 show() 声明为 Student 类的友元函数。