#include <iostream>
using std::string;

int main()
{
    /*
        ֱ�ӳ�ʼ���Ϳ�����ʼ��,ʹ��"="���ǿ�����ʼ������ʹ�õ���ֱ�ӳ�ʼ��
    */
    string s1;  //Ĭ�ϳ�ʼ��Ϊ��
    string s2 = s1;
    string s3 = "hiya";
    string s4(10,'c');
    //std::cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s4<<"\n";

    string s7(10,'c');
    string s8 = string(10,'c');  //Ч����s7һ�����ǿɶ��Խϲ�
    std::cout<<s7<<std::endl;
    std::cout<<s8<<std::endl;
    return 0;
}
