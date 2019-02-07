#include <iostream>
#include "ex13_34_36_37.h"

using namespace std;

Message::Message(const string &s)
{
    sContent = s;
}

Message::Message(const Message& rhs)
{
    sContent = rhs.sContent;
    //remove_from_Folders();  //删除原先message在各个Folders中的该message(拷贝构造不需要这句)
    pSet_F = rhs.pSet_F;  //赋值
    add_to_Folders(rhs);  //把当前拷贝的message添加到各个Folder中

}

void Message::Save(Folder& rhs)
{
    pSet_F.insert(&rhs);
    rhs.addMsg(this);
}

void Message::Remove(Folder& rhs)
{
    pSet_F.erase(&rhs);
    rhs.remMsg(this);
}

void Message::add_to_Folders(const Message& rhs)
{
    for(auto f:pSet_F)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for(auto f:pSet_F)
    {
        f->remMsg(this);
    }
}

Message& Message::operator=(const Message& rhs)
{
    sContent = rhs.sContent;
    remove_from_Folders();  //删除原先在各个Folders中的该message
    pSet_F = rhs.pSet_F;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

//这个函数会在移动赋值运算符的时候起作用
//从本Message移动pSet_F指针
//但是要注意的是，除了移动pSet_F成员外，还必须更新每个指向原Message的pSet_F。
//必须删除指向旧Message的指针，并添加新Message指针
void Message::move_Folders(Message *m)
{
    pSet_F = std::move(m->pSet_F);  //使用set的移动赋值运算符
    //删除pSet_F中folder指向m的message，将本message添加到folder中
    for( auto f : pSet_F )
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->pSet_F.clear();  //清除m中原先保存的所有folder指针,这样m是否被析构就都不会影响到当前对象保存的数据

}
//类似于shared_ptr，=号左边的指针在这条语句结束之后内部计数器会递减。如果计数器为0了就可以把左边的内存释放掉 是一个道理

//移动构造函数
Message(Message &&s)noexcept
{
    sContent = std::move(s.sContent);
    move_Folders(&s);
}

//移动赋值运算符
Message& Message::operator=(Message &&s)
{
    //先判断不是自赋值的情况
    if( this != &s )
    {
        remove_from_Folders();  //先将原message存在的folder中删除该message
        sContent = std::move(s.sContent);
        move_Folders(&s);
    }
    return *this;
}

//swap函数必须管理指向被交换Message的Folder指针.在调用swap(m1,m2)
void swap(Message& lhs, Message& rhs)
{
    using std::swap;  //在本例中严格来说不需要，但这是一个好习惯
    lhs.remove_from_Folders();  //删除在folder中的message
    rhs.remove_from_Folders();

    swap(lhs.pSet_F,rhs.pSet_F);  //交换message中的folder
    swap(lhs.sContent,rhs.sContent);

    lhs.add_to_Folders(lhs);  //在message中指定的folder中添加该消息
    rhs.add_to_Folders(rhs);


}


Folder::Folder(string s)
{
    sName = s;
}

Folder& Folder::operator=(const Folder& rhs)
{
    sName = rhs.sName;
    pSet_M = rhs.pSet_M;
    return *this;
}

Folder::~Folder()
{

}

void Folder::addMsg(Message* rhs)
{
    pSet_M.insert(rhs);
}

void Folder::remMsg(Message* rhs)
{
    pSet_M.erase(rhs);
}
