#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    9.3
        ����������begin��end����ָ��ͬһ�������е�Ԫ�أ��������������һ��Ԫ��֮���λ�ã�
        ���ң���begin�������е������������Ա�֤�ﵽend����end����begin֮ǰ��


    9.6
        ������<���� �����<��std :: list��δʵ�֣���Ϊstd :: list��������˫������ ����ڵ�ĵ�ַ��һ���������ġ�

*/
//9.4,9.5
int main()
{
    vector<int> ival{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int num;
    cin>>num;
    vector<int>::iterator vi;
    for(vi = ival.begin();vi != ival.end(); ++vi)
    {
        if(*vi == num)
        {
            cout<<"find pos:"<<vi - ival.begin()<<endl;
            return 0;
        }
    }
    cout<<"cant find pos"<<endl;

    return 0;
}





