#include <iostream>
#include <utility>
#include "13.6.2_5.h"


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

//移动构造函数
Message::Message(Message &&m) noexcept : sContent(std::move(m.sContent))
{
    move_Folders(&m);  //移动folders并更新folder指针
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

//为什么要有这个函数？因为移动赋值运算符的时候message的内容可能是不一样的
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


Message& Message::operator=(Message &&rhs) noexcept
{
    if( &rhs != this )  //先检查自赋值情况
    {
        remove_from_Folders();  //先将该message在存在的folder中删除
        move_Folders(&rhs);  //更新pSet_F指针
        sContent = std::move(rhs.sContent);
    }
    return *this;
}


Message::~Message()
{
    remove_from_Folders();
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

int main()
{
    Folder *pF[5];
    pF[0] = new Folder("C:\\");
    pF[1] = new Folder("D:\\");
    pF[2] = new Folder("E:\\");
    pF[3] = new Folder("F:\\");
    pF[4] = new Folder("G:\\");

    Message *pM[5];
    pM[0] = new Message("Msg1");
    pM[1] = new Message("Msg2");
    pM[2] = new Message("Msg3");
    pM[3] = new Message("Msg4");
    pM[4] = new Message("Msg5");

    for(int i = 0 ; i < 5 ; ++i)
    {
        pM[0]->Save(*pF[i]);
    }


    for(int i = 0 ;i < 5 ;++i)
    {
        cout<<pM[i]->sContent<<" exists following folders: ";
        for(auto f : pM[i]->pSet_F)
        {
//            for(auto c : *f.pSet_F)
//            {
//                cout<<c<<endl;
//            }
            cout<<f->sName<<" ";
        }
        cout<<endl;
    }

    cout << "Hello world!" << endl;
    return 0;
}
