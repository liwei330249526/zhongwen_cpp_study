//析构函数没有参数，不能被重载，因此一个类只能有一个析构函数。如果用户没有定义，编译器会自动生成一个默认的析构函数。
#include <iostream>
using namespace std;
class VLA{
public:
    VLA(int len);  //构造函数
    ~VLA();  //析构函数
public:
    void input();  //从控制台输入数组元素
    void show();  //显示数组元素
private:
    int *at(int i);  //获取第i个元素的指针
private:
    const int m_len;  //数组长度
    int *m_arr; //数组指针
    int *m_p;  //指向数组第i个元素的指针
};
VLA::VLA(int len): m_len(len){  //使用初始化列表来给 m_len 赋值
    if(len > 0){ m_arr = new int[len];  /*分配内存*/ }
    else{ m_arr = NULL; }
}
VLA::~VLA(){
    delete[] m_arr;  //释放内存
}
//void VLA::input(){
//    int i;
//    m_p = at(i);
//    for(int i=0; m_p; i++){
//        cin>>*at(i);
//        m_p = at(i);
//    }
//}
// 数组长度是5， 获取5个后， at[5] = null, 退出for循环
void VLA::input(){
    for(int i=0; m_p=at(i); i++){
        cin>>*at(i);
    }
}
// 展示数组元素
void VLA::show(){
    for(int i=0; m_p=at(i); i++){
        if(i == m_len - 1){ cout<<*at(i)<<endl; }
        else{ cout<<*at(i)<<", "; }
    }
}
// 获取第 i 个元素指针， 0， 1 ，2 ，3 ，4
int * VLA::at(int i){
    if(!m_arr || i<0 || i>=m_len){ return NULL; }
    else{ return m_arr + i; }
}
int main(){
    //创建一个有n个元素的数组（对象）
    int n;
    cout<<"Input array length: ";
    cin>>n;
    VLA *parr = new VLA(n);
    //输入数组元素
    cout<<"Input "<<n<<" numbers: ";
    parr -> input();
    //输出数组元素
    cout<<"Elements: ";
    parr -> show();
    //删除数组（对象）
    delete parr;
    return 0;
}

//Input array length: 5
//Input 5 numbers: 1 2 3 4 5
//Elements: 1, 2, 3, 4, 5
//
//~VLA()就是 VLA 类的析构函数，它的唯一作用就是在删除对象后释放已经分配的内存
//
//函数名是标识符的一种，原则上标识符的命名中不允许出现~符号，在析构函数的名字中出现的~可以认为是一种特殊情况，目的是为了和构造函数的名字加以对比和区分。
//
//注意：at() 函数只在类的内部使用，所以将它声明为 private 属性；m_len 变量不允许修改，所以用 const 进行了限制，这样就只能使用初始化列表来进行赋值。
//
//C++ 中的 new 和 delete 分别用来分配和释放内存，它们与C语言中 malloc()、free() 最大的一个不同之处在于：
//用 new 分配内存时会调用构造函数，用 delete 释放内存时会调用析构函数。构造函数和析构函数对于类来说是不可或缺的，
//所以在C++中我们非常鼓励使用 new 和 delete。