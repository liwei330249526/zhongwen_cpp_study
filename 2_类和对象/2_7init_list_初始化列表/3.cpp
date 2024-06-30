//初始化 const 成员变量
//构造函数初始化列表还有一个很重要的作用，那就是初始化 const 成员变量。初始化 const 成员变量的唯一方法就是使用初始化列表。

class VLA{
private:
    const int m_len;
    int *m_arr;
public:
    VLA(int len);
};
//必须使用初始化列表来初始化 m_len
VLA::VLA(int len): m_len(len){
    m_arr = new int[len];
}

//VLA 类包含了两个成员变量，m_len 和 m_arr 指针，需要注意的是 m_len 加了 const 修饰，
// 只能使用初始化列表的方式赋值，如果写作下面 4.cpp 的形式是错误的