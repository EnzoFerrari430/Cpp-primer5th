#include <iostream>
#include <vector>
#include <functional>
#include <map>
using namespace std;

/*
    ���ǲ��ܽ����غ��������ִ���function���͵Ķ�����
    ֱ�Ӵ�᲻֪��������һ��
*/

int add(int i,int j){return i + j;}
Sales_data add(const Sales_data &,const Sales_data &);
map<string ,function<int(int ,int)>> binops;
binops.insert({"+",add});  //���󣬲�֪�������ĸ�add

//��������������ʹ��һ������ָ��
int (*fp)(int,int) = add;  //fpָ����ָ��add����2��int�汾
binops.insert({"+",fp});

//Ҳ��ʹ��lambda��ָ������ϣ��ʹ��add�汾
binops.insert({"+",[](int a,int b){ return add(a+b); }});


int main()
{


    return 0;
}
