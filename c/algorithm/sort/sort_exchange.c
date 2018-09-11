#include <stdio.h>

void exchange_sort(int * pdata, int count)
{
	int i, j, tem;

	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (pdata[j] < pdata[i])
			{
				tem = pdata[i];
				pdata[i] = pdata[j];
				pdata[j] = tem;
			}
		}
	}
}

int main(void)
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};
	exchange_sort(data,7);
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
