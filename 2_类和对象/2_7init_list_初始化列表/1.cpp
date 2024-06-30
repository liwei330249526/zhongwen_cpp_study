//C++构造函数的初始化列表使得代码更加简洁

#include <iostream>
using namespace std;
class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    Student(char *name, int age, float score);
    void show();
};
//采用初始化列表
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){
    //TODO:
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
int main(){
    Student stu("小明", 15, 92.5f);
    stu.show();
    Student *pstu = new Student("李华", 16, 96);
    pstu -> show();
    return 0;
}

//小明的年龄是15，成绩是92.5
//李华的年龄是16，成绩是96

//如本例所示，定义构造函数时并没有在函数体中对成员变量一一赋值，其函数体为空（当然也可以有其他语句），
// 而是在函数首部与函数体之间添加了一个冒号:，后面紧跟m_name(name), m_age(age), m_score(score)语句，
// 这个语句的意思相当于函数体内部的m_name = name; m_age = age; m_score = score;语句，也是赋值的意思。

//使用构造函数初始化列表并没有效率上的优势，仅仅是书写方便，尤其是成员变量较多时，这种写法非常简单明了。

//初始化列表可以用于全部成员变量，也可以只用于部分成员变量。