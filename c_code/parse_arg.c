


/*

#include<unistd.h>
函数定义
int getopt
(
int argc,
char * const argv[ ],
const char * optstring
);
全局变量
extern char* optarg;//-f 后面带的参数
extern int optind;
extern int opterr;
extern int optopt;//没有找到的参数

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


struct str_arg_value
{
	int count;
	int debug_flag;
	char filename[20];
};

int parse_arg(int argc, char** argv, struct str_arg_value* arg_val)
{
	int ch;
	char* short_options = "c:df:";

	while ((ch = getopt(argc, argv, short_options)) != -1)
	{
		switch (ch)
		{
			case 'c':
				break;
			case 'd':
				arg_val->debug_flag = 1;
				printf("option debug\n");
				break;
			case 'f':
				strcpy(arg_val->filename, optarg);
				printf("option -f %s\n", arg_val->filename);
				break;
			case ':':
				opterr = 0;
				printf("option requires an argument\n");
				break;
			case '?':
				opterr = 0;
				printf("can not find option %c\n", optopt);
				break;
		}
	}

	printf("optind: %d\n", optind);
	return 0;
}

int parse_arg_long(int argc, char** argv, struct str_arg_value* arg_val)
{
	int ch;
	char* short_options = "c:df:";
	struct option long_options[4] =
	{
		{"count", 1, NULL, 'c'},
		{"debug", 0, NULL, 'd'},
		{"file", 1, NULL, 'f'},
		{NULL, 0, NULL, 0}
	};

	while ((ch = getopt_long(argc, argv, short_options, long_options, NULL)) != -1)
	{
		switch (ch)
		{
			case 'c':
				break;
			case 'd':
				arg_val->debug_flag = 1;
				printf("option debug\n");
				break;
			case 'f':
				strcpy(arg_val->filename, optarg);
				printf("option -f %s\n", arg_val->filename);
				break;
			case ':':
				opterr = 0;
				printf("option requires an argument\n");
				break;
			case '?':
				opterr = 0;
				printf("can not find option %c\n", optopt);
				break;
		}
	}

	printf("optind: %d\n", optind);
	return 0;
}


int main(int argc, char** argv)
{
	struct str_arg_value arg_val;


	parse_arg(argc, argv, &arg_val);
	parse_arg_long(argc, argv, &arg_val);

	return 0;
}
