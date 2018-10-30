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
