#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
	pid_t  child_pid;
	// pid_t  parent_pid;

	double s = 0.0;

	FILE* fp;

	child_pid = fork();

	fp = fopen("test.dat","a+");

	if(child_pid != 0)
	{
		s += 3.14;
		cout << "CHILD: " << (int) getpid() << " s = " << s << " &s = " << &s << " fp = " << fp << endl;
		// fprintf(fp, "CHILD:  %i  s=%g &s=%u fp=%u\n", (int) getpid(),s,&s,fp);
	}

	else
	{
		s += 2.72;
		cout << "PARENT: " << (int) getpid() << " s = " << s << " &s = " << &s << " fp = " << fp << endl;
		// fprintf(fp, "PARENT: %i  s=%g &s=%u fp=%u\n",(int) getpid(),s, &s,fp);
	}

	fclose(fp);

	return 0;
}