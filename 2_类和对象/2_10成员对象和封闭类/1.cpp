//一个类的成员变量如果是另一个类的对象，就称之为“成员对象”

//创建封闭类的对象时，它包含的成员对象也需要被创建，这就会引发成员对象构造函数的调用。

//对于基本类型的成员变量，“参数表”中只有一个值，就是初始值，在调用构造函数时，会把这个初始值直接赋给成员变量。
//
//但是对于成员对象，“参数表”中存放的是构造函数的参数，它可能是一个值，也可能是多个值，它指明了该成员对象如何被初始化。


#include <iostream>
using namespace std;
//轮胎类
class Tyre{
public:
    Tyre(int radius, int width);
    void show() const;
private:
    int m_radius;  //半径
    int m_width;  //宽度
};
Tyre::Tyre(int radius, int width) : m_radius(radius), m_width(width){ }
void Tyre::show() const {
    cout << "轮毂半径：" << this->m_radius << "吋" << endl;
    cout << "轮胎宽度：" << this->m_width << "mm" << endl;
}
//引擎类
class Engine{
public:
    Engine(float displacement = 2.0);
    void show() const;
private:
    float m_displacement;
};
Engine::Engine(float displacement) : m_displacement(displacement) {}
void Engine::show() const {
    cout << "排量：" << this->m_displacement << "L" << endl;
}
//汽车类
class Car{
public:
    Car(int price, int radius, int width);
    void show() const;
private:
    int m_price;  //价格
    Tyre m_tyre;
    Engine m_engine;
};
Car::Car(int price, int radius, int width): m_price(price), m_tyre(radius, width)/*指明m_tyre对象的初始化方式*/{ };
void Car::show() const {
    cout << "价格：" << this->m_price << "￥" << endl;
    this->m_tyre.show();
    this->m_engine.show();
}
int main()
{
    Car car(200000, 19, 245);
    car.show();
    return 0;
}


//价格：200000￥
//轮毂半径：19吋
//轮胎宽度：245mm
//排量：2L

//Car 是一个封闭类，它有两个成员对象：m_tyre 和 m_engine。

//编译器已经知道这里的 car 对象是用第 48 行的 Car(int price, int radius, int width) 构造函数初始化的，
//那么 m_tyre 和 m_engine 该如何初始化，就要看第 48 行后面的初始化列表了
//m_tyre 应以 radius 和 width 作为参数调用 Tyre(int radius, int width) 构造函数初始化。
//但是这里并没有说明 m_engine 该如何处理。在这种情况下，编译器就认为 m_engine 应该用 Engine 类的无参构造函数初始化。