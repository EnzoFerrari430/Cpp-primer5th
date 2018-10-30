bool fcn(const Sales_data *trans,Sales_data accum)
{
    Sales_data item1(*trans),item2(accum);
    return item1.isbn() != item2.isbn();
}

这里发生三次析构函数
局部对象item1 item2 会在函数结束时被销毁，Sales_data析构函数被调用
函数结束时，参数accum的生命期结束，被销毁，Sales_data的析构函数被调用
虽然函数结束时，trans的生命期也结束了，但是它是Sales_data的指针，并不是它指向的Sales_data对象的生命期结束(只有delete指针时，指向的动态对象的生命期才结束)，所以不会引起析构函数的调用
