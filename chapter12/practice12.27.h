#ifndef PRACTICE12_27_H_INCLUDED
#define PRACTICE12_27_H_INCLUDED
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
using namespace std;

class QueryResult;
class TextQuery
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(ifstream &infile);  //���캯��
    QueryResult query(const string&) const;

public:
    vector<string> sTxts;  //������ı�
    map<string,set<int>> row;  //���ʳ��ֵ���

    shared_ptr<vector<string>> input;
    map<string,shared_ptr<set<LineNo>>> result;


};

class QueryResult
{
public:
    friend ostream &print(ostream &,const QueryResult&);
public:
    QueryResult(const string &s,shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v):word(s), nos(set), input(v){}
private:
    string word;
    shared_ptr<vector<string>> input;
    shared_ptr<set<TextQuery::LineNo>> nos;
};


#endif // PRACTICE12_27_H_INCLUDED
