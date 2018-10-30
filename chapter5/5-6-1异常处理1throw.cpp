#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    /*
        �쳣�������Ϊ�������쳣������쳣������������ֵ�Э���ṩ֧�֡�
        C++���쳣���������
            throw ���ʽ:�쳣��ⲿ��ʹ��throw���ʽ����ʾ���������޷���������⡣��Ϊthrow����(raise)���쳣

            try���飬�쳣������ʹ��try���鴦���쳣��try�����Թؼ���try��ʼ�����Զ��catch�Ӿ������try�����д����׳����쳣
            ͨ���ᱻĳ��catch�Ӿ䴦����Ϊcatch�Ӿ䡱�����쳣��ͨ������Ҳ�������쳣�������

            һ���쳣�࣬������throw���ʽ����ص�catch�Ӿ�֮��ת���쳣�ľ�����Ϣ
    */

    int num1,num2;
    num1 = 10;
    num2 = 5;
    try
    {
        if(num1 != num2)
            throw runtime_error("num1,num2 are not same");
    }
    catch(runtime_error err)
    {
        cout<<err.what()<<endl;
    }
    return 0;
}
