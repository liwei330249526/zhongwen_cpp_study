#include <iostream>
using namespace std;

class Address;  //提前声明Address类
//Address a; //error: aggregate ‘Address a’ has incomplete type and cannot be defined
//声明Student类
class Student{
public:
    Student(char *name, int age, float score);
public:
    void show(Address *addr);
private:
    char *m_name;
    int m_age;
    float m_score;
};

//声明Address类
class Address{
private:
    char *m_province;  //省份
    char *m_city;  //城市
    char *m_district;  //区（市区）
public:
    Address(char *province, char *city, char *district);
    //将Student类中的成员函数show()声明为友元函数
    friend void Student::show(Address *addr);
};

//实现Student类
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
void Student::show(Address *addr){
    cout<<m_name<<"的年龄是 "<<m_age<<"，成绩是 "<<m_score<<endl;
    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
}

//实现Address类
Address::Address(char *province, char *city, char *district){
    m_province = province;
    m_city = city;
    m_district = district;
}

//小明的年龄是 16，成绩是 95.5
//家庭住址：陕西省西安市雁塔区
//李磊的年龄是 16，成绩是 80.5
//家庭住址：河北省衡水市桃城区

int main(){
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);

    Student *pstu = new Student("李磊", 16, 80.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu -> show(paddr);

    return 0;
}

//小明的年龄是 16，成绩是 95.5
//家庭住址：陕西省西安市雁塔区
//李磊的年龄是 16，成绩是 80.5
//家庭住址：河北省衡水市桃城区

//2) 将其他类的成员函数声明为友元函数

//本例定义了两个类 Student 和 Address，程序第 27 行将 Student 类的成员函数 show() 声明为 Address 类的友元函数，由此，
//show() 就可以访问 Address 类的 private 成员变量了。

//① 程序第 4 行对 Address 类进行了提前声明，是因为在 Address 类定义之前、在 Student 类中使用到了它，
//如果不提前声明，编译器会报错，提示'Address' has not been declared。类的提前声明和函数的提前声明是一个道理。
//
//② 程序将 Student 类的声明和实现分开了，而将 Address 类的声明放在了中间，这是因为编译器从上到下编译代码，
//show() 函数体中用到了 Address 的成员 province、city、district，如果提前不知道 Address 的具体声明内容，
//就不能确定 Address 是否拥有该成员（类的声明中指明了类有哪些成员）。

//但是应当注意，类的提前声明的使用范围是有限的，只有在正式声明一个类以后才能用它去创建对象。
//如果在上面程序的第4行之后增加如下所示的一条语句，编译器就会报错：
///error: aggregate ‘Address a’ has incomplete type and cannot be defined
//
//因为创建对象时要为对象分配内存，在正式声明类之前，编译器无法确定应该为对象分配多大的内存。
//编译器只有在“见到”类的正式声明后（其实是见到成员变量），才能确定应该为对象预留多大的内存。在对一个类作了提前声明后，
//可以用该类的名字去定义指向该类型对象的指针变量（本例就定义了 Address 类的指针变量）或引用变量（后续会介绍引用），
//因为指针变量和引用变量本身的大小是固定的，与它所指向的数据的大小无关。

//③ 一个函数可以被多个类声明为友元函数，这样就可以访问多个类中的 private 成员。