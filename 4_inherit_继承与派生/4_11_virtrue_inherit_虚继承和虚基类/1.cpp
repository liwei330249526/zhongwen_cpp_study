//间接基类A
class A{
protected:
    int m_a;
};

//直接基类B
class B: public A{
protected:
    int m_b;
};

//直接基类C
class C: public A{
protected:
    int m_c;
};

//派生类D
class D: public B, public C{
public:
//    void seta(int a){ m_a = a; }  //命名冲突
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确

    void setab(int a){ B::m_a = a; }  //解决命名冲突
    void setac(int a){ C::m_a = a; }  //解决命名冲突
private:
    int m_d;
};

int main(){
  D d;
  return 0;
}

//这段代码实现了上图所示的菱形继承，第 22 行代码试图直接访问成员变量 m_a，结果发生了错误，因为类 B 和类 C 中都有成员变量 m_a（从 A 类继承而来），编译器不知道选用哪一个，所以产生了歧义。

//为了消除歧义，我们可以在 m_a 的前面指明它具体来自哪个类：
//void seta(int a){ B::m_a = a; }
//这样表示使用 B 类的 m_a。当然也可以使用 C 类的：
//void seta(int a){ C::m_a = a; }







//read
//多继承（Multiple Inheritance）是指从多个直接基类中产生派生类的能力，多继承的派生类继承了所有父类的成员。
// 尽管概念上非常简单，但是多个基类的相互交织可能会带来错综复杂的设计问题，命名冲突就是不可回避的一个。

//多继承时很容易产生命名冲突，即使我们很小心地将所有类中的成员变量和成员函数都命名为不同的名字，命名冲突依然有可能发生，比如典型的是菱形继承

/**
 *
 *                     A
 *                  B     C
 *                     D
 *
 * */

//类 A 派生出类 B 和类 C，类 D 继承自类 B 和类 C，这个时候类 A 中的成员变量和成员函数继承到类 D 中变成了两份，
// 一份来自 A-->B-->D 这条路径，另一份来自 A-->C-->D 这条路径。

//在一个派生类中保留间接基类的多份同名成员，虽然可以在不同的成员变量中分别存放不同的数据，但大多数情况下这是多余的：
// 因为保留多份成员变量不仅占用较多的存储空间，还容易产生命名冲突。假如类 A 有一个成员变量 a，那么在类 D 中直接访问 a 就会产生歧义，
// 编译器不知道它究竟来自 A -->B-->D 这条路径，还是来自 A-->C-->D 这条路径。



