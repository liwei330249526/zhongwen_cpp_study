#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "first second second second third";
    string s2 = "second";
    int index1 = s1.rfind(s2);
    if(index1 < s1.length())
        cout<<"Found at index : "<< index1 <<endl;
    else
        cout<<"Not found"<<endl;


    int index2 = s1.rfind(s2, 6);
    if(index2 < s1.length())
        cout<<"Found at index : "<< index2 <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}

//
//Found at index : 20
//Found at index : 6



//rfind() 函数， 反向查找, 或最后一个匹配的位置
//rfind() 和 find() 很类似，同样是在字符串中查找子字符串，不同的是 find() 函数从第二个参数开始往后查找，
//而 rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回 string::npos。