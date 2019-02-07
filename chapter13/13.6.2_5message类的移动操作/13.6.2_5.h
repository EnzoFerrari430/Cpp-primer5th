#ifndef EX13_6_2_5_H_INCLUDED
#define EX13_6_2_5_H_INCLUDED

#include <string>
#include <set>
using namespace std;

class Folder;



class Message
{
    friend class Folder;
    friend void swap(Message& lhs,Message& rhs);
public:
    explicit Message(const string &s = "");
    Message(const Message&);
    Message(Message &&)noexcept;   //�ƶ����캯��,���׳��쳣
    Message& operator=(const Message&);  //������  ������ֵ
    Message& operator=(Message &&)noexcept;   //�ƶ���ֵ��������׳��쳣
    ~Message();  //ɾ������
    //�ڸ�����folder����Ӻ�ɾ��message
    void Save(Folder&);  //��ΪFolder�Ƕ�̬����ģ��������ã�����������
    void Remove(Folder&);  //�������ã�����������

    //ͨ�������ƶ�����,����������Ŀ�����ֵ�����ʹ��string��set���ƶ����������⿽��sContent��pSet_F��Ա�Ķ��⿪��
    void move_Folders( Message *m );

public:
    string sContent;  //��Ϣ����
    set<Folder*> pSet_F;  //���������¼��message��������Щfolder��
    //����Message��ӵ�ָ�������Folder��
    void add_to_Folders(const Message&);
    //��message��Folder��ɾ��
    void remove_from_Folders();
};


class Folder
{
    friend class Message;
public:
    Folder(string s = string() );
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg( Message*);
    //void remMsg(const Message&);  Ϊʲô������const
    void remMsg( Message*);
public:
    string sName;
    set<Message*> pSet_M;
};



#endif // 13_6_2_5_H_INCLUDED
