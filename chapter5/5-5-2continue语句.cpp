#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        continue���ֻ�ܳ�����for��while��do whileѭ�����ڲ�������Ƕ���ڴ���ѭ�������������ڲ�
        ��break���ƣ�������Ƕ��ѭ���е�continue���Ҳ�����������������ѭ����
        ���break��䲻ͬ���ǣ�ֻ�е�switch���Ƕ���ڵ�������ڲ�ʱ��������switch��ʹ��continue

        continue����жϵ��ǵ�ǰ�ĵ�����������Ȼ����ִ��ѭ��������while �� do while�����˵�������ж�������ֵ��
        ���ڴ�ͳ��forѭ����˵������ִ��for���ͷ��expression
        ���ڷ�Χfor��˵�������������е���һ��Ԫ�س�ʼ��ѭ�����Ʊ���(declaration)
        for(declaration:expression)
            statement
    */
    string buf;
    vector<string> sval;
    while(cin>>buf && !buf.empty() )
    {
        if(buf[0] != '_')  //string�������»��߿�ͷ������ȥ
            continue;
        else
            sval.push_back(buf);
    }
    for(auto c: sval)
        cout<<c<<' ';
    return 0;
}
