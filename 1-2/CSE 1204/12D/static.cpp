#include "Float.cpp"

#define ITERN 2
ostream& operator<<(ostream& out, const Float& p)
{
    out<<"("<<p.m_x<<","<<p.m_y<<")";
    return out;
}

