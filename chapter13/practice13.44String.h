#ifndef PRACTICE13_44STRING_H_INCLUDED
#define PRACTICE13_44STRING_H_INCLUDED

#include <memory>

//�Լ���д����string��
class String
{
public:
    String();
    String(char* pstr);



    ~String();

private:
    char* elements;
    char* end;

    std::allocator<char> alloc;
};




#endif // PRACTICE13_44STRING_H_INCLUDED
