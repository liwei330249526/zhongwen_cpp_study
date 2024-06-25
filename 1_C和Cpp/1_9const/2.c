#include <stdio.h>
const int n = 10;
void func();
int main(){
    func();
    printf("main: %d\n", n);
    return 0;
}

//module: 10
//main: 10

//C语言中的 const 变量在多文件编程时的表现和普通变量一样，除了不能修改，没有其他区别。