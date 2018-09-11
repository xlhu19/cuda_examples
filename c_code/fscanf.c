

#include <stdio.h>
#include <stdlib.h>

/*
fscanf 遇空格或回车结束
*/

int main()
{
	int i = 0, j;
	FILE* fd;
	char str[20];

	fscanf(stdin, "%d", &i);
	printf("i == %d\n", i);

	fd = fopen("fscanf_test_data.txt", "r");
	if (fd == NULL)
	{
		printf("open file error!\n");
		exit(0);
	}
	for (j = 0; j < 10; j++)
	{
		fscanf(fd, "%d%s", &i, str);
		printf("i == %d, str == %s\n", i, str);
	}

	return 0;
}
