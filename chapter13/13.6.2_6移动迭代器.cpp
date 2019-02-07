#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <utility>


/*

    C++11�±�׼���ж�����һ���ƶ�������������
    ������һ���ƶ�������ͨ���ı�����������Ľ��������������Ϊ������˵�������


    һ���������Ľ��������������һ��ָ��Ԫ�ص�  ��ֵ
    �ƶ��������Ľ��������������һ����ֵ����


    make_move_iterator������һ����ͨ�ĵ�����ת��Ϊһ���ƶ���������
    �����������һ������������������һ���ƶ�������


    ԭ�����������������������ƶ��������϶��ճ����������Կ��Խ��ƶ����������ݸ�uninitialized_copy
*/


class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){};  //Ĭ�Ϲ��캯��
    StrVec(const StrVec&);  //�������캯��������һ�������á���������������ͣ�ֵ���ݵĻ���ʵ�δ����βξ�Ҫ����һ�ο������죬�����������ﶼ��û����ɿ������졣����γ���ì�ܡ�
    StrVec& operator=(const StrVec&);  //�������ʹ������  1.��ֹ��û�ж��忽�����캯��֮��ʹ��Ĭ�ϵĿ������캯����ɵ�δ֪Ӱ�졣2.ʵ�δ����βλ����һ�ο�������Ҫ����CPU�Ŀ���

    ~StrVec();

    //����vector��һЩ�ӿں���
    std::string* begin()const{return elements;}  //stl������
    std::string* end()const{return first_free;}
    // !!!C++��const ���õ��Ƕ���ʱֻ�ܷ��ʸö����const ��������Ϊ���������п��ܻ��޸ĸö���ĳ�Ա��������Ϊ�˱���������鷢��������Ϊ���÷�const�����Ǵ���ġ�
    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}  //ע�⣡��:2��ͬ���ͣ�ָ��ͬһ�������ָ��������������������ָ����ֵ�ϵĲ���ǰ���������ָ��ָ�����͵Ĵ�С�Ľ����
    size_t capacity() const {return cap - elements;}  //��������

    bool empty() const {return (first_free - elements)? false : true; }  //�Ƿ�Ϊ�գ��ǿշ���true�����򷵻�false







private:

    std::allocator<std::string> alloc;  //����Ԫ��

    //4�����ߺ���
    void free();  //����Ԫ�أ����ͷ��ڴ�
    void reallocate();  //��ø�����ڴ沢�������е�Ԫ��
    //ȷ��StrVec����������һ����Ԫ�صĿռ�.���û�пռ������Ԫ�أ��ú�������reallocate���������Ŀռ�
    void chk_n_alloc(){
        if( size() == capacity() )
        {
            reallocate();
        }
    }

    //�����ڴ棬������һ��������Χ�е�Ԫ��,����1,2��ʾһ����Χ�е�Ԫ��
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string* ,const std::string*);


    std::string* elements;
    std::string* first_free;
    std::string* cap;
};


void StrVec::push_back(const std::string& s )
{
    chk_n_alloc();  //ȷ���пռ������µ�Ԫ��

    //��first_freeָ���Ԫ���й���s�ĸ���
    alloc.construct(first_free++,s);
}

//�ڿ������߸�ֵStrVecʱʹ�øú������ú�������һ��ָ���pair��2��ָ��ֱ�ָ���¿ռ�Ŀ�ʼλ�úͿ�����β��λ��
std::pair<std::string* ,std::string*> StrVec::alloc_n_copy(const std::string* b,const std::string* e)
{
    //data��ָ�룬ָ��alloc�����ԭʼ�ռ���׵�ַ
    auto data = alloc.allocate(e - b);

    //���Է��ػ������б�������ʱ�����г�ʼ��������һ���ڴ�ռ���׵�ַ����������һ����������b��e��ʾ��һ����Χ����ʼ��dataΪ�׵��ڴ��ַ������β����������������stringָ��
    return {data,uninitialized_copy(b,e,data)};
}

//free�����Ĺ��ܣ�1.destroyԪ�� 2.�ͷ�StrVec�Լ�������ڴ�ռ�
void StrVec::free()
{
    //���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ�գ�����ʲôҲ����
    if(elements)
    {
        //��������Ԫ��
        for(auto p = first_free; p!= elements;)
        {
            //destroy��pָ���Ԫ�ؽ�����������
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}



//�������캯��
StrVec::StrVec(const StrVec& s)
{
    //����alloc_n_copy����ռ���������s��һ�����Ԫ��
    //newdata��������pair<string*,string*>
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}


//��������
StrVec::~StrVec()
{
    free();
}


StrVec& StrVec::operator=(const StrVec& rhs)
{
    //�Ƚ����ݿ�������,��ô���ĺô��ǿ��Դ����Լ����Լ���ֵ�������
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

//���ƶ���������֪ʶ��д�ú���
//void StrVec::reallocate()
//{
//    //���䵱ǰ2����С���ڴ�ռ�
//    auto newcapacity = size()? 2*size() : 1;
//    //�����µ��ڴ�
//    auto newdata = alloc.allocate(newcapacity);  //newdataָ��������ݿռ��׵�ַ
//
//    auto dest = newdata;   //ָ������������һ������λ��
//    auto elem = elements;  //ָ�����������һ��Ԫ��
//
//    for(size_t i = 0; i!= size() ;++i)
//    {
//        alloc.construct(dest++,std::move(*elem++));
//    }
//    free();  //���Ԫ���ƶ����ͷž��ڴ�ռ�
//    elements = newdata;
//    first_free = dest;
//    cap = elements + newcapacity;
//
//
//}

void StrVec::reallocate()
{
    //���䵱ǰ2���С�Ŀռ�
    auto newcapacity = size()? 2*size() : 1;
    auto first = alloc.allocate(newcapacity);

    //�ƶ�Ԫ��
    //uninitialized_copy(inputit first,inputit last,forwardit d_first)  ��first last��ʾ��Χ�ڵ�Ԫ�ظ��Ƶ�d_firstΪ�׵�δ��ʼ�����ڴ���
    auto last = uninitialized_copy( make_move_iterator(begin()),make_move_iterator(end()),first );  //���������Ԫ�ص�β�������
    free();  //�ͷžɿռ�
    elements = first;  //����ָ��
    first_free = last;
    cap = elements + newcapacity;
    std::cout<<"move iterator makes reallocate more memory"<<std::endl;
}

int main()
{
    StrVec sv;
    sv.push_back("hello1");
    sv.push_back("hello2");
    sv.push_back("hello3");
    sv.push_back("hello4");
    sv.push_back("hello5");
    sv.push_back("hello6");




    for( auto it = sv.begin(); it != sv.end(); ++it )
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;


    return 0;
}
