#include <iostream>
using namespace std;
class Student{
public:
    void setname(char *name);
    void setage(int age);
    void setscore(float score);
    void show();
    void printThis();
private:
    char *name;
    int age;
    float score;
};
void Student::setname(char *name){
    this->name = name;
}
void Student::setage(int age){
    this->age = age;
}
void Student::setscore(float score){
    this->score = score;
}
void Student::show(){
    cout<<this->name<<"的年龄是"<<this->age<<"，成绩是"<<this->score<<endl;
}

void Student::printThis(){
    cout<<this<<endl;
}

int main(){
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96.5);
    pstu -> show();

    cout << "----test2----" << endl;

    Student *pstu1 = new Student;
    pstu1 -> printThis();
    cout<<pstu1<<endl;
    Student *pstu2 = new Student;
    pstu2 -> printThis();
    cout<<pstu2<<endl;
    return 0;
}

//李华的年龄是16，成绩是96.5
//----test2----
//0x55bfb15c72e0
//0x55bfb15c72e0
//0x55bfb15c7300
//0x55bfb15c7300


//this 只能用在类的内部，通过 this 可以访问类的所有成员，包括 private、protected、public 属性的。


//this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。

//几点注意：
//this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
//this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
//只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。


//this 作为隐式形参，本质上是成员函数的局部变量，所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给 this 赋值。



//成员函数最终被编译成与对象无关的普通函数，除了成员变量，会丢失所有信息，所以编译时要在成员函数中添加一个额外的参数，
//把当前对象的首地址传入，以此来关联成员函数和成员变量。这个额外的参数，实际上就是 this，它是成员函数和成员变量关联的桥梁。