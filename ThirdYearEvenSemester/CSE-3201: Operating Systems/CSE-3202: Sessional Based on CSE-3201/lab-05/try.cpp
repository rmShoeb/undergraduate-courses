#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	printf("Another\n");
	cin >> n;
	for(int i=0; i<n; i++) cout << i << endl;
	return 0;
}
