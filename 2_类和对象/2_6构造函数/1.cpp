//在C++中，有一种特殊的成员函数，它的名字和类名相同，没有返回值，不需要用户显式调用（用户也不能调用），
//而是在创建对象时自动执行。这种特殊的成员函数就是构造函数（Constructor）

#include <iostream>
using namespace std;
class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    //声明构造函数
    Student(char *name, int age, float score);
    //声明普通成员函数
    void show();
};
//定义构造函数
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
//定义普通成员函数
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
int main(){
    //创建对象时向构造函数传参
    Student stu("小明", 15, 92.5f);
    stu.show();
    //创建对象时向构造函数传参
    Student *pstu = new Student("李华", 16, 96);
    pstu -> show();
    return 0;
}

//小明的年龄是15，成绩是92.5
//李华的年龄是16，成绩是96

//构造函数必须是 public 属性的，否则创建对象时无法调用