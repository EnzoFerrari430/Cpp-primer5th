#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Student
{
public:
    Student();
    Student(const char *p);

    ~Student();
private:
    //std::pair<char*,char*>

private:
    char *p;


};

int main()
{

    string s("helloworld");
    cout<<s<<endl;
    cout<<s.size()<<endl;
    cout<<s.length()<<endl;

    return 0;
}
