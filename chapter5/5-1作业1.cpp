#include <iostream>
using namespace std;
int main()
{
    //5.1�����  ֻ��һ���ֺŵ����  ���﷨����Ҫһ����� �����߼��ϲ���Ҫ����Ϳ����ÿ����
    //5.2���������������������������У���Ϊ��.  ���﷨����Ҫһ����� �������߼�����Ҫ��������ǵ�ʱ��Ϳ����õ���


    int sum = 0,val = 1;
    while(val<=10)
        sum += val,++val;
    cout<<sum<<endl;

    return 0;
}
