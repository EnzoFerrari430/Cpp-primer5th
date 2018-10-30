#include <iostream>
#include <set>
#include <string>
using namespace std;
/*
    �������2���࣬message���folder�࣬��ʾ�����ʼ�����Ϣ����ϢĿ¼��
    ÿ����Ϣ������Գ����ڶ��folder�У����Ǹ�����message������ֻ��һ��������
    ���һ��message�����ݱ��ı䣬������Ŀ¼�µĴ�messageҲ�ᱻ�ı�
    ���������ͼ��Ŀ�ݷ�ʽ

    message����һ����������folder��ָ���set
    folder������һ��������message��ָ���set
*/
//class Message;  //����2����
class Folder;



class Message
{
    friend class Folder;
public:
    Message();
    Message(const Message&);
    Message& operator=(const Message&);  //������  ������ֵ
    ~Message();  //ɾ������
    //�ڸ�����folder����Ӻ�ɾ��message
    void Save(Folder&);  //��ΪFolder�Ƕ�̬����ģ��������ã�����������
    void Remove(Folder&);  //�������ã�����������
private:
    string sContent;  //��Ϣ����
    set<Folder*> pSet_F;
    //����Message��ӵ�ָ�������Folder��
    void add_to_Folders(const Message&);
    //��message��Folder��ɾ��
    void remove_from_Folders();
};

Message::Message()
{
    sContent = "";  //��ʼ��Ϊ��
}

Message::Message(const Message& rhs)
{
    sContent = rhs.sContent;
    pSet_F.insert(rhs.pSet_F.begin(),rhs.pSet_F.end());  //�ø���������������ͬ��folder�С�
    add_to_Folders(rhs);  //�����������message��ӵ�folder��
}

void Message::Save(Folder& rhs)  //��Ͳ�����const���ã�rhs�ᱻ�޸�
{
    //��¼�����folder
    pSet_F.insert(&rhs);
    //Folder��������Message
    rhs.addMsg(this);  //��ΪFolderû�ж�������Ա������������Ҳ���addMsg��Ա����
}

void Message::Remove(Folder& rhs)
{
    pSet_F.erase(&rhs);  //��������ɾ���ĵ������汾������һ��key_type,���ﴫ��Folder*
    //Folder��ɾ�����message
    rhs.remMsg(this);
}

Message& Message::operator=(const Message& rhs)
{
    //���������ֵ���ڵ�ǰĿ¼��
    remove_from_Folders();  //ɾ��folder�б���Ĵ���message
    sContent = rhs.sContent;  //����message����

//���Ժ�Ϊһ�仰
//    pSet_F.clear();  //���FolderĿ¼
//    pSet_F.insert(rhs.pSet_F.begin(),rhs.pSet_F.end());  //��rhs��Ŀ¼���Ƶ�pSet_F��
    pSet_F = rhs.pSet_F;
    add_to_Folders(rhs);
    //��Folder��������message
    return *this;
}

Message::~Message()
{
    //���pSet_F
    //Folder��ɾ����Message
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
    //void remMsg(const Message&);  Ϊʲô������const
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
