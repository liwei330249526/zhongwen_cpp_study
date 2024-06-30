
//对象的内存中包含了成员变量，不同的对象占用不同的内存（已在《C++对象的内存模型》中提到），这使得不同对象的成员变量相互独立，它们的值不受其他对象的影响
//例如有两个相同类型的对象 a、b，它们都有一个成员变量 m_name，那么修改 a.m_name 的值不会影响 b.m_name 的值。

//可是有时候我们希望在多个对象之间共享数据，对象 a 改变了某份数据后对象 b 可以检测到。
//共享数据的典型使用场景是计数，以前面的 Student 类为例，如果我们想知道班级中共有多少名学生，就可以设置一份共享的变量，每次创建对象时让该变量加 1。

//static 成员变量不占用对象的内存，而是在所有对象之外开辟内存，即使不创建对象也可以访问。

#include <iostream>
using namespace std;
class Student{
public:
    Student(char *name, int age, float score);
    void show();
private:
    static int m_total;  //静态成员变量
private:
    char *m_name;
    int m_age;
    float m_score;
};
//初始化静态成员变量
int Student::m_total = 0;  // 如果不初始化 undefined reference to 陈`Student::m_total'
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){
    m_total++;  //操作静态成员变量
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"（当前共有"<<m_total<<"名学生）"<<endl;
}
int main(){
    //创建匿名对象
    (new Student("小明", 15, 90)) -> show();
    (new Student("李磊", 16, 80)) -> show();
    (new Student("张华", 16, 99)) -> show();
    (new Student("王康", 14, 60)) -> show();
//    cout << Student::m_total << endl;  //error: ‘int Student::m_total’ is private within this context
    return 0;
}

//小明的年龄是15，成绩是90（当前共有1名学生）
//李磊的年龄是16，成绩是80（当前共有2名学生）
//张华的年龄是16，成绩是99（当前共有3名学生）
//王康的年龄是14，成绩是60（当前共有4名学生

//本例中将 m_total 声明为静态成员变量，每次创建对象时，会调用构造函数使 m_total 的值加 1。
//
//之所以使用匿名对象，是因为每次创建对象后只会使用它的 show() 函数，不再进行其他操作。
//不过使用匿名对象无法回收内存，会导致内存泄露，在中大型程序中不建议使用。



//1) 一个类中可以有一个或多个静态成员变量，所有的对象都共享这些静态成员变量，都可以引用它。
//
//2) static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。
//这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。

//3) 静态成员变量必须初始化，而且只能在类体外进行。例如：
//初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0。
//全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。

//4) 静态成员变量既可以通过对象名访问，也可以通过类名访问，但要遵循 private、protected 和 public 关键字的访问权限限制。
//当通过对象名访问时，对于不同的对象，访问的是同一份内存。