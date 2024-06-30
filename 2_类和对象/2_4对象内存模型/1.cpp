//不同对象的成员变量的值可能不同，需要单独分配内存来存储。但是不同对象的成员函数的代码是一样的
//
//编译器会将成员变量和成员函数分开存储：分别为每个对象的成员变量分配内存，但是所有对象都共享同一段函数代码。
//
//成员变量在堆区或栈区分配内存，成员函数在代码区分配内存。
//
//【示例】使用 sizeof 获取对象所占内存的大小


#include <iostream>
using namespace std;
class Student{
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
};
void Student::setname(char *name){
//    m_name = name;
}
void Student::setage(int age){
    m_age = age;
}
void Student::setscore(float score){
    m_score = score;
}
void Student::show(){
//    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
int main(){
    //在栈上创建对象
    Student stu;
    cout<<sizeof(stu)<<endl;
    //在堆上创建对象
    Student *pstu = new Student();
    cout<<sizeof(*pstu)<<endl;
    //类的大小
    cout<<sizeof(Student)<<endl;
    return 0;
}

//16
//16
//16

//Student 类包含三个成员变量，它们的类型分别是 char *、int、float
//
//对象所占用的内存仅仅包含了成员变量
//
//类可以看做是一种复杂的数据类型，也可以使用 sizeof 求得该类型的大小。
//从运行结果可以看出，在计算类这种类型的大小时，只计算了成员变量的大小，并没有把成员函数也包含在内。