#include <iostream>
#include <string>
using namespace std;
/*

*/

//基类shape
class Shape
{
public:
    typedef std::pair<double,double> Coordinate;
    Shape() = default;
    Shape(const string& n):name(n){}

    //纯虚函数，抽象基类
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() = default;


private:
    std::string name;

};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string &n,const Coordinate &a,const Coordinate &b,const Coordinate &c,const Coordinate &d):Shape(n),a(a),b(b),c(c),d(d){}

    virtual ~Rectangle() = default;

protected:
    Coordinate a;
    Coordinate b;
    Coordinate c;
    Coordinate d;
};

class Square : public Rectangle
{
public:
    Square() = default;
    Square(const std::string &n,const Coordinate &a,const Coordinate &b,const Coordinate &c,const Coordinate &d):Rectangle(n,a,b,c,d){}
    virtual ~Square() = default;
};

int main()
{


    return 0;
}
