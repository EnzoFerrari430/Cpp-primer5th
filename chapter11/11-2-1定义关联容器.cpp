#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
/*
    ÿ������������������һ��Ĭ�Ϲ��캯����������һ��ָ�����͵Ŀ�������
    ����Ҳ���Խ�����������ʼ��Ϊ��һ��ͬ���͵������Ŀ���
*/
int main()
{
    map<string,size_t> word_count;  //������

    //�б��ʼ��
    set<string> exclude = {"the","but","and","or","an","a"};
    //����ӳ��Ϊ��
    map<string,string> authors {
        {"Joyce","James"},
        {"Austen","Jane"},
        {"Dickens","Charles"}
    };

    return 0;
}
