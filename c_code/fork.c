

#include <unistd.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	int pid = fork();
	if (pid == -1)
	{
		printf("error!");
	}
	else if(pid ==0 )
	{
		printf("This is the child process!\n");
	}
	else
	{
		printf("This is the parent process! child process id = %d\n", pid);
	}
	return 0;
}
