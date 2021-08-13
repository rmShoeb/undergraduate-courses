#include<fstream>
using namespace std;
int main(void)
{
    ofstream out;
    out.open("foo.tmp");
    out<<"Yowzer!!!"<<endl;
    out.close();
}
