#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

struct Data
{
    int ival;
    string s;


};
//Specifies that a type is a literal type.
//Literal types are the types of constexpr variables and they can be constructed, manipulated, and returned from constexpr functions.

//ָ������������ֵ���͡� ����ֵ������constexpr���������ͣ����ǿ��Ա����죬�����ʹ�constexpr�������ء�

//7.56���ǣ�string��������ֵ����

int main()
{
    cout<<boolalpha;
    cout<<is_literal_type<Data>::value<<endl;  //�����Ƿ������һ������constexpr������ɹ��죬��ʹ�ã���ӷ���constexpr������
    return 0;
}
