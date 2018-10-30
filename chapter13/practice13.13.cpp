#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Grade
{
public:
    string m_sLesson;
    int m_nScore;
public:
    Grade()
    {
        cout<<"Grade()"<<endl;
    }
    Grade( const Grade& rhs)
    {
        cout<<"Grade(const Grade&)"<<endl;
        m_sLesson = rhs.m_sLesson;
        m_nScore = rhs.m_nScore;
    }
    ~Grade()
    {
        cout<<"~Grade()"<<endl;
    }
    Grade operator=(const Grade &rhs)
    {
        cout<<"Grade operator="<<endl;
        m_sLesson = rhs.m_sLesson;
        m_nScore = rhs.m_nScore;
        return *this;
    }

};


int main()
{
    Grade pjd;
    pjd.m_sLesson = "math";
    pjd.m_nScore = 100;
    Grade wf(pjd);
    cout<<wf.m_sLesson<<" "<<wf.m_nScore<<endl;
    Grade yxl = pjd;
    cout<<yxl.m_sLesson<<" "<<yxl.m_nScore<<endl;

    vector<Grade> clss;
    clss.push_back(pjd);
    clss.push_back(yxl);
    clss.push_back(yxl);
    clss.push_back(yxl);
    return 0;
}
