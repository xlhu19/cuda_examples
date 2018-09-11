#include <stdio.h>
#include <string.h>

int getgpsval(char* s)
{
	char du[10] = {0};
	char fen[10] = {0};
	char miao[10] = {0};
	char direction[10] = {0};
	char* tmp[10] = {0};
	int i = 0;

	tmp[i++] = strtok(s, ".'");
	while (tmp[i++] = strtok(NULL, ".'"))
	{
	}
#if 0
	for (i = 0; tmp[i]; i++)
		printf("%s--", tmp[i]);
	printf("\n");
#endif
	strcpy(fen, tmp[1]-3);
	*(tmp[1]-3) = 0;
	strcpy(du, tmp[0]);
	strcpy(miao, tmp[1]);
	strcpy(direction, tmp[2]);
#if 0
	printf("du %s, fen %s, miao %s, direction %s\n", du, fen, miao, direction);

	printf("du %d, fen %d, miao %d, direction %s\n",
               strtol(du, NULL, 10),
               strtol(fen, NULL, 10),
               strtol(miao, NULL, 10),
               direction);
#endif

	return 0;
}

int main()
{
	char str1[256] = {0};
	strcpy(str1, "3010.3341'N");
	getgpsval(str1);
	strcpy(str1, "11122.7865'N");
	getgpsval(str1);
	return 0;
}

/*

char* strtok(char *s, const char *delim);
分解字符串为一组字符串。s为要分解的字符串，delim为分隔符字符串。
首次调用时，s指向要分解的字符串，之后再次调用要把s设成NULL。
strtok在s中查找包含在delim中的字符并用NULL('')来替换，直到找遍整个字符串。
在调用的过程中，字串s被改变了，这点是要注意的。
从s开头开始的一个个被分割的串。当没有被分割的串时则返回NULL。
所有delim中包含的字符都会被滤掉，并将被滤掉的地方设为一处分割的节点。

*/
