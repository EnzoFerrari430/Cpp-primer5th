#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
public:
    //Ĭ�Ϲ��캯��
    Sales_data(string s = ""):bookNo(s){}  //1
    //�������캯����֮ǰһ��
    Sales_data(string s,unsigned cnt,double rev):bookNo(s),units_sold(cnt),revenue(rev*cnt){}  //2
    Sales_data(istream &is){read(is,*this);}  //3

    //7.38
    Sales_data(istream &is = cin){read(is,*this);}  //4

    //7.39  1��4������Ĭ��ʵ�β��Ϸ��� ��֪�����õ����ĸ����캯��

};

Sales_data first_item(cin);  //3

int main()
{
    Sales_data next;  //1
    Sales_data last("9-999-99999-9");  //1

    return 0;
}
