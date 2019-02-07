/*
    1.当基类的指针或引用绑定到派生类的对象上时
    2.用派生类对象给基类进行拷贝或移动初始化，或者调用赋值运算符派生类向基类赋值

    double print_total( ostream &os,const Quote &item,size_t n )
    类似上面的函数，这个原理还是将基类的引用绑定到派生类对象上
*/
