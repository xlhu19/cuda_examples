#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int p, int q, int r)
{
	int i,k;
	int begin1, end1, begin2, end2;
	int* temp = (int*)malloc((r-p+1) * sizeof(int));
	begin1= p;
	end1 = q;
	begin2 = q+1;
	end2 = r;
	k = 0;
	while ((begin1 <= end1) && ( begin2 <= end2))
	{
		if (array[begin1] < array[begin2])
		{
			temp[k] = array[begin1];
			begin1++;
		}
		else
		{
			temp[k] = array[begin2];
			begin2++;
		}
		k++;
	}
	while(begin1<=end1)
	{
		temp[k++] = array[begin1++];
	}
	while(begin2<=end2)
	{
		temp[k++] = array[begin2++];
	}
	for (i = 0; i <= (r - p); i++)
		array[p+i] = temp[i];
	free(temp);
}

void MergeSort(int array[], int first, int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first+last)/2;
		MergeSort(array, first, mid);
		MergeSort(array, mid+1,last);
		merge(array, first, mid, last);
	}
}

int main()
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};

	MergeSort(data, 0, 6);

	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
