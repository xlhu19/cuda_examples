


#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
	{
		printf("you should input one directory!\n");
		return 0;
	}

	if ((dp = opendir(argv[1])) == NULL)
	{
		printf("directory is not exist!\n");
		return 0;
	}

	while ((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}

	close(dp);

	return 0;
}
