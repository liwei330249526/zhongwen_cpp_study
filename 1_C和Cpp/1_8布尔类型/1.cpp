//在C语言中，关系运算和逻辑运算的结果有两种，真和假：0 表示假，非 0 表示真。例如：
#include <stdio.h>
int main(){
    int a, b, flag;
    scanf("%d %d", &a, &b);
    flag = a > b;  //flag保存关系运算结果
    printf("flag = %d\n", flag);

    return 0;
}
//
//10
//20
//flag = 0
//
//C语言并没有彻底从语法上支持“真”和“假”，只是用 0 和非 0 来代表。这点在 C++ 中得到了改善，
//C++ 新增了 bool 类型（布尔类型），它一般占用 1 个字节长度。bool 类型只有两个取值，true 和 false：true 表示“真”，false 表示“假”。