#include <iostream>
using namespace std;
/*


*/
int ff(int a,int b = 0,int c = 0);
//char *init(int ht = 24,int wd,char bckgrnd);  ���� ��Ĭ��ֵ���βκ�����βζ�Ҫ��Ĭ��ֵ

char *init(int ht,int wd = 80,char bckgrnd = ' ');

string make_plural(size_t ctr,const string &word,const string &ending = "s")
{
    return ctr>1? word + ending:word;
}
int main()
{
    //init();  ȱ�ٲ���
    //init(24,10);  //�Ϸ�
    //init(14,'*'); //�Ϸ�������'*'��ת����ascii�� ����wd
    cout<<make_plural(1,"tree","es")<<endl;
    cout<<make_plural(2,"table")<<endl;
    return 0;
}
