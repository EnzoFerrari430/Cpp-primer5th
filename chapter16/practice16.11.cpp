#include <iostream>
#include <string>
using namespace std;

template <typename elemType> class ListItem;
template <typename elemType>
class List
{

public:
    List<elemType>();  //�������List<elemType>�������ڵģ�����������Լ�ΪList
    List<elemType>(const List<elemType>&);
    List<elemType>& operator=(const List<elemType>&);
    ~List();
    void insert(ListItem *ptr,elemType value);  //�����ListItem����һ�����ͣ�ֻ��ʹ��ListType<elemType>����һ������
private:
    ListItem *front,*end;  //�����ListItemҲҪ��ģ������б�
};

int main()
{


    return 0;
}
