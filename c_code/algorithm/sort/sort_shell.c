#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *a, int n)
{
	int k = n/2;
	int i, j, t;
	while (k > 0)
	{
		for (i = k; i< n; i++)
		{
			t = a[i];
#if 0
			//算法1
			j = i - k;
			while (j >= 0 && t < a[j])
			{
				a[j + k] = a[j];
				j = j - k;
			}
#endif
#if 0
//算法2
			j;
			for (j = i - k; j >= 0 && t < a[j]; j -= k)
				a[j + k] = a[j];
			a[j + k] = t;
#endif
#if 0
//算法3
			j;
			for (j = i; j >= k && t < a[j - k]; j -= k)
				a[j] = a[j - k];
			a[j] = t;
#endif
//算法4
			j = i;
			while (j >= k && t < a[j - k])
			{
				a[j] = a[j-k];
				j = j-k;
			}
			a[j] = t;
		}
		k /= 2;
	}
}

int main()
{
	int k;
	int a[10]= {8,10,3,5,7,4,6,1,9,2};
	shell_sort(a, sizeof(a)/sizeof(a[0]));

	for (k = 0; k < 10; k++)
		printf("a[%d] = %d\n", k, a[k]);
	return 0;
}
