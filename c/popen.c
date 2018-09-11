#include <stdio.h>

/*

FILE * popen (const char * command, const char * type);
int pclose (FILE * stream);

*/

int main()
{
	int i;
	FILE *fp;
	char cmd[128];
	char buf[1024];

	sprintf(cmd, "ls -l");
	fp = popen(cmd, "r");
	if (fp != NULL) {
		fread(buf, 1024, 1, fp);
		pclose(fp);
	}

	printf("%s\n", buf);

	return 0;
}
