/*

    practice14.30
        ��StrBlob��Ŀ


    practice14.31
        ����3/5��������û����Ҫ��̬�����ڴ�������ʹ�úϳɵİ汾���Ѿ��㹻��


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
