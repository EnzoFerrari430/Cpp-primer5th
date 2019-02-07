/*
    Query的唯一成员是  shared_ptr<Query_base> q
    拷贝：
        q1 = q2
    移动
        q1 = std::move(q2)
    赋值
        q1 =

    拷贝，移动，赋值都调用对应的派生类的对应的函数
    销毁
        调用Query_base派生来的对应的析构函数

*/
