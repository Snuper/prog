#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include <string>

using namespace std;

int main()
{
	pid_t child;
	child = fork();

	if(child == 0)
	{
		string lol = "ps -e | grep ";
		int i = (int) getppid();
		lol += to_string(i);
		
		cout << "parent = " << getppid() << endl;
		system(lol.c_str());

		lol = "ps -e | grep ";
		i = (int) getpid();
		lol += to_string(i);

		system(lol.c_str());

		kill((int) getppid(), SIGKILL);

		cout << "child = " << getpid() << endl;
	}
	else sleep(2);
}