#include <iostream>
using namespace std;

//基类People
class People{
public:
    People();  //基类默认构造函数
    People(char *name, int age);
protected:
    char *m_name;
    int m_age;
};
People::People(): m_name("xxx"), m_age(0){ }
People::People(char *name, int age): m_name(name), m_age(age){}

//派生类Student
class Student: public People{
public:
    Student();
    Student(char*, int, float);
public:
    void display();
private:
    float m_score;
};
Student::Student(): m_score(0.0){ }  //派生类默认构造函数
Student::Student(char *name, int age, float score): People(name, age), m_score(score){ }
void Student::display(){
  cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"。"<<endl;
}

int main(){
  Student stu1;
  stu1.display();

  Student stu2("小明", 16, 90.5);
  stu2.display();

  return 0;
}

//xxx的年龄是0，成绩是0。
//小明的年龄是16，成绩是90.5。

//创建对象 stu1 时，执行派生类的构造函数Student::Student()，它并没有指明要调用基类的哪一个构造函数，
// 从运行结果可以很明显地看出来，系统默认调用了不带参数的构造函数，也就是People::People()。
//
//创建对象 stu2 时，执行派生类的构造函数Student::Student(char *name, int age, float score)，它指明了基类的构造函数
//
//在第 27 行代码中，如果将People(name, age)去掉，也会调用默认构造函数，第 37 行的输出结果将变为：
//xxx的年龄是0，成绩是90.5。








//read
//基类构造函数调用规则
//事实上，通过派生类创建对象时必须要调用基类的构造函数，这是语法规定。
// 换句话说，定义派生类构造函数时最好指明基类构造函数；如果不指明，就调用基类的默认构造函数（不带参数的构造函数）；
// 如果没有默认构造函数，那么编译失败。请看下面的例子：