#include "Float.h"
Float::Float(float x):m_x(x)
{

}

unsigned long Float::m_get(0);

float Float::operator()()const
{
    m_get++;
    return m_x;
}
