//在类体中直接定义函数时，不需要在函数名前面加上类名，因为函数属于哪一个类是不言而喻的。

//但当成员函数定义在类外时，就必须在函数名前面加上类名予以限定。
// ::被称为域解析符（也称作用域运算符或作用域限定符），用来连接类名和函数名，指明当前函数属于哪个类。

//在类体中和类体外定义成员函数是有区别的：在类体中定义的成员函数会自动成为内联函数，在类体外定义的不会。
//当然，在类体内部定义的函数也可以加 inline 关键字，但这是多余的，因为类体内部定义的函数默认就是内联函数。