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
�ֽ��ַ���Ϊһ���ַ�����sΪҪ�ֽ���ַ�����delimΪ�ָ����ַ�����
�״ε���ʱ��sָ��Ҫ�ֽ���ַ�����֮���ٴε���Ҫ��s���NULL��
strtok��s�в��Ұ�����delim�е��ַ�����NULL('')���滻��ֱ���ұ������ַ�����
�ڵ��õĹ����У��ִ�s���ı��ˣ������Ҫע��ġ�
��s��ͷ��ʼ��һ�������ָ�Ĵ�����û�б��ָ�Ĵ�ʱ�򷵻�NULL��
����delim�а������ַ����ᱻ�˵����������˵��ĵط���Ϊһ���ָ�Ľڵ㡣

*/
