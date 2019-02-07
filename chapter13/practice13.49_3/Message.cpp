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
    //remove_from_Folders();  //ɾ��ԭ��message�ڸ���Folders�еĸ�message(�������첻��Ҫ���)
    pSet_F = rhs.pSet_F;  //��ֵ
    add_to_Folders(rhs);  //�ѵ�ǰ������message��ӵ�����Folder��

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
    remove_from_Folders();  //ɾ��ԭ���ڸ���Folders�еĸ�message
    pSet_F = rhs.pSet_F;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

//������������ƶ���ֵ�������ʱ��������
//�ӱ�Message�ƶ�pSet_Fָ��
//����Ҫע����ǣ������ƶ�pSet_F��Ա�⣬���������ÿ��ָ��ԭMessage��pSet_F��
//����ɾ��ָ���Message��ָ�룬�������Messageָ��
void Message::move_Folders(Message *m)
{
    pSet_F = std::move(m->pSet_F);  //ʹ��set���ƶ���ֵ�����
    //ɾ��pSet_F��folderָ��m��message������message��ӵ�folder��
    for( auto f : pSet_F )
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->pSet_F.clear();  //���m��ԭ�ȱ��������folderָ��,����m�Ƿ������Ͷ�����Ӱ�쵽��ǰ���󱣴������

}
//������shared_ptr��=����ߵ�ָ��������������֮���ڲ���������ݼ������������Ϊ0�˾Ϳ��԰���ߵ��ڴ��ͷŵ� ��һ������

//�ƶ����캯��
Message(Message &&s)noexcept
{
    sContent = std::move(s.sContent);
    move_Folders(&s);
}

//�ƶ���ֵ�����
Message& Message::operator=(Message &&s)
{
    //���жϲ����Ը�ֵ�����
    if( this != &s )
    {
        remove_from_Folders();  //�Ƚ�ԭmessage���ڵ�folder��ɾ����message
        sContent = std::move(s.sContent);
        move_Folders(&s);
    }
    return *this;
}

//swap�����������ָ�򱻽���Message��Folderָ��.�ڵ���swap(m1,m2)
void swap(Message& lhs, Message& rhs)
{
    using std::swap;  //�ڱ������ϸ���˵����Ҫ��������һ����ϰ��
    lhs.remove_from_Folders();  //ɾ����folder�е�message
    rhs.remove_from_Folders();

    swap(lhs.pSet_F,rhs.pSet_F);  //����message�е�folder
    swap(lhs.sContent,rhs.sContent);

    lhs.add_to_Folders(lhs);  //��message��ָ����folder����Ӹ���Ϣ
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
