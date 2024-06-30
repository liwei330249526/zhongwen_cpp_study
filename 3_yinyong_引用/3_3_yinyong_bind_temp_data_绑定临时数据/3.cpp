#include <iostream>
using namespace std;

typedef struct{
    int a;
    int b;
} S;

//这里用到了一点新知识，叫做运算符重载，我们会在《运算符重载》一章中详细讲解
S operator+(const S &A, const S &B){
    S C;
    C.a = A.a + B.a;
    C.b = A.b + B.b;
    return C;
}

S func(){
    S a;
    a.a = 100;
    a.b = 200;
    return a;
}

int main(){
    S s1 = {23, 45};
    S s2 = {90, 75};
    S *p1 = &(s1 + s2);  // Taking the address of a temporary object of type 'S'
    S *p2 = &(func());  // Taking the address of a temporary object of type 'S'
    cout<<p1<<", "<<p2<<endl;

    return 0;
}

//error: taking address of rvalue [-fpermissive]



//寄存器离 CPU 近，并且速度比内存快，将临时数据放到寄存器是为了加快程序运行。
// 但是寄存器的数量是非常有限的，容纳不下较大的数据，所以只能将较小的临时数据放在寄存器中。
// int、double、bool、char 等基本类型的数据往往不超过 8 个字节，用一两个寄存器就能存储，
// 所以这些类型的临时数据通常会放到寄存器中；而对象、结构体变量是自定义类型的数据，
// 大小不可预测，所以这些类型的临时数据通常会放到内存中
// 错误， 不可

