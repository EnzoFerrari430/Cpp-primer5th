#include <iostream>
#include "HasPtr.h"
using namespace std;

/*
    ���п�����ֵʱ����ͨ���������촴����hp2�Ŀ���rhs��Ȼ���ٽ���hp��rhs��rhs��Ϊһ���м�ý�飬ֻ�𵽽�ֵ��hp2���ݸ�hp�����ã���һ������Ĳ���
    ���Ƶ��ڽ����ƶ���ֵʱ���ȴ�hp2ת�Ƶ�rhs���ٽ�����hpҲ������Ĳ�����
    ���ַ�ʽ��ʵ����ͳһ�˿������ƶ���ֵ���㣬���������ܽǶȶ���һ��rhs�ļ�Ӵ��ݣ����ܲ���
*/

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(hp2);



    cout << "Hello world!" << endl;
    return 0;
}
