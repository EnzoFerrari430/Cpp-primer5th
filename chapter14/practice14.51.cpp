/*
    这里调用的是 void calc( int )  因为double类型转int类型是标准转换。
    而转换为LongDouble则是转换为用户自定义类型，实际上是调用了转换构造函数，所以前者优先
*/
