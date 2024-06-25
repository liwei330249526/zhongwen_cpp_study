//类是创建对象的模板，一个类可以创建多个对象，每个对象都是类类型的一个变量；
// 创建对象的过程也叫类的实例化。每个对象都是类的一个具体实例（Instance），拥有类的成员变量和成员函数。

//一个简单的类的定义：
//class Student{
//public:
//    //成员变量
//    char *name;
//    int age;
//    float score;
//    //成员函数
//    void say(){
//        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
//    }
//};

//class是 C++ 中新增的关键字，专门用来定义
//Student是类的名称；类名的首字母一般大写，以和其他的标识符区分开
//public也是 C++ 的新增关键字，它只能用在类的定义中，表示类的成员变量或成员函数具有“公开”的访问权限，
//注意在类定义的最后有一个分号;，它是类定义的一部分，表示类定义结束了，不能省略

//整体上讲，上面的代码创建了一个 Student 类，它包含了 3 个成员变量和 1 个成员函数

//创建对象
//
//有了 Student 类后，就可以通过它来创建对象了，例如：
//Student liLei;  //创建对象
//
//Student是类名，liLei是对象名。这和使用基本类型定义变量的形式类似：
//int a;  //定义整型变量
//
//除了创建单个对象，还可以创建对象数组：
//Student allStu[100];


//创建对象以后，可以使用点号.来访问成员变量和成员函数，这和通过结构体变量来访问它的成员类似，如下所示：

#include <iostream>
using namespace std;
//类通常定义在函数外面
class Student{
public:
    //类包含的变量
    char *name;
    int age;
    float score;
    //类包含的函数
    void say(){
        cout<<name<<"的年龄是"<<age<<"，成绩是"<<score<<endl;
    }
};
int main(){
    //创建对象
    Student stu;
    stu.name = "小明";
    stu.age = 15;
    stu.score = 92.5f;
    stu.say();
    return 0;
}
//小明的年龄是15，成绩是92.5

//stu 是一个对象，占用内存空间，可以对它的成员变量赋值，也可以读取它的成员变量。