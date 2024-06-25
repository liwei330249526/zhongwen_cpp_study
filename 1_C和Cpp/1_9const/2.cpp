#include <stdio.h>
const int n = 10;
void func();
int main(){
    func();
    printf("main: %d\n", n);
    return 0;
}

///usr/bin/ld: CMakeFiles/1_9_2.dir/1_9const/2_1.cpp.o: in function `func()':
///home/liwei/books/zhongwenwang/cpp_study/1_9const/2_1.cpp:4: undefined reference to `n'


//这是因为 C++ 对 const 的特性做了调整，C++ 规定，全局 const 变量的作用域仍然是当前文件，
//但是它在其他文件中是不可见的，这和添加了static关键字的效果类似。虽然代码段2中使用 extern 声明了变量 n，
//但是在链接时却找不到代码段1中的 n