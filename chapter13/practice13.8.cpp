class HasPtr
{
public:
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}

    HasPtr& operator=(const std::string &s);

private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr &hp)
{-
    //ps = new std::string();
    //ps = *hp.ps;

    ps = new std::string( *hp.ps );  //����psָ��Ķ��󣬶����ǿ���ָ�뱾��
    i = hp.i;

}

HasPtr& HasPtr::operator=( const HasPtr &hp )
{
    std::string *temp_ps = new std::string( *hp.ps );
    delete ps;  //ɾ��ԭ�ȵ��ڴ�,�ͷ�����ڴ�
    ps = temp_ps;
    i = hp.i;
    return *this;
}

