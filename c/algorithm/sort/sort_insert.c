#include <stdio.h>

void insert_sort(int * pdata, int count)
{
	int i, tem, pos;

	for (i = 1; i < count; i++)
	{
		tem = pdata[i];
		pos = i-1;
		while ( (pos >= 0) && (tem < pdata[pos]) )
		{
			pdata[pos+1] = pdata[pos];
			pos--;
		}
		pdata[pos+1] = tem;
	}
}

int main(void)
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};
	insert_sort(data,7);
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
