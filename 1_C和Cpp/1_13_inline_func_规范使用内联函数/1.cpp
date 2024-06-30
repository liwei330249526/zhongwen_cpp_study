//更为严格地说，内联函数不应该有声明，应该将函数定义放在本应该出现函数声明的地方，这是一种良好的编程风格。
//
//在多文件编程中，我们通常将函数的定义放在源文件中，将函数的声明放在头文件中，希望调用函数时，
//引入对应的头文件即可，我们鼓励这种将函数定义和函数声明分开的做法。
//但这种做法不适用于内联函数，将内联函数的声明和定义分散到不同的文件中会出错，请看下面的例子。

#include <iostream>
using namespace std;
//内联函数声明
void func();
int main(){
    func();
    return 0;
}

///usr/bin/ld: CMakeFiles/1_13_1.dir/1_C和Cpp/1_13_inline_func_规范使用内联函数/1.cpp.o: in function `main':
///home/liwei/books/zhongwenwang/cpp_study/1_C和Cpp/1_13_inline_func_规范使用内联函数/1.cpp:12: undefined reference to `func()'

//上面的代码能够正常编译，但在链接时会出错。func() 是内联函数，编译期间会用它来替换函数调用处，
//编译完成后函数就不存在了，链接器在将多个目标文件（.o或.obj文件）合并成一个可执行文件时找不到 func() 函数的定义，所以会产生链接错误。