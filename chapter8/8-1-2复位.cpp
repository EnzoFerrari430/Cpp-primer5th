#include <iostream>
using namespace std;
int main()
{
    auto old_state = cin.rdstate();
    cout<<(cin.rdstate())<<endl;
    int n;
    cin>>n;
    cout<<(cin.rdstate())<<endl;

    cin.clear();
    cout<<(cin.rdstate())<<endl;
    cin.sync();  //�����
    cin>>n;
    cout<<(cin.rdstate())<<endl;
    cin.setstate(old_state);  //���ݸ����ı�־λ�����е�����״̬λ��λ
    cout<<(cin.rdstate())<<endl;
    //setstate()��������ǿ�Ƹ�������ԭ״̬�����ǽ������ڲ����������״̬���ӵ�ԭʼ״̬�ϡ�
    //clear() ��������״̬���ó������ڲ����������״̬��ǿ�Ƹ��ǵ�����ԭ״̬��
    return 0;
}
