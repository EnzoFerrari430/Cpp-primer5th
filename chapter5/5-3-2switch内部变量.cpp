#include <iostream>
using namespace std;
//��������û�б��������ڱ���ʱ�ͼ�����,����������ͨ��
//�ڴ���switch case ����У�C++11��׼�ı�����������ִ��case��תǰΪ��������ռ䣬���ִ��Ҳû������
int main()
{
    int idx = 2;
    switch(idx)
    {
        int k;
    case 1:
        int j;
        break;
    case 2:
        k = 1;
        j = 2;
        cout<<"K: "<<k<<endl;
        cout<<"J: "<<j<<endl;
        break;
    default:
        break;
    }
    return 0;
}
