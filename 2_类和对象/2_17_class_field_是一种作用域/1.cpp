#include<iostream>
using namespace std;

class A{
public:
    typedef int INT;
    static void show();
    void work();
};
void A::show(){ cout<<"show()"<<endl; }
void A::work(){ cout<<"work()"<<endl; }

int main(){
    A a;
    a.work();  //通过对象访问普通成员
    a.show();  //通过对象访问静态成员
    A::show();  //通过类访问静态成员
    A::INT n = 10;  //通过类访问 typedef 定义的类型

    return 0;
}

//work()
//show()
//show()






//
//类其实也是一种作用域，每个类都会定义它自己的作用域。在类的作用域之外，普通的成员只能通过对象（可以是对象本身，也可以是对象指针或对象引用）来访问，
//静态成员既可以通过对象访问，又可以通过类访问，而 typedef 定义的类型只能通过类来访问。




