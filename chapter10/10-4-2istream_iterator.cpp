#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
/*
    һ��istream_iteratorʹ��>>����ȡ����
    istream_iteratorҪ��ȡ�����ͱ��붨�������������
    ����istream_iteratorʱ�����ǿ��Խ����󶨵�һ������
    Ĭ�ϳ�ʼ��ʱ���������Ǳ�ʾβ��ֵ�ĵ�����


    istream_iterator<int> int_it(cin)  //��cin��ȡint
    istream_iterator<int> int_eof;  //β�������
    ifstream in("afile");
    istream_iterator<string> str_it(in);  //��"afile"��ȡ�ַ���

istream_iterator��������ֵ
    ���ǽ�һ��istream_iterator�󶨵�һ����ʱ����׼�Ⲣ����֤����������������ȡ���ݡ�֪������ʹ�õ�����ʱ��������ȡ��


*/
int main()
{
    /*
    1.
    //��ȡ���ݴ���vector
    vector<int> vec;
    istream_iterator<int> in_iter(cin);  //��cin��ȡint
    istream_iterator<int> eof;  //istreamβ�������
    while(in_iter != eof )  //�������ݿɹ���ȡʱ
    {
        //�Ƚ�����������Ȼ�����vec���������������
        vec.push_back(*in_iter++);
    }
    */

    //2.��д
    istream_iterator<int> in_iter(cin),eof;

    /*
    //��ע�ͻ��ȴ���vec��,�͵ò�������ֵ
    vector<int> vec(in_iter,eof);
    for(auto c: vec)
        cout<<c<<' ';
    cout<<endl;
    */
    int num;
    cin>>num;
    cout<<num<<endl;

    cout<<accumulate(in_iter,eof,0)<<endl;

    return 0;
}
