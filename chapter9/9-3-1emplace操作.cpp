#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
/*
    C++11�±�׼�����������³�Ա ���� emplace_front,emplace,emplace_back����Щ������������ǿ���Ԫ�أ���Ӧpush_front,insert,push_back

    �ڵ���push��insert��Ա����ʱ�����ǽ�Ԫ�����͵Ķ��󴫵ݸ����ǣ���Щ���󱻿����������С�
    ������emplace��Ա����ʱ�����ǽ��������ݸ�Ԫ�����͵Ĺ��캯����emplace��Աʹ����Щ����������������ڴ�ռ���ֱ�ӹ���Ԫ��

    emplace�����Ĳ�������Ԫ�����Ͷ��仯������������Ԫ�����͵Ĺ��캯����ƥ��
*/
int main()
{
    //iterָ��c�е�һ��Ԫ�أ����б�����Sales_dataԪ��
    c.emplace_back();  //ʹ��Sales_data��Ĭ�Ϲ��캯��
    c.emplace(iter,"999-999999999");  //ʹ��Sales_data(string)
    //ʹ��Sales_data�Ľ���һ��ISBN��һ��count��һ��price�Ĺ��캯��
    c.emplace_front("978-0590353403",25,15.99);

    return 0;
}
