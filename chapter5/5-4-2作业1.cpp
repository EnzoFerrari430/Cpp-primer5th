#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /*
        5.15 a ѭ����ix����sz ����ix������forѭ���ڲ����壬
        5.15 b ix��Ҫ��ʼ��
        5.15 c 2���� ++ ������һ��ʼ��������ѭ���ͳ�����ѭ��
    */

    int i,sum,i2,sum2,num,num2;
    sum = sum2 = 0;
    vector<int> vi;
    for(i = 1; i <= 10 ;++i)
    {
        sum += i;
    }

    i2 = 1;
    while(i2 <= 10)
    {
        sum2 += i2;
        ++i2;
    }
    /*
    while(cin>>num)
    {

    }
    */
    cout<<"cin num2"<<endl;
    for( int d ;cin>>d; )
    {
        vi.push_back(d);
    }

    cout<<sum<<endl;
    cout<<sum2<<endl;




    return 0;
}
