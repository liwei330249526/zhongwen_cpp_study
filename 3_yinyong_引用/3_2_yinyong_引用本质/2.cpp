#include <iostream>
#include <iomanip>
using namespace std;

int num = 99;

class A{
public:
    A();
//private:
    int32_t n;
    int32_t &r;
};

A::A(): n(3), r(num){}

int main (){
    A *a = new A();
    cout<<sizeof(A)<<endl;  //输出A类型的大小    //16
    cout<<hex<<showbase<<*((int32_t*)a)<<endl;  //输出r本身的内容   //0x3
    cout<<hex<<showbase<<*((int32_t*)a + 2)<<endl;  //输出r本身的内容  //0xc2314010
    cout<<hex<<showbase<<*((int32_t*)a + 3)<<endl;  //输出r本身的内容  //0x555f
    cout<<&num<<endl;  //输出num变量的地址   //0x555fc2314010

    cout<< a->n <<endl;  //0x3
    cout<< a->r <<endl;  //0x63

    return 0;
}


//16
//0x3
//0xc2314010
//0x555f
//0x555fc2314010
//0x3
//0x63

//成员变量 r 是 private 属性的，不能直接通过对象来访问，但是借助强大的指针和类型转换，我们依然可以得到它的内容，只不过这种方法有点蹩脚

//只要知道第 20  21 行代码是用来输出 r 本身的内容的即可。

//从运行结果可以看出：
//成员变量 r 是占用内存的，如果不占用的话，sizeof(A)的结果应该为 8。
//r 存储的内容是 0x555fc2314010，也即变量 num 的地址。

//这说明 r 的实现和指针非常类似。如果将 r 定义为int *类型的指针，并在构造函数中让它指向 num，
//那么 r 占用的内存也是 4 个字节，存储的内容也是 num 的地址

//其实引用只是对指针进行了简单的封装，它的底层依然是通过指针实现的，引用占用的内存和指针占用的内存长度一样，
// 在 32 位环境下是 4 个字节，在 64 位环境下是 8 个字节，之所以不能获取引用的地址，是因为编译器进行了内部转换。


//使用&r取地址时，编译器会对代码进行隐式的转换，使得代码输出的是 r 的内容（a 的地址），
// 而不是 r 的地址，这就是为什么获取不到引用变量的地址的原因。也就是说，不是变量 r 不占用内存，而是编译器不让获取它的地址。

//引用虽然是基于指针实现的，但它比指针更加易用，从上面的两个例子也可以看出来，
// 通过指针获取数据时需要加*，书写麻烦，而引用不需要，它和普通变量的使用方式一样。

//C++ 的发明人 Bjarne Stroustrup 也说过，他在 C++ 中引入引用的直接目的是为了让代码的书写更加漂亮，
// 尤其是在运算符重载中，不借助引用有时候会使得运算符的使用很麻烦。