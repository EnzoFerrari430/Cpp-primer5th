#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;

class Window_mgr
{
public:


    //������ÿ����Ļ�ı��
    using ScreenIndex = std::vector<Screen>::size_type;
    //���ݱ�Ž�ָ����Screen����Ϊ�հ�
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);

private:
    vector<Screen> screens;  //���Screen�໹û�ж���� �����Բ��ܳ�ʼ��
};



class Screen
{

    //friend class Window_mgr;
    //Ҳ����ֻΪclear�����ṩ����Ȩ��
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    Screen() = default;  //��ΪScreen����һ�����캯�������Ա������Ǳ����
    //cursor�����౻��ʼ��Ϊ0

    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c) {} //cursor��Ա��ʽ��ʹ�������ڳ�ʼֵ
    char get() const
    {
        return contents[cursor];   //��ʽ����
    }
    inline char get(pos ht,pos wd) const;  //��ʽ����
    Screen &move(pos r,pos c);  //����֮����Ϊ����
    void some_member() const;
    pos size() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    //mutable�ؼ���  �ɱ����ݳ�Ա����Զ������const����ʹ��const����ĳ�Ա
    mutable size_t access_ctr;  //��const������Ҳ�ܱ��޸�
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


//pos������֮ǰ����Ҫ��������ʷ�
Screen::pos Screen::size() const
{
    return height * width;
}

void Window_mgr::clear(ScreenIndex i)
{
    //s��һ��Screen�����ã�ָ����������յ��Ǹ���Ļ
    Screen &s = screens[i];

    s.contents = string(s.height * s.width, ' ');
}

/*
declare class does not name a type

����������������Ҫ���ĸ�����ԭ�����ܽ����£�

1.���õ��������ռ�δ����

2.���õ���ͷ�ļ�δ����

3.������ͷ�ļ��������Ѿ�ǰ�������ˣ���˵�������õ�����д��

4.ѭ������ͷ�ļ�
*/

//�������ͳ���������֮ǰ����ʹ��ScreenIndex��Ϊ�������ͣ���Ҫ��ȷָ���ĸ���ʹ������
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screens.push_back(s);
    return screens.size() - 1;
}




int main()
{
    Screen::pos ht = 24;

    return 0;
}
