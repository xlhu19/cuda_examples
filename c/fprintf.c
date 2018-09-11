

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i;
	int data = 5;
	char* str = "c4ddd7d3";
	FILE* fd;

	fd = fopen("fprintf_test_data.txt", "w");
	if (fd == NULL)
	{
		printf("open file error!\n");
		exit(0);
	}

	fprintf(fd, "%s, %d\n", str, data);
	fprintf(stdout, "%s, %d\n", str, data);

	return 0;
}
