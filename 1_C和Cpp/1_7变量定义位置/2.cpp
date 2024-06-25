//取消限制带来的另外一个好处是，可以在 for 循环的控制语句中定义变量，请看下面的例子

#include <iostream>
using namespace std;
int sum(int n){
    int total = 0;
    //在for循环的条件语句内部定义变量i
    for(int i=1; i<=n ;i++){
        total += i;
    }
    return total;
}
int main(){
    cout<<"Input a interge: ";
    int n;
    cin>>n;
    cout<<"Total: "<<sum(n)<<endl;
    return 0;
}

//Input a interge: 5
//Total: 15
//
//在 for 内部定义循环控制变量 i，会让代码看起来更加紧凑，
//并使得 i 的作用域被限制在整个 for 循环语句内部（包括循环条件和循环体），
//减小了命名冲突的概率。