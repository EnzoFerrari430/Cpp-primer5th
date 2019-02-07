/*

    practice14.30
        看StrBlob项目


    practice14.31
        根据3/5法则，这里没有需要动态分配内存的情况，使用合成的版本就已经足够了


*/

//practice 14.32

class StrBlobPtr;

class StrBlobPtr_pointer
{
public:
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr *p):pointer(p) {}

    StrBlobPtr &operator*()const;
    StrBlobPtr *operator->()const;

private:
    StrBlobPtr *pointer = nullptr;
};

StrBlobPtr &StrBolbPtr_pointer::operator*()const
{
    return *pointer;
}

StrBlobPtr *StrBlobPtr_pointer::operator->()const
{
    return pointer;
}
