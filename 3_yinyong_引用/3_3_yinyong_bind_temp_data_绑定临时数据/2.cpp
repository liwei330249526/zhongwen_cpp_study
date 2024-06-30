#include <iostream>
using namespace std;

int func(){
    int n = 100;
    return n;
}


int main(){
    int *p = &(func());

    return 0;
}


//error: lvalue required as unary ‘&’ operand
//    int *p = &(func());


//func() 的返回值 100 也会被放到寄存器中，也没法用&获取它的地址。