//你也可以使用 true 或 false 显式地对 bool 变量赋值，例如：

#include <iostream>
using namespace std;
int main(){
    bool flag = true;
    if(flag){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    flag = false;
    if(flag){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}