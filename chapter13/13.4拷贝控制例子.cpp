#include <iostream>
#include <set>
#include <string>
using namespace std;
/*
    我们设计2个类，message类和folder类，表示电子邮件的消息和消息目录，
    每个消息对象可以出现在多个folder中，但是给定的message的内容只有一个副本，
    如果一条message的内容被改变，则其他目录下的此message也会被改变
    类似于软件图标的快捷方式

    message都有一个保存所在folder的指针的set
    folder都保存一个它包含message的指针的set
*/
//class Message;  //声明2个类
class Folder;



class Message
{
    friend class Folder;
public:
    Message();
    Message(const Message&);
    Message& operator=(const Message&);  //用引用  返回左值
    ~Message();  //删除对象
    //在给定的folder中添加和删除message
    void Save(Folder&);  //因为Folder是动态申请的，传入引用，不拷贝对象
    void Remove(Folder&);  //传入引用，不拷贝对象
private:
    string sContent;  //消息内容
    set<Folder*> pSet_F;
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //将message从Folder中删除
    void remove_from_Folders();
};

Message::Message()
{
    sContent = "";  //初始化为空
}

Message::Message(const Message& rhs)
{
    sContent = rhs.sContent;
    pSet_F.insert(rhs.pSet_F.begin(),rhs.pSet_F.end());  //让副本副本出现在相同的folder中。
    add_to_Folders(rhs);  //把这个拷贝的message添加到folder中
}

void Message::Save(Folder& rhs)  //这和不能用const引用，rhs会被修改
{
    //记录下这个folder
    pSet_F.insert(&rhs);
    //Folder里添加这个Message
    rhs.addMsg(this);  //因为Folder没有定义好所以编译器在这里找不到addMsg成员函数
}

void Message::Remove(Folder& rhs)
{
    pSet_F.erase(&rhs);  //关联容器删除的第三个版本，传入一个key_type,这里传入Folder*
    //Folder里删除这个message
    rhs.remMsg(this);
}

Message& Message::operator=(const Message& rhs)
{
    //这个拷贝赋值，在当前目录下
    remove_from_Folders();  //删除folder中保存的此条message
    sContent = rhs.sContent;  //拷贝message内容

//可以合为一句话
//    pSet_F.clear();  //清除Folder目录
//    pSet_F.insert(rhs.pSet_F.begin(),rhs.pSet_F.end());  //将rhs的目录复制到pSet_F中
    pSet_F = rhs.pSet_F;
    add_to_Folders(rhs);
    //在Folder中添加这个message
    return *this;
}

Message::~Message()
{
    //清空pSet_F
    //Folder中删除此Message
    remove_from_Folders();
}

void Message::add_to_Folders( const Message& rhs)
{
    for(auto f:rhs.pSet_F)
    {
        f->addMsg(this);
    }

}

void Message::remove_from_Folders()
{
    for(auto f : (*this).pSet_F)
    {
        f->remMsg(this);
    }
}


class Folder
{
    friend class Message;
public:
    Folder(string s = string() );
    void addMsg( Message*);
    //void remMsg(const Message&);  为什么不能用const
    void remMsg( Message*);
private:
    string sName;
    set<Message*> pSet_M;
};

Folder::Folder(string s )
{
    sName = s;
}

void Folder::addMsg( Message* rhs)
{
    pSet_M.insert(rhs);
}

//void Folder::remMsg(const Message& rhs)
//{
//    pSet_M.erase(&rhs);
//}

void Folder::remMsg( Message* rhs)
{
    pSet_M.erase(rhs);
}






int main()
{


    return 0;
}
