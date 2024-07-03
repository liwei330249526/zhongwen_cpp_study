#include<iostream>
using namespace std;

//基类People
class People{
public:
    void setname(char *name);
    void setage(int age);
    void sethobby(char *hobby);
    char *gethobby();
protected:
    char *m_name;
    int m_age;
private:
    char *m_hobby;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
void People::sethobby(char *hobby){ m_hobby = hobby; }
char *People::gethobby(){ return m_hobby; }

//派生类Student
class Student: public People{
public:
    void setscore(float score);
protected:
    float m_score;
};
void Student::setscore(float score){ m_score = score; }

//派生类Pupil
class Pupil: public Student{
public:
    void setranking(int ranking);
    void display();
private:
    int m_ranking;
};
void Pupil::setranking(int ranking){ m_ranking = ranking; }
void Pupil::display(){
    cout<<m_name<<"的年龄是"<<m_age<<"，考试成绩为"<<m_score<<"分，班级排名第"<<m_ranking<<"，TA喜欢"<<gethobby()<<"。"<<endl;
}

int main(){
    Pupil pup;
    pup.setname("小明");
    pup.setage(15);
    pup.setscore(92.5f);
    pup.setranking(4);
    pup.sethobby("乒乓球");
    pup.display();

    return 0;
}

//小明的年龄是15，考试成绩为92.5分，班级排名第4，TA喜欢乒乓球。


//这是一个多级继承的例子，Student 继承自 People，Pupil 又继承自 Student，它们的继承关系为 People --> Student --> Pupil。
// Pupil 是最终的派生类，它拥有基类的 m_name、m_age、m_score、m_hobby 成员变量以及
// setname()、setage()、sethobby()、gethobby()、setscore() 成员函数。

//注意，在派生类 Pupil 的成员函数 display() 中，我们借助基类的 public 成员函数 gethobby() 来访问基类的 private 成员变量 m_hobby，
// 因为 m_hobby 是 private 属性的，在派生类中不可见，所以只能借助基类的 public 成员函数 sethobby()、gethobby() 来访问。

//在派生类中访问基类 private 成员的唯一方法就是借助基类的非 private 成员函数，
// 如果基类没有非 private 成员函数，那么该成员在派生类中将无法访问。



//1) 基类成员在派生类中的访问权限不得高于继承方式中指定的权限。
//2) 不管继承方式如何，基类中的 private 成员在派生类中始终不能使用（不能在派生类的成员函数中访问或调用）。
//3) 如果希望基类的成员能够被派生类继承并且毫无障碍地使用，那么这些成员只能声明为 public 或 protected；只有那些不希望在派生类中使用的成员才声明为 private。
//
//4) 如果希望基类的成员既不向外暴露（不能通过对象访问），还能在派生类中使用，那么只能声明为 protected。