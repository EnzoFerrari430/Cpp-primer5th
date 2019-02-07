#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED


#include <memory>
#include <iostream>
class String
{
    friend bool operator==(const String &,const String &);  //practice14.16
    friend bool operator!=(const String &,const String &);

    friend bool operator<(const String &,const String &);  //practice 14.18
    friend bool operator>(const String &,const String &);
    friend bool operator<=(const String &,const String &);
    friend bool operator>=(const String &,const String &);

    friend std::ostream& operator<<(std::ostream& output,const String &);
public:
    String():String(""){};
    String(char* pstart,char *pend);
    String(const char *);
    String(const String&);
    String& operator=(const String&);


    char* begin(){return elements;}
    char* end(){return first_free;}

    ~String();
    void push_back();

    const char *c_str() const {return elements;}
    size_t size() const {return first_free - elements;}
    size_t length() const {return first_free - elements;}

    //practice14.26
    //非常量版本
    char& operator[](size_t n){return elements[n];}
    //常量版本
    const char& operator[](size_t n)const{return elements[n];}

private:
    std::pair<char*,char*> alloc_n_copy(const char*,const char*);
    void range_initializer(const char*,const char*);  //用一个范围的字符串初始化
    void free();
private:
    char* elements;
    char* first_free;

    std::allocator<char> alloc;
};




#endif // STRING_H_INCLUDED
