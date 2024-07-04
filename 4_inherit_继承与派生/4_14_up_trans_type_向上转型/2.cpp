#include <iostream>
using namespace std;

//基类A
class A{
public:
    A(int a);
public:
    void display();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
  cout<<"Class A: m_a="<<m_a<<endl;
}

//中间派生类B
class B: public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
  cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}

//基类C
class C{
public:
    C(int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int c): m_c(c){ }
void C::display(){
  cout<<"Class C: m_c="<<m_c<<endl;
}

//最终派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d): B(a, b), C(c), m_d(d){ }
void D::display(){
  cout<<"Class D: m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}


int main(){
  A *pa = new A(1);
  B *pb = new B(2, 20);
  C *pc = new C(3);
  D *pd = new D(4, 40, 400, 4000);

  pa = pd;
  pa -> display();

  pb = pd;
  pb -> display();

  pc = pd;
  pc -> display();

  cout<<"-----------------------"<<endl;
  cout<<"pa="<<pa<<endl;
  cout<<"pb="<<pb<<endl;
  cout<<"pc="<<pc<<endl;
  cout<<"pd="<<pd<<endl;

  return 0;
}

//Class A: m_a=4
//Class B: m_a=4, m_b=40
//Class C: m_c=400
//-----------------------
//pa=0x560ad85a7f10
//pb=0x560ad85a7f10
//pc=0x560ad85a7f18
//pd=0x560ad85a7f10


//除了可以将派生类对象赋值给基类对象（对象变量之间的赋值），还可以将派生类指针赋值给基类指针（对象指针之间的赋值）

//本例中定义了多个对象指针，并尝试将派生类指针赋值给基类指针。与对象变量之间的赋值不同的是，对象指针之间的赋值并没有拷贝对象的成员，
// 也没有修改对象本身的数据，仅仅是改变了指针的指向。

//1) 通过基类指针访问派生类的成员
//请读者先关注第 68 行代码，我们将派生类指针 pd 赋值给了基类指针 pa，从运行结果可以看出，
//调用 display() 函数时虽然使用了派生类的成员变量，但是 display() 函数本身却是基类的。
// 也就是说，将派生类指针赋值给基类指针时，通过基类指针只能使用派生类的成员变量，但不能使用派生类的成员函数，
// 这看起来有点不伦不类，究竟是为什么呢？第 71、74 行代码也是类似的情况。

//概括起来说就是：编译器通过指针来访问成员变量，指针指向哪个对象就使用哪个对象的数据；
// 编译器通过指针的类型来访问成员函数，指针属于哪个类的类型就使用哪个类的函数。

//2) 赋值后值不一致的情况
//本例中我们将最终派生类的指针 pd 分别赋值给了基类指针 pa、pb、pc，按理说它们的值应该相等，都指向同一块内存，
// 但是运行结果却有力地反驳了这种推论，只有 pa、pb、pd 三个指针的值相等，pc 的值比它们都大。也就是说，执行pc = pd;
// 语句后，pc 和 pd 的值并不相等。