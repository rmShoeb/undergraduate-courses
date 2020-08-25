#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

bool negation(bool p)
{
    return (!p);
}

bool conjunction(bool p, bool q)
{
    return (p&&q);
}

bool disjunction(bool p, bool q)
{
    return (p||q);
}

bool condition_al(bool p, bool q)
{
    return ((!p)||q);
}

bool x_or(bool p, bool q)
{
    return ((p&&(!q))||((!p)&&q));
}

bool bi_conditional(bool p, bool q)
{
    return ((p||(!q))&&((!p)||q));
}

int main(void)
{
    bool p,q;

    printf(" P | Q | !P | !Q | P^Q | PvQ | P->Q | P<->Q | P(+)Q\n");
    printf("---------------------------------------------------\n");
    for(p=0;;p++)
    {
        for(q=0;;q++)
        {
            printf(" %d | %d |  %d |  %d |  %d  |  %d  |  %d   |   %d   |   %d\n",p,q,negation(p),negation(q),conjunction(p,q),disjunction(p,q),condition_al(p,q),bi_conditional(p,q),x_or(p,q));
            printf("---------------------------------------------------\n");
            if(q)
                break;
        }
        if(p)
            break;
    }
}
