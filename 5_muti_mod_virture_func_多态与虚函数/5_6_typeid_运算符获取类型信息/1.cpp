#include <iostream>
#include <typeinfo>
using namespace std;

class Base{ };

struct STU{ };

int main(){
  //获取一个普通变量的类型信息
  int n = 100;
  const type_info &nInfo = typeid(n);
  cout<<nInfo.name()<<" | nInfo "<<nInfo.hash_code()<<endl;

  //获取一个字面量的类型信息
  const type_info &dInfo = typeid(25.65);
  cout<<dInfo.name()<<" | dInfo "<<dInfo.hash_code()<<endl;

  //获取一个对象的类型信息
  Base obj;
  const type_info &objInfo = typeid(obj);
  cout<<objInfo.name()<<" | objInfo "<<objInfo.hash_code()<<endl;

  //获取一个类的类型信息
  const type_info &baseInfo = typeid(Base);
  cout<<baseInfo.name()<<" | baseInfo "<<baseInfo.hash_code()<<endl;

  //获取一个结构体的类型信息
  const type_info &stuInfo = typeid(struct STU);
  cout<<stuInfo.name()<<" | stuInfo "<<stuInfo.hash_code()<<endl;

  //获取一个普通类型的类型信息
  const type_info &charInfo = typeid(char);
  cout<<charInfo.name()<<" | charInfo "<<charInfo.hash_code()<<endl;

  //获取一个表达式的类型信息
  const type_info &expInfo = typeid(20 * 45 / 4.5);
  cout<<expInfo.name()<<" | expInfo "<<expInfo.hash_code()<<endl;

  return 0;
}

//i | nInfo 6253375586064260614
//d | dInfo 14494284460613645429
//4Base | objInfo 1646098473708828226
//4Base | baseInfo 1646098473708828226
//3STU | stuInfo 12536571244334020757
//c | charInfo 10959529184379665549
//d | expInfo 14494284460613645429

//name() 用来返回类型的名称。
//hash_code() 用来返回当前类型对应的 hash 值。




// read
//typeid 运算符用来获取一个表达式的类型信息。类型信息对于编程语言非常重要，它描述了数据的各种属性：
//对于基本类型（int、float 等C++内置类型）的数据，类型信息所包含的内容比较简单，主要是指数据的类型。
//对于类类型的数据（也就是对象），类型信息是指对象所属的类、所包含的成员、所在的继承关系等。