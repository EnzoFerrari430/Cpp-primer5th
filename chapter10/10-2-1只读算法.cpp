#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    //accmulate������ͷ�ļ�numeric�У�ǰ2������ָ����Ҫ���Ԫ�صķ�Χ����3�������Ǻ͵ĳ�ʼֵ
    //��Ԫ�����ͼӵ��͵������ϵĲ��������ǿ��еģ���ƥ�������ת��,string����Ҫ��ʾ�Ĵ�������û����ʾ��ָ������const char*����
    vector<int> val{0,1,2,3,4,5,6,7,8,9};
    int sum = accumulate(val.begin(),val.end(),0);
    cout<<sum<<endl;

    //equal�㷨����һ�������е�ÿ��Ԫ����ڶ��������еĶ�ӦԪ�ؽ��бȽ�.����ȷ���true ����false
    //ǰ�������ǵڶ������еĳ���Ҫ���ڵ��ڵ�һ������



    return 0;
}
