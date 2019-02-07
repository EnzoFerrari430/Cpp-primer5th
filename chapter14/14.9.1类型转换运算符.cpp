#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


/*
    �����ܶ�����������͵�ת����ͨ����������ת�����������������һ�㡣
    ת�����캯��������ת���������ͬ������������ת��
    ������ת����ʱҲ�������û����������ת��
*/

/*
    ����ת�����������һ�������͵�ֵת�����������ͣ�һ����ʽ����
    operator type() const;    type�������������͵��ǲ�����void

    ֻҪ����������Ϊ�����ķ������͡��������ǲ�����ת�������飬���ߺ������ͣ���������ת����ָ�������������
*/

//��ʾ0-255֮�����
class SmallInt
{
public:
    SmallInt(int i = 0):val(i){
        if(i < 0 || i > 255)
        {
            throw std::out_of_range("Bad SmallInt Value");
        }
    }
    //operator int()const{return val;}
    explicit operator int() const{return val;}  //explicit��ʽ������ת�������  ���������������Զ�ִ����һ����ת��
private:
    std::size_t val;

};

int main()
{
    SmallInt si = 4;  //�Ƚ�4��ʽת����SmallInt��Ȼ�����SmallInt::operator=
    //cout<<si + 3<<endl;  //�Ƚ�si��ʽ��ת����int��Ȼ��ִ�������ļӷ�  ��������Ҫ����ʽ������ת�������ʾ������ת��
    cout<<static_cast<int>(si) + 3<<endl;

    SmallInt s2 = 3.14;  //����SmallInt(int)���캯��
    //cout<<s2 + 3.14<<endl;  //s2��ת��int��ת��double�õ�6.14
    cout<<static_cast<int>(s2) + 3.14<<endl;
    SmallInt s3 = 1000;


    //int i = 42;
    //cin<<i;  //�����bool������ת��������ʾ�ģ���ô����ڱ������������ǺϷ��ġ�  ��������ͨ������
    //istream��bool����ת���������cinת����bool�������boolֵ���Ż�������int  �������һ��intֵ��1��0��������42λ


    return 0;
}
