#include <iostream>
#include <string>
#include <cstddef>  //�����±�size_t�����ͷ�ļ��ж���
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    //int a[11] = {};  //������ʼ��Ϊ0

    unsigned score[11] = {};  //��ʼ��Ϊ0
    unsigned grade;
    while(cin>>grade)
    {
        if(grade<=100)
        {
            score[grade/10]++;
        }
    }
    for(int c:score)
    {
        cout<<c<<" ";
    }
    return 0;
}
