class HasPtr
{
public:
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}



private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr &hp)
{
    //ps = new std::string();
    //ps = *hp.ps;

    ps = new std::string( *hp.ps );  //����psָ��Ķ��󣬶����ǿ���ָ�뱾��
    i = hp.i;

}
