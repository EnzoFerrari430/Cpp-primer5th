#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        string��vector�ĵ������ṩ�˸���Ķ��������
        1.iter+n ������ָʾ��λ����ԭ�����ǰ����n��Ԫ�أ����������ָ�������ڵ�һ��Ԫ�أ���βԪ�ص���һԪ��
        2.iter-n ������ָʾ��λ����ԭ����Ⱥ�����n��Ԫ�أ����������ָ�������ڵ�һ��Ԫ�أ���βԪ�ص���һԪ��
        3.iter += n �������ӷ��ĸ�����䣬��iter + n�Ľ������iter
        4.iter -= n �������ӷ��ĸ�����䣬��iter - n�Ľ������iter
        5.iter1 - iter2 ����������֮��ľ��룬������������ָ�����ͬһ�������е�Ԫ�ػ���βԪ�ص���һλ��
        6.> >= < <= ����������λ�õıȽϣ�������������ָ�����ͬһ�������е�Ԫ�ػ���βԪ�ص���һλ��
    */
    vector<int> s1;
    int num;
    while(cin>>num)
    {
        s1.push_back(num);
    }
    auto beg = s1.begin();
    auto edd = s1.end();
    auto mid = s1.begin() + (edd - beg)/2;
    //auto mid2 = (edd + beg)/2;
    //�����ԣ�������Ϊ�����һ��˵���Ѿ�˵�ˣ���ӵĽ������ָ�������ڵ�һ��Ԫ�ػ�βԪ��,����ӿ϶���������һ����
    cout<<*mid<<endl;
    //cout<<*mid2<<endl;

    return 0;
}
