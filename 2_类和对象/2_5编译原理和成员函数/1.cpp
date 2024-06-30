//C++和C语言的编译方式不同。C语言中的函数在编译时名字不变，或者只是简单的加一个下划线_（不同的编译器有不同的实现），
// 例如，func() 编译后为 func() 或 _func()。


//而C++中的函数在编译时会根据它所在的命名空间、它所属的类、以及它的参数列表（也叫参数签名）等信息进行重新命名，形成一个新的函数名。

//如果你希望看到经 Name Mangling 产生的新函数名，可以只声明而不定义函数，这样调用函数时就会产生链接错误，从报错信息中就可以看到新函数名。

#include <iostream>
using namespace std;
void display();
void display(int);
namespace ns{
    void display();
}
class Demo{
public:
    void display();
};
int main(){
    display();
    display(1);
    ns::display();
    Demo obj;
    obj.display();
    return 0;
}

//该例中声明了四个同名函数，包括两个具有重载关系的全局函数，一个位于命名空间 ns 下的函数，
//以及一个属于类 Demo 的函数。它们都是只声明而未定义的函数。

///usr/bin/ld: CMakeFiles/2_5_1.dir/2_类和对象/2_5编译原理和成员函数/1.cpp.o: in function `main':
///home/liwei/books/zhongwenwang/cpp_study/2_类和对象/2_5编译原理和成员函数/1.cpp:21: undefined reference to `display()'
///usr/bin/ld: /home/liwei/books/zhongwenwang/cpp_study/2_类和对象/2_5编译原理和成员函数/1.cpp:22: undefined reference to `display(int)'
///usr/bin/ld: /home/liwei/books/zhongwenwang/cpp_study/2_类和对象/2_5编译原理和成员函数/1.cpp:23: undefined reference to `ns::display()'
///usr/bin/ld: /home/liwei/books/zhongwenwang/cpp_study/2_类和对象/2_5编译原理和成员函数/1.cpp:25: undefined reference to `Demo::display()'


//成员函数的调用
//C++规定，编译成员函数时要额外添加一个参数，把当前对象的指针传递进去，通过指针来访问成员变量