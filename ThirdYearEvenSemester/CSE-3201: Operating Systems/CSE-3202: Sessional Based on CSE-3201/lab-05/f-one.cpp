#include <iostream>
#include <syscall.h>
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[])
{
	printf("Hello world\n");
	printf("m1\n");
	int id = fork();
	printf("m2\n");
	int id2 = fork();
	printf("m3\n");

	return 0;
}
