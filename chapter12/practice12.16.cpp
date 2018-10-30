#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
int main()
{

    unique_ptr<int> p1(new int(42));
    unique_ptr<int> p2(p1);  //¿½±´
    unique_ptr<int> p3;
    p3 = p1;  //¸³Öµ


    return 0;
}
