#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
int main()
{
    int ia[] = {0,2,4,6,8};
    int last = *(ia + 4);  //����iaǰ��4��Ԫ�غ���µ�ַ  �ȼ���ia[4]
    cout<<last<<endl;





    return 0;
}
