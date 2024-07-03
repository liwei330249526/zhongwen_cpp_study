#include<iostream>
using namespace std;

//基类 Pelple
class People{
public:
    void setname(char *name);
    void setage(int age);
    char *getname();
    int getage();
private:
    char *m_name;
    int m_age;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
char* People::getname(){ return m_name; }
int People::getage(){ return m_age;}

//派生类 Student
class Student: public People{
public:
    void setscore(float score);
    float getscore();
private:
    float m_score;
};
void Student::setscore(float score){ m_score = score; }
float Student::getscore(){ return m_score; }

int main(){
    Student stu;
    stu.setname("小明");
    stu.setage(16);
    stu.setscore(95.5f);
    cout<<stu.getname()<<"的年龄是 "<<stu.getage()<<"，成绩是 "<<stu.getscore()<<endl;

    return 0;
}
//小明的年龄是 16，成绩是 95.5

//本例中，People 是基类，Student 是派生类。Student 类继承了 People 类的成员，同时还新增了自己的成员变量 score 和成员函数 setscore()、getscore()。
//这些继承过来的成员，可以通过子类对象访问，就像自己的一样。


// start
//继承（Inheritance）可以理解为一个类从另一个类获取成员变量和成员函数的过程
//以下是两种典型的使用继承的场景：
//1) 当你创建的新类与现有的类相似，只是多出若干成员变量或成员函数时，可以使用继承，这样不但会减少代码量，而且新类会拥有基类的所有功能。
//2) 当你需要创建多个类，它们拥有很多相似的成员变量或成员函数时，也可以使用继承。可以将这些类的共同成员提取出来，定义为基类，然后从基类继承，
//既可以节省代码，也方便后续修改成员。