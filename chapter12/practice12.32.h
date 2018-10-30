#ifndef PRACTICE12_32_H_INCLUDED
#define PRACTICE12_32_H_INCLUDED

#include "practice12.22.h"
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
    TextQuery(ifstream &infile);  //构造函数
    QueryResult query(const string&) const;

public:
    vector<string> sTxts;  //输入的文本
    map<string,set<int>> row;  //单词出现的行

    StrBlob input;
    map<string,shared_ptr<set<LineNo>>> result;


};

class QueryResult
{
public:
    friend ostream &print(ostream &,const QueryResult&);
public:
    QueryResult(const string &s,shared_ptr<std::set<TextQuery::LineNo>> set, const StrBlob& v):word(s), nos(set), input(v){}
private:
    string word;
    StrBlob input;
    shared_ptr<set<TextQuery::LineNo>> nos;
};

ostream& print(ostream&,const QueryResult&);


#endif // PRACTICE12_32_H_INCLUDED
