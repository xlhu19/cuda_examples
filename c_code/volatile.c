#include<stdio.h>
#include<setjmp.h>

void f1(int cnt, int val, int sum);
void f2(void);

jmp_buf jmpbuffer;

int main(void)
{
	int cnt;
	register int val;
	volatile int sum;

	cnt = 2;
	val = 3;
	sum = 4;

	if (setjmp(jmpbuffer) != 0)
	{
		printf("LINE: %d, cnt == %d, val == %d, sum == %d\n", __LINE__, cnt, val, sum);
	}
	else
	{
		printf("LINE: %d, cnt == %d, val == %d, sum == %d\n", __LINE__, cnt, val, sum);
		cnt = 97;
		val = 98;
		sum = 99;
		f1(cnt, val, sum);
	}

	return 0;
}

void f1(int cnt, int val, int sum)
{
	printf("LINE: %d, cnt == %d, val == %d, sum == %d\n", __LINE__, cnt, val, sum);
	f2();
}

void f2(void)
{
	longjmp(jmpbuffer, 1);
}

