#include <stdio.h>

void run(int* pdata, int left, int right)
{
	int i, j;
	int middle, tmp;

	i = left;
	j = right;
	middle = pdata[left];

	do {
		while ((pdata[i] < middle) && (i < right))
			i++;
		while ((pdata[j] > middle) && (j > left))
			j--;

		if (i <= j)
		{
			tmp = pdata[i];
			pdata[i] = pdata[j];
			pdata[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		run(pdata, left, j);
	if (right > i)
		run(pdata, i, right);
}

void quick_sort(int* pdata, int count)
{
	run(pdata, 0, count-1);
}


int main(void)
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};

	quick_sort(data, 7);

	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
