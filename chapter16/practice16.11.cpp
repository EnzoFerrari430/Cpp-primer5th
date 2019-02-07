#include <iostream>
#include <string>
using namespace std;

template <typename elemType> class ListItem;
template <typename elemType>
class List
{

public:
    List<elemType>();  //而这里的List<elemType>是在类内的，所以这里可以简化为List
    List<elemType>(const List<elemType>&);
    List<elemType>& operator=(const List<elemType>&);
    ~List();
    void insert(ListItem *ptr,elemType value);  //这里的ListItem不是一个类型，只有使用ListType<elemType>才是一个类型
private:
    ListItem *front,*end;  //这里的ListItem也要给模板参数列表
};

int main()
{


    return 0;
}
