//由于 C++ 中全局 const 变量的可见范围仅限于当前源文件，
// 所以可以将它放在头文件中，这样即使头文件被包含多次也不会出错(我理解是多个文件包含 .h 文件不会报错)，请看下面的例子。

#include <stdio.h>
#include "3.h"
int main(){
    func();
    printf("main: %d\n", n);
    return 0;
}