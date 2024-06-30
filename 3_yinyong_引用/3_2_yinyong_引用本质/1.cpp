#include <iostream>
using namespace std;

int main(){
    int a = 99;
    int &r = a;
    cout<<a<<", "<<r<<endl;
    cout<<&a<<", "<<&r<<endl;

    return 0;
}

//99, 99
//0x7ffe40c2d60c, 0x7ffe40c2d60c



//2_2_yinyong_引用本质

//我们知道，变量是要占用内存的，虽然我们称 r 为变量，但是通过&r获取到的却不是 r 的地址，
//而是 a 的地址，这会让我们觉得 r 这个变量不占用独立的内存，它和 a 指代的是同一份内存。