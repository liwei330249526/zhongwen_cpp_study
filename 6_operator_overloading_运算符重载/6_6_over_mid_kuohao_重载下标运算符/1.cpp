#include <iostream>
using namespace std;

class Array{
public:
    Array(int length = 0);
    ~Array();
public:
    int & operator[](int i);
    const int & operator[](int i) const;
public:
    int length() const { return m_length; }
    void display() const;
private:
    int m_length;  //数组长度
    int *m_p;  //指向数组内存的指针
};

Array::Array(int length): m_length(length){
  if(length == 0){
    m_p = NULL;
  }else{
    m_p = new int[length];
  }
}

Array::~Array(){
  delete[] m_p;
}

int& Array::operator[](int i){
  return m_p[i];
}

const int & Array::operator[](int i) const{
  return m_p[i];
}

void Array::display() const{
  for(int i = 0; i < m_length; i++){
    if(i == m_length - 1){
      cout<<m_p[i]<<endl;
    }else{
      cout<<m_p[i]<<", ";
    }
  }
}

int main(){
  int n;
  cin>>n;

  Array A(n);
  for(int i = 0, len = A.length(); i < len; i++){
    A[i] = i * 5;
  }
  A.display();

  const Array B(n);
  cout<<B[n-1]<<endl;  //访问最后一个元素

  return 0;
}
//5
//0, 5, 10, 15, 20
//0

//重载[ ]运算符以后，表达式arr[i]会被转换为：
//arr.operator[ ](i);


// read
//C++ 规定，下标运算符[ ]必须以成员函数的形式进行重载。该重载函数在类中的声明格式如下：
//返回值类型 & operator[ ] (参数);
//
//或者：
//const 返回值类型 & operator[ ] (参数) const;

//使用第一种声明方式，[ ]不仅可以访问元素，还可以修改元素。使用第二种声明方式，[ ]只能访问而不能修改元素。
// 在实际开发中，我们应该同时提供以上两种形式，这样做是为了适应 const 对象，因为通过 const 对象只能调用 const 成员函数，
// 如果不提供第二种形式，那么将无法访问 const 对象的任何元素。