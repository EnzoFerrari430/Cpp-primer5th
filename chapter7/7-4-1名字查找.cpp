#include <iostream>
using namespace std;

typedef double Money;
string bal;
class Account
{
public:
    Money balance(){return bal;}  //balance��������������ɼ���ű��������Ըú���return ��Ϊbal�ĳ�Ա,��������������string����
private:
    //typedef int Money;  //�������¶���Money����ʹAccount�ж����Money���ͺ����������һ�£�����Ȼ�Ǵ���ġ�һЩ��������ͨ�������Ĵ��룬�����Դ����д����ʵ��
    Money bal;
};

int main()
{


    return 0;
}
