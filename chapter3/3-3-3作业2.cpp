#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1(10,42);
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    vector<int> v3 = v2;
    return 0;
}
