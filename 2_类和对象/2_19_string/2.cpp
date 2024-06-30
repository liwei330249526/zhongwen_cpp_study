#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;  //输入字符串
    cout<<s<<endl;  //输出字符串
    return 0;
}

//123   456
//123

//虽然我们输入了两个由空格隔开的字符串 ，但是只输出了一个，这是因为输入运算符>>默认会忽略空格，
//遇到空格就认为输入结束，所以最后输入的456没有被存储到变量 s。



//string 类重载了输入输出运算符，可以像对待普通变量那样对待 string 变量，也就是用>>进行输入，用<<进行输出

