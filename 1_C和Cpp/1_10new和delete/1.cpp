//在C语言中，动态分配内存用 malloc() 函数，释放内存用 free() 函数。如下所示：
#include <stdio.h>
#include <cstdlib>

int main(){
    int *p1 = (int*) malloc( sizeof(int) * 10 );  //分配10个int型的内存空间
    free(p1);  //释放内存

//用 new 和 delete 分配内存更加简单：
    int *p2 = new int;  //分配1个int型的内存空间
    delete p2;  //释放内存

//如果希望分配一组连续的数据，可以使用 new[]：
    int *p3 = new int[10];  //分配10个int型的内存空间
    delete[] p3;
    return 0;
}

