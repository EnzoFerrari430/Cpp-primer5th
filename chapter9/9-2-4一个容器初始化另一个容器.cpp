#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;
/*
    C c(b,e) c��ʼ��Ϊb��eָ����Χ��Ԫ�صĿ�������Χ��Ԫ�ص����ͱ�����C��Ԫ����������(array������)


    Ϊ�˴���һ������Ϊ��һ�������Ŀ������������������ͼ���Ԫ�����ͱ���ƥ�䡣�����������ݵ���������������һ����Χʱ���Ͳ�Ҫ��
    ��������������ͬ���ˡ����ң���������ԭ�����е�Ԫ������Ҳ���Բ�ͬ��ֻҪ�ܽ�Ҫ������Ԫ��ת��ΪҪ��ʼ����������Ԫ�����ͼ���
*/
int main()
{
    list<string> authors = {"Milton","Shakespeare","Austen"};
    vector<const char *>articles = {"a","an","the"};

    list<string> list2(authors);
    //deque<string> authList(authors);  //error  �������Ͳ�ƥ��
    //vector<string> words(articles);   //error  �������ͱ���ƥ��

    //���Խ�const char*ת��Ϊstring
    forward_list<const char *> words(articles.begin(),articles.end());
    for(auto c:words)
    {
        cout<<c<<' ';
    }

    return 0;
}
