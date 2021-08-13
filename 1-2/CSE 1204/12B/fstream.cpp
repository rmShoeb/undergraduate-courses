#include<fstream>
using namespace std;
int main(void)
{
    ofstream out("foo.txt");
    out<<"Hello world"<<endl;
    out.close();
}
