#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	char* args[3];
	int code;
    // after "g++ try.cpp -o try"
	string str = "/media/rmshoeb/Porashuna/3-2/CSE_3202/lab-05-online/try";
	args[0] = (char*)str.c_str();
	args[1] = NULL;
	int pipefd[2];

	pipe(pipefd);
	int id = fork();

	if(id==0){
		printf("child\n");
		cout << getpid() << endl;

		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		if(execvp(args[0], args) == -1){
			perror("excvp");
		}
		_exit(1);
	}
	else if(id>0){
		// code = wait(0);
		printf("parent\n");
		cout << getpid() << endl;
		close(pipefd[0]);
		printf("Enter value: ");
		cin >> code;
		dup2(pipefd[1], STDOUT_FILENO);
		cout << code;
	}

	close(pipefd[0]);
	close(pipefd[1]);

	return 0;
}
