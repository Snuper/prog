#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	pid_t  child_pid;
	double s = 0.0;

	child_pid = fork();

	cout << endl << child_pid;

	if(child_pid == 0)
	{
		s += 3.14;
		cout << "CHILD: " << (int) getpid() << " s = " << s << " &s = " << &s << endl;
		// fprintf(stdout, "CHILD:  %i  s=%g &s = %u\n", (int) getpid(), s, &s);
	}
	
	else	
	{
		s += 2.72;
		cout << "PARENT: " << (int) getpid() << " s = " << s << " &s = " << &s << endl;
		// fprintf(stdout, "PARENT: %i  s=%g &s = %u\n", (int) getpid(), s, &s);
	}
	
	return 0;
}