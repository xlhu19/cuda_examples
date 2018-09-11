#include <stdio.h>

void select_sort(int * pdata, int count)
{
	int i, j, tem, pos;

	for (i = 0; i < count - 1; i++)
	{
		tem = pdata[i];
		pos = i;
		for (j = i + 1; j < count; j++)
		{
			if (pdata[j] < tem)
			{
				tem = pdata[j];
				pos = j;
			}
		}
		pdata[pos] = pdata[i];
		pdata[i] = tem;
	}
}

int main(void)
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};
	select_sort(data,7);
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
