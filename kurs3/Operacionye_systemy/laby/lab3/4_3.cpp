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
		cout << "Process tree:" << endl;
		string lol = "pstree ";
		int i = (int) getppid();
		lol += to_string(i);
		system(lol.c_str());

		cout << "folder content:" << endl;
		lol = "cat /proc/";
		i = (int) getppid();
		lol += to_string(i);
		lol += "/task/";
		lol += to_string(i);
		lol += "/children";
		system(lol.c_str());
		cout << endl;

	}
	else sleep(2);
}