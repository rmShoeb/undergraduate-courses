#ifndef FLOAT_H
#define FLOAT_H
#include<iostream>
using namespace std;
class Float
{
public:
    Float(float x=0.0);
    friend ostream& operator<<(ostream&, const Float&);
    float operator()()const;     ///overloading the function call operator
private:
    float m_x;
    static unsigned long m_get;
};
#endif // FLOAT_H
