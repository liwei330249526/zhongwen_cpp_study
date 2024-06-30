#include<iostream>
using namespace std;

class CTest{
public:
    CTest(int n){cout<<"Constructor 1 Called"<<endl; }  //构造函数(1)
    CTest(int n, int m){cout<<"Constructor 2 Called"<<endl; }  //构造函数(2)
    CTest(){ cout<<"Constructor 3 Called"<<endl; }  //构造函数(3)
};
int main(){
    //三个元素分别用构造函数(1)、(2)、(3) 初始化
    cout << "step1 " << endl;
    CTest arrayl [3] = { 1, CTest(1,2) };


    //三个元素分别用构造函数(2)、(2)、(1)初始化
    cout << "step1 " << endl;
    CTest array2[3] = { CTest(2,3), CTest(1,2), 1};


    //两个元素指向的对象分别用构造函数(1)、(2)初始化
    cout << "step1 " << endl;
    CTest* pArray[3] = { new CTest(4), new CTest(1,2) };
    return 0;
}

//         step1
//        Constructor 1 Called
//        Constructor 2 Called
//        Constructor 3 Called
//        step1
//        Constructor 2 Called
//        Constructor 2 Called
//        Constructor 1 Called
//        step1
//        Constructor 1 Called
//        Constructor 2 Called

//上面程序中比较容易令初学者困惑的是 CTest* pArray[3] 。pArray 数组是一个指针数组，
//其元素不是 CTest 类的对象，而是 CTest 类的指针。第 23 行对 pArray[0] 和 pArray[1] 进行了初始化，
//把它们初始化为指向动态分配的 CTest 对象的指针，而这两个动态分配出来的 CTest 对象又分别是用构造函数（1）和构造函数（2）初始化的。
//pArray[2] 没有初始化，其值是随机的，不知道指向哪里。

//第 23 行生成了两个 CTest 对象，而不是三个，所以也只调用了两次 CTest 类的构造函数。