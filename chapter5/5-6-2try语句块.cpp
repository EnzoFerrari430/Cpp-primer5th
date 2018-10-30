#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    /*
        try�����ͨ���﷨�ǣ�

        try{
            program-statements
        }
        catch(exception-declaration)
        {
            handler-statements
        }
        catch(exception-declaration)
        {
            handler-statements
        }
        //...
        catch�Ӿ��3���֣��ؼ���catch��������һ��(����δ������)���������(�����쳣���� exception declaration)�Լ�һ����

        try�����������ı����ڿ��ⲿ�޷����ʣ��ر�����catch�Ӿ���Ҳ�޷�����
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
        cout<<err.what()<<"\nTry Again? Enter y or n"<<endl;
    }
    return 0;
}
