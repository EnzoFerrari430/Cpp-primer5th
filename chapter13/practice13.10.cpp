2个类都没有定义自己的析构函数，所以编译器会为它们合成析构函数

StrBlob的非静态成员data会被销毁，这调用shared_ptr的析构函数，将其引用计数 -1 ，引用计数变为0会销毁共享的vector对象

StrBlobPtr在合成析构函数在隐含的析构阶段被销毁数据成员wptr和curr，销毁wptr会调用weak_ptr的析构函数，引用计数不变，而curr是内置类型，销毁它不会有特殊动作

