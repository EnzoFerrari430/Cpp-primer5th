#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>  //bind�������ڵ�ͷ�ļ�
using namespace std;
//using std::placeholders::_1;  //�������� _1 ����ÿ��ռλ�����ֶ�Ҫ�ṩһ��������using����,���鷳
//using namespace namespace_name����ʽ˵��ϣ����������namespace_name�����ֶ����������ǵĳ�����ֱ��ʹ��
using namespace std::placeholers;

/*
    ���ڲ���ֲ�������lambda���ú������滻���Ͳ�����ô�����ˣ�
    ��������find_if�����е�lambda�Ƚ�һ��string��һ��������С�����ǿ��Ժ����׵ر�дһ�������ͬ�����ĺ���
*/
bool check_size(const string &s,string::size_type sz)
{
    return s.size() >= sz;
}

//���ǣ����ǲ��������������Ϊfind_if��һ����������ǰ����ʾ��find_if����һ��һԪν��
//C++11�±�׼ ʹ��һ���µ���Ϊbind�ı�׼�⺯���������check_size����һ�����Ȳ���������,������ͷ�ļ�functional��
//bind�������Կ�����һ��ͨ�õĺ���������,����һ���ɵ��ö��������µĿɵ��ö���������Ӧ��ԭ����Ĳ����б�
/*
    ����bind��һ����ʽ
    auto newCallble = bind(callble,arg_list);
    ����newCallble������һ���ɵ��ö���arg_list��һ�����ŷָ��Ĳ����б�,��Ӧ������callble�Ĳ�����
    �����ǵ���newCallbleʱ��newCallble�����callble�������ݸ���arg_list�еĲ���
    ��arg_list�еĲ������ܰ�������_n�����֣�����n��һ����������Щ�����ǡ�ռλ��������ʾnewCallble�Ĳ���,����ռ���˴��ݸ�newCallble�Ĳ�����λ��
    _1ΪnewCallble�ĵ�һ��������_2Ϊ�ڶ�������
*/
//��check_size��sz����
//check6��һ���ɵ��ö��󣬽���һ��string���͵Ĳ���
//���ô�string��ֵ6������check_size
auto check6 = bind(check_size,_1,6);
//��bind����ֻ��һ��ռλ������ʾcheck6ֻ���ܵ�һ������һԪν��
//ռλ��������arg_list�ĵ�һ��λ�á���ʾcheck6�Ĵ˲�����Ӧcheck_size�ĵ�һ���������˲�����һ��const string &��
//��ˣ�����check6���봫�ݸ���һ��string���͵Ĳ�����check6�Ὣ�˲������ݸ�check_size
string s = "hello";
bool b1 = check6(s);  //check6(s) ����� check_size(s,6);
/*
    ������lambda��find_if����
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a));

    �滻Ϊ����ʹ��check_size�İ汾
    auto wc = find_if(words.begin(),words.end(),bind(check_size,_1,sz));
*/



int main()
{


    return 0;
}
