#ifndef MYDATE_H_INCLUDED
#define MYDATE_H_INCLUDED

#include <string>
#include <iostream>
class Mydate
{
    friend int operator-(Mydate &,Mydate &);  //practice14.15  ����2������֮��
    friend std::istream& operator>>(std::istream&,Mydate &);  //practice14.12
    friend bool operator==(const Mydate &,const Mydate &);  //practice14.17
    friend bool operator!=(const Mydate &,const Mydate &);

    friend bool operator<(const Mydate &,const Mydate &);  //practice14.19
    friend bool operator>(const Mydate &,const Mydate &);
    friend bool operator<=(const Mydate &,const Mydate &);
    friend bool operator>=(const Mydate &,const Mydate &);

public:

    Mydate():year("0000"),month("00"),day("00"){}
    Mydate(std::string y,std::string m,std::string d){year = y;month = m;day = d;}

    //14.24������ֵ�����  �ƶ���ֵ�����
    Mydate &operator=(const Mydate &);
    Mydate &operator=(Mydate &&)noexcept;

    //practice14.48  ���Ժ���bool���͵�ת�����ж����ڵĺϷ��ԣ�����Ҫ��explicit  ��Ϊֻ��Ҫ�����������жϾͺ���
    explicit operator bool()const{
        //�ж���ݣ��·ݣ������Ƿ����,,�Ƚ�����ʵ�֣���ʱ�ͷ���true����
        return true;
    }



    std::string year;
    std::string month;
    std::string day;

private:
    bool judgeYear();
    bool judgeMonth();
    bool judgeDay();

};





#endif // MYDATE_H_INCLUDED
