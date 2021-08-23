#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char const *argv[])
{
	pid_t pid = fork();
	if(pid == 0){
		printf("child");
	}
	return 0;
}
