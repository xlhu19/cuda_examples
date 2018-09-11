#include <stdio.h>

/*

sprintf和printf基本一样的格式
下面只列出区别

*/
int main()
{
	int                  len;
	char                 buf[256];
	double               data_04 = -1314.743;

	len = sprintf(buf, "%e", data_04);
	printf("len == %d, buf == %s\n", len, buf);
	len = sprintf(buf, "%.*e", 1, data_04);
	printf("len == %d, buf == %s\n", len, buf);

	return 0;
}
