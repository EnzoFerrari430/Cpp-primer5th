#include <iostream>
#include "Query_base.h"
using namespace std;

int main()
{
    std::string sFile("tial.txt");
    std::ifstream in(sFile);
    TextQuery(in);
    //cout << "Hello world!" << endl;
    return 0;
}
