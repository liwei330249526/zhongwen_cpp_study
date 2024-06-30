
#include <iostream>
using namespace std;
#define SQ(y) y*y

#define SQ2(y) (y)*(y)


inline int SQ3(int y){ return y*y; }

int testSQ_1() {
    int n, sq;
    n=9;
    sq = SQ(n);
    cout<<sq<<endl;
    return 0;
}
//81     输出是正确的

int testSQ_2() {
    int n, sq;
    n=9;
    sq = SQ2(n+1);
    cout<<sq<<endl;
    return 0;
}
//19     输出有问题
//我们期望的结果是 100，但这里却是 19，两者大相径庭。这是因为，宏展开仅仅是字符串的替换，
//不会进行任何计算或传值，上面的sq = SQ(n+1);在宏展开后会变为sq = n+1*n+1;


int testSQ2() {
    int n, sq;
    n = 9;
    sq = 200 / SQ2(n+1);
    cout<<sq<<endl;
    return 0;
}
//200

//之所以会出现这么奇怪的结果，是因为宏调用sq = 200 / SQ(n+1);会被展开为sq = 200 / (n+1) * (n+1);，
//当 n 被赋值 9 后，相当于sq = 200 / 10 * 10，结果显然是 200。

//要想得到正确的结果，还应该对宏加以限制，在两边增加( )，如下所示：
//#define SQ(y) ( (y)*(y) )


//如果我们将宏替换为内联函数，情况就没有那么复杂了，程序员就会游刃有余

int testSQ3() {
    cout << "-----------testSQ3--------- " << endl;
    int n, sq;
    n = 9;
    //SQ(n)
    sq = SQ3(n);
    cout<<sq<<endl;
    //SQ(n+1)
    sq = SQ3(n+1);
    cout<<sq<<endl;
    //200 / SQ(n+1)
    sq = 200 / SQ3(n+1);
    cout<<sq<<endl;
    return 0;
}

//-----------testSQ3---------
//81
//100
//2

//和宏一样，内联函数可以定义在头文件中（不用加 static 关键字），并且头文件被多次#include后也不会引发重复定义错误。
// 这一点和非内联函数不同，非内联函数是禁止定义在头文件中的，它所在的头文件被多次#include后会引发重复定义错误

int main(){
    testSQ_1();
    testSQ_2();
    testSQ2();
    testSQ3();
}

//内联函数在编译时会将函数调用处用函数体替换，编译完成后函数就不存在了，所以在链接时不会引发重复定义错误。
// 这一点和宏很像，宏在预处理时被展开，编译时就不存在了。从这个角度讲，内联函数更像是编译期间的宏。

//综合本节和上节的内容，可以看到内联函数主要有两个作用，一是消除函数调用时的开销，二是取代带参数的宏。