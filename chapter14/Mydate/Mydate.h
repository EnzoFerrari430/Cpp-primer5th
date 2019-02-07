#ifndef MYDATE_H_INCLUDED
#define MYDATE_H_INCLUDED

#include <string>
#include <iostream>
class Mydate
{
    friend int operator-(Mydate &,Mydate &);  //practice14.15  计算2个日期之差
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

    //14.24拷贝赋值运算符  移动赋值运算符
    Mydate &operator=(const Mydate &);
    Mydate &operator=(Mydate &&)noexcept;

    //practice14.48  可以含有bool类型的转换来判断日期的合法性，而且要加explicit  因为只需要在条件里面判断就好了
    explicit operator bool()const{
        //判断年份，月份，日期是否符合,,比较难以实现，暂时就返回true好了
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
