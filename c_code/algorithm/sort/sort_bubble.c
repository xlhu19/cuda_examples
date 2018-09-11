#include <stdio.h>


void bubble_sort(int * pdata, int count)
{
	int i, j, tem;

	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if ( pdata[j] < pdata[j-1] )
			{
				tem = pdata[j-1];
				pdata[j-1] = pdata[j];
				pdata[j] = tem;
			}
		}
	}
}

int main(void)
{
	int i;
	int data[7] = {10,9,8,7,6,5,4};
	bubble_sort(data,7);
	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
