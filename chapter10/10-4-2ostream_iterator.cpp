#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

/*
    �κξ����������������Ͷ����Զ���ostream_iterator��
    ������һ��ostream_iteratorʱ�����ǿ����ṩ(��ѡ��)�ڶ���������������C������ַ���
    ������ջ���β��λ�õ�ostream_iterator

ostream_iterator����
    ostream_iterator<T> out(os)     ������ΪT��ֵд�뵽�����os��
    ostream_iterator<T> out(os,d)   ............................��ÿ��ֵ���涼���һ��d

    out = val;      ��<<�������valд�뵽out���󶨵�ostream�С�val�����ͱ�����out��д�����ͼ���

    *out, ++out, out++  ��Щ������Ǵ��ڵģ����ǲ���out���κ����顣ÿ�������������out
*/

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    ostream_iterator<int> out_iter(cout," ");
    for(auto e : vec)
    {
        //*out_iter++ = e;  //��out_iter��ֵʱ�����Ժ��Խ����ú͵�������
        out_iter = e;
    }
    cout<<endl;

    //����ͨ��copy����ӡvec�е�Ԫ��.  vec�����������������������
    copy(vec.begin(),vec.end(),out_iter);
    cout<<endl;
    return 0;
}
