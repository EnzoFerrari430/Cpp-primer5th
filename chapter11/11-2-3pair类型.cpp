#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>  //pair����ͷ�ļ�
#include <algorithm>
using namespace std;
//����һ��pair����ĺ���
pair<string,int> process(vector<string> &v)
{
    //����v
    //v.back() v.front() ����v��ĩβԪ�غ���ʼԪ�ص�����
    if( !v.empty() )
    {
        return {v.back(),v.back().size()};  //�б��ʼ��
        //Ҳ������make_pair�����ɶ���
        //return make_pair(v.back(),v.back().size() );
    }
    else
    {
        return pair<string,int>();  //��ʽ���췵��ֵ
    }
}
int main()
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    cout<<vec.back()<<endl;

    return 0;
}
