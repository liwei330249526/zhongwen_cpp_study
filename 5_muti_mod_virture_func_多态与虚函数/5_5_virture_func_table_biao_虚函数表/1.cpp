#include <iostream>
#include <string>
using namespace std;

//People类
class People{
public:
    People(string name, int age);
public:
    virtual void display();
    virtual void eating();
protected:
    string m_name;
    int m_age;
};
People::People(string name, int age): m_name(name), m_age(age){ }
void People::display(){
  cout<<"Class People："<<m_name<<"今年"<<m_age<<"岁了。"<<endl;
}
void People::eating(){
  cout<<"Class People：我正在吃饭，请不要跟我说话..."<<endl;
}

//Student类
class Student: public People{
public:
    Student(string name, int age, float score);
public:
    virtual void display();
    virtual void examing();
protected:
    float m_score;
};
Student::Student(string name, int age, float score):
        People(name, age), m_score(score){ }
void Student::display(){
  cout<<"Class Student："<<m_name<<"今年"<<m_age<<"岁了，考了"<<m_score<<"分。"<<endl;
}
void Student::examing(){
  cout<<"Class Student："<<m_name<<"正在考试，请不要打扰T啊！"<<endl;
}

//Senior类
class Senior: public Student{
public:
    Senior(string name, int age, float score, bool hasJob);
public:
    virtual void display();
    virtual void partying();
private:
    bool m_hasJob;
};
Senior::Senior(string name, int age, float score, bool hasJob):
        Student(name, age, score), m_hasJob(hasJob){ }
void Senior::display(){
  if(m_hasJob){
    cout<<"Class Senior："<<m_name<<"以"<<m_score<<"的成绩从大学毕业了，并且顺利找到了工作，Ta今年"<<m_age<<"岁。"<<endl;
  }else{
    cout<<"Class Senior："<<m_name<<"以"<<m_score<<"的成绩从大学毕业了，不过找工作不顺利，Ta今年"<<m_age<<"岁。"<<endl;
  }
}
void Senior::partying(){
  cout<<"Class Senior：快毕业了，大家都在吃散伙饭..."<<endl;
}

int main(){
  People *p = new People("赵红", 29);
  p -> display();

  p = new Student("王刚", 16, 84.5);
  p -> display();

  p = new Senior("李智", 22, 92.0, true);
  p -> display();

  return 0;
}
//Class People：赵红今年29岁了。
//Class Student：王刚今年16岁了，考了84.5分。
//Class Senior：李智以92的成绩从大学毕业了，并且顺利找到了工作，Ta今年22岁。

//仔细观察虚函数表，可以发现基类的虚函数在 vtable 中的索引（下标）是固定的，
//不会随着继承层次的增加而改变，派生类新增的虚函数放在 vtable 的最后。
//如果派生类有同名的虚函数遮蔽（覆盖）了基类的虚函数，那么将使用派生类的虚函数替换基类的虚函数，
//这样具有遮蔽关系的虚函数在 vtable 中只会出现一次。

//当通过指针调用虚函数时，先根据指针找到 vfptr，再根据 vfptr 找到虚函数的入口地址。


//read
//前面我们一再强调，当通过指针访问类的成员函数时：
//如果该函数是非虚函数，那么编译器会根据指针的类型找到该函数；也就是说，指针是哪个类的类型就调用哪个类的函数
//如果该函数是虚函数，并且派生类有同名的函数遮蔽它，那么编译器会根据指针的指向找到该函数；
//也就是说，指针指向的对象属于哪个类就调用哪个类的函数。这就是多态。

//编译器之所以能通过指针指向的对象找到虚函数，是因为在创建对象时额外地增加了虚函数表

//如果一个类包含了虚函数，那么在创建该类的对象时就会额外地增加一个数组，数组中的每一个元素都是虚函数的入口地址。
//不过数组和对象是分开存储的，为了将对象和数组关联起来，编译器还要在对象中安插一个指针，指向数组的起始位置。
//这里的数组就是虚函数表（Virtual function table）


//https://c.biancheng.net/view/vip_2300.html