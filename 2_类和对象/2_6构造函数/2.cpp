//和普通成员函数一样，构造函数是允许重载的。一个类可以有多个重载的构造函数，创建对象时根据传递的实参来判断调用哪一个构造函数

//更改示例1的代码，再添加一个构造函数（示例2）：

#include <iostream>
using namespace std;
class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    Student();
    Student(char *name, int age, float score);
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
Student::Student(){
    m_name = NULL;
    m_age = 0;
    m_score = 0.0;
}
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
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
    if(m_name == NULL || m_age <= 0){
        cout<<"成员变量还未初始化"<<endl;
    }else{
        cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
    }
}
int main(){
    //调用构造函数 Student(char *, int, float)
    Student stu("小明", 15, 92.5f);
    stu.show();
    //调用构造函数 Student()
    Student *pstu = new Student();
    pstu -> show();
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();
    return 0;
}

//小明的年龄是15，成绩是92.5
//成员变量还未初始化
//李华的年龄是16，成绩是96


//构造函数Student(char *, int, float)为各个成员变量赋值，构造函数Student()将各个成员变量的值设置为空，
//它们是重载关系。根据Student()创建对象时不会赋予成员变量有效值，所以还要调用成员函数 setname()、setage()、setscore() 来给它们重新赋值。
//
//构造函数在实际开发中会大量使用，它往往用来做一些初始化工作，例如对成员变量赋值、预先打开文件等