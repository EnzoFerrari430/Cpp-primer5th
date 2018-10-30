#include <iostream>
#include <forward_list>
using namespace std;
/*
    因为forward_list是单向链表,当删除一个元素时，我们不好找到这个被删除元素的上一个元素，以便让上一个元素指向被删元素的下一个元素
    所以forward_list添加或删除元素的操作是通过改变给定元素之后的元素来完成的。
    forward_list未定义insert emplace erase 而定义了名为insert_after emplace_after erase_after.
    为了支持在首元素之前添加或删除forward_list也定义了before_begin

在forward_list中插入或删除元素的操作
    lst.before_begin()      返回指向链表首元素之前不存在的元素的迭代器。此迭代器不能解引用。cbefore_begin()返回const_iterator
    lst.cbefore_begin()

    lst.insert_after(p,t)   在迭代器p之后的位置插入元素。t是一个对象，n是数量，b和e是表示范围的一对迭代器（b，e不能指向lst内部）
    lst.insert_after(p,n,t) il是一个花括号列表。返回一个指向最后一个插入元素的迭代器。如果范围为空，则返回p。
    lst.insert_after(p,b,e) 若p为尾后迭代器，则函数行为未定义
    lst.insert_after(p,il)

    emplace_after(p,args)   使用args在p指定的位置之后创建一个元素。返回一个指向这个新元素的迭代器。若p是尾后迭代器，则函数行为未定义

    lst.erase_after(p)      删除p指向之后的元素，或删除从b之后直到（不包含e）之前的元素。返回一个指向被删元素之后的迭代器，若不存在
    lst.erase_after(b,e)    这样的元素，则返回尾后迭代器。如果p指向lst的尾元素或者是一个尾后迭代器，则函数行为未定义

    在forward_list中添加或删除元素时，我们必须关注2个迭代器，一个指向我们要处理的元素，另一个指向其前驱。
*/
int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();  //表示flst的首前元素
    auto curr = flst.begin();         //表示flst的第一个元素
    while(curr != flst.end())
    {
        if( *curr % 2)
            curr = flst.erase_after(prev);  //删除prev指向之后的元素，返回一个指向被删元素之后的迭代器
        else
        {
            prev = curr;
            ++curr;
        }
    }
    for(auto c:flst)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
