//C++ 允许数组的每个元素都是对象，这样的数组称为对象数组。

#include<iostream>
using namespace std;
class CSample{
public:
    CSample(){  //构造函数 1
        cout<<"Constructor 1 Called"<<endl;
    }
    CSample(int n){  //构造函数 2
        cout<<"Constructor 2 Called"<<endl;
    }
};
int main(){
    cout<<"stepl"<<endl;
    CSample arrayl[2];  //  array1 数组中的两个元素没有指明如何初始化，那么默认调用无参构造函数初始化，因此输出两行 Constructor 1 Called。

    cout<<"step2"<<endl;
//    array2 数组进行了初始化，初始化列表 {4, 5} 可以看作用来初始化两个数组元素的参数，
//    所以 array2[0] 以 4 为参数，调用构造函数 2 进行初始化；array2[1] 以 5 为参数，
//    调用构造函数 2 进行初始化。这导致输出两行 Constructor 2 Called。
    CSample array2[2] = {4, 5};
    cout<<"step3"<<endl;

    //array3 只指出了 array3[0] 的初始化方式，没有指出 array3[1] 的初始化方式，因此它们分别用构造函数 2 和构造函数 1 进行初始化。
    CSample array3[2] = {3};


    cout<<"step4"<<endl;
    //态分配了一个 CSample 数组， array3 只指出了 array3[0] 的初始化方式，没有指出 array3[1] 的初始化方式，因此它们分别用构造函数 2 和构造函数 1 进行初始化。
    CSample* array4 = new CSample[2];
    delete [] array4;
    return 0;
}

//          stepl
//        Constructor 1 Called
//        Constructor 1 Called
//        step2
//          Constructor 2 Called
//        Constructor 2 Called
//        step3
//          Constructor 2 Called
//        Constructor 1 Called
//        step4
//          Constructor 1 Called
//        Constructor 1 Called