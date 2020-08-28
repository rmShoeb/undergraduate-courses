#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
    double x1, x2, x3;
    double xt;
    double xa[3];
    double nearest;

    xt = 1 / 3;
    cout << "your Values: ";
    cin >> x1 >> x2 >> x3;

    xa[0] = abs(xt - x1);
    xa[1] = abs(xt - x2);
    xa[2] = abs(xt - x3);

    if (xa[0] < xa[1] && xa[0] < xa[2])
        cout << x1 << endl;
    else if (xa[1] < xa[0] && xa[1] < xa[2])
        cout << x2 << endl;
    else
        cout << x3 << endl;
}
