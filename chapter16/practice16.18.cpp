/*

a)  template <typename T,U,typename V> void f1(T,U,V);
    Uǰ��Ҫ��typename�ؼ��֣�ָ��U�����Ͳ���
b)  template <typename T> T f2(int &T);
    ���������У�ģ���������������,����T����Ϊ�˺���������
c)  inline template <typename T> T foo(T,unsigned int*);
    inline�ؼ�����ģ������б�֮�󣬺�����������֮ǰ��
    ӦΪ
    template <typename T> inline T foo(T,unsigned int*);
d)  template <typename T> f4(T,T);
    û�з�������
e)
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);
û������typedef��������



*/
