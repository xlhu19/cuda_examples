

#include <stdio.h>

/*
二进制数除法
多项式除法
*/

//D10 + D8 + D6 + D5 + D4 + D2 + 1
unsigned int ulPolynomial_sch[10] = {0, 1, 0, 1, 1, 1, 0, 1, 0, 1};


int check_parity(unsigned int* data, int d_len, unsigned int* poly, int p_len)
{
	int i;
	int ps;
	unsigned int re[50];

	for (i = 0; i < p_len + 1; i++)
	{
		re[i] = data[i];
	}
	ps = p_len + 1;

	while (ps <= (d_len))
	{
		if (re[0] == 0)
		{
			for (i = 0; i < p_len; i++)
			{
				re[i] = re[i+1];
			}
			re[p_len] = data[ps];
			ps++;
		}
		else
		{
			for (i = 0; i < p_len; i++)
			{
				re[i] = poly[i]^re[i+1];
			}
			re[p_len] = data[ps];
			ps++;
		}
	}

	printf("PARITY!\n");
	for (i = 0; i < p_len; i++)
	{
		printf("%d  ", re[i]);
	}
	printf("\n");
	return 0;
};


int main(void)
{
//	unsigned int test_data[16] = {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1};
//	check_parity(&(test_data[0]), 16, &(ulPolynomial_sch[0]), 10);
//	unsigned int test_data_2[11] = {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1};
//	check_parity(&(test_data_2[0]), 11, &(ulPolynomial_sch[0]), 10);
	unsigned int test_data_3[] = 
	{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1};
	check_parity(&(test_data_3[0]), 35, &(ulPolynomial_sch[0]), 10);

//	unsigned int test_data_4[] = 
//	{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0};
//	check_parity(&(test_data_4[0]), 35, &(ulPolynomial_sch[0]), 10);

	return 0;
}
