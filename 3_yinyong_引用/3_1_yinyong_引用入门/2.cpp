#include <iostream>
using namespace std;

void swap1(int a, int b);
void swap2(int *p1, int *p2);
void swap3(int &r1, int &r2);


int main() {
    int num1, num2;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap1(num1, num2);
    cout << num1 << " " << num2 << endl;

    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap2(&num1, &num2);
    cout << num1 << " " << num2 << endl;

    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap3(num1, num2);
    cout << num1 << " " << num2 << endl;

    return 0;
}

//直接传递参数内容
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//传递指针
void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//按引用传参
void swap3(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

//Input two integers: 10 20
//10 20
//Input two integers: 10 20
//20 10
//Input two integers: 10 20
//20 10

//1) swap1() 直接传递参数的内容，不能达到交换两个数的值的目的。
//2) swap2() 传递的是指针，能够达到交换两个数的值的目的。
//3) swap3() 是按引用传递，能够达到交换两个数的值的目的。

//C++引用作为函数参数

//在定义或声明函数时，我们可以将函数的形参指定为引用的形式，这样在调用函数时就会将实参和形参绑定在一起，
// 让它们都指代同一份数据。如此一来，如果在函数体中修改了形参的数据，那么实参的数据也会被修改，从而拥有“在函数内部影响函数外部数据”的效果。

//从以上代码的编写中可以发现，按引用传参在使用形式上比指针更加直观。在以后的 C++ 编程中，
// 我鼓励读者大量使用引用，它一般可以代替指针（当然指针在C++中也不可或缺），C++ 标准库也是这样做的。

