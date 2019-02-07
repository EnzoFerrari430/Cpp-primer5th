#ifndef TEXTQUERY_H_INCLUDED
#define TEXTQUERY_H_INCLUDED
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using line_no = std::vector<std::string>::size_type;  //�����к�
class QueryResult;  //Ϊ�˶��庯��query�ķ�������

class TextQuery
{
public:
    TextQuery(std::ifstream &);  //���캯��,�������ļ���
    QueryResult query(const std::string &s) const;

private:
    std::shared_ptr<std::vector<std::string>> file;  //ָ�������ļ���ָ��
    std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;  //ÿ�����ʵ������кŵļ���

};

class QueryResult
{
    friend std::ostream &print(std::ostream&,const QueryResult&);
private:
    std::string sought;  //��ѯ�ĵ���
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<line_no>> lines;
public:
    QueryResult( std::string s,std::shared_ptr<std::set<line_no>> ss ,std::shared_ptr<std::vector<std::string>> svs)
    :sought(s)
    ,lines(ss)
    ,file(svs)
    {

    }

	std::shared_ptr<std::vector<std::string>> get_file()const { return file; }
	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end() { return lines->end(); }

};


#endif // 12-3-2TEXTQUERY_H_INCLUDED
