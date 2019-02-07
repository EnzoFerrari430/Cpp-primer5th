/*
    类可以定义其他赋值运算符以使用别的类型作为右侧运算对象。

    类似 vector<string> v;
    v = {"a","an","the"};

    我们可以把该运算符加到我们StrVec类中


    复合赋值运算符不非得是类的成员，不过我们还是倾向于把包括复合赋值在内的所有赋值运算都定义在类的内部
    为了与内置类型的复合赋值保持一致，类中的复合赋值运算符也要返回其左侧运算对象的引用

    详见Sales_data类
*/
