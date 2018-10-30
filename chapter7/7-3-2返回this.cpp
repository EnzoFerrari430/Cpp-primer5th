#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;  //��ΪScreen����һ�����캯�������Ա������Ǳ����
    //cursor�����౻��ʼ��Ϊ0

    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c){}  //cursor��Ա��ʽ��ʹ�������ڳ�ʼֵ
    char get() const {return contents[cursor];}  //��ʽ����
    inline char get(pos ht,pos wd) const;  //��ʽ����
    Screen &move(pos r,pos c);  //����֮����Ϊ����
    void some_member() const;

    Screen &set(char);
    Screen &set(pos,pos,char);


    //���ݶ����Ƿ���const������display����
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    //mutable�ؼ���  �ɱ����ݳ�Ա����Զ������const����ʹ��const����ĳ�Ա
    mutable size_t access_ctr;  //��const������Ҳ�ܱ��޸�
    //����������ʽScreen����
    void do_display(std::ostream &os) const
    {
        os<<contents;
    }
};

//�ƶ����
inline
Screen &Screen::move(pos r,pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;  //����ֵ����ʽ���ض���
}

//��ȡ����λ�õ��ַ�
char Screen::get(pos r,pos c) const  //���ڲ�������inline
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const  //�����const��ʾthis��һ��ָ������ָ��
{
    ++access_ctr;  //����һ��ֵ�����ڼ�¼��Ա���������õĴ���
}

inline Screen Screen::&set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::&set(pos r,pos col, char ch)
{
    contents[r*width + col] = ch;  //�趨����λ�õ���ֵ
    return *this;  //this������Ϊ��ֵ����
}
int main()
{

    return 0;
}
