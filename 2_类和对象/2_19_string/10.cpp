#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "first second second third";
    string s2 = "asecond";
    int index = s1.find_first_of(s2);
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}

//Found at index : 3

//本例中 s1 和 s2 共同具有的字符是‘s’，该字符在 s1 中首次出现的下标是3，故查找结果返回3。

//3) find_first_of() 函数
//find_first_of() 函数用于查找子字符串和字符串共同具有的字符在字符串中首次出现的位置。请看下面的代码：
