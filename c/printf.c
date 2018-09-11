

#include <stdio.h>


int main()
{
	char                 char_01 = 'n';
	int                  data_01 = 1991;
	int                  data_02 = -1991;
	float                data_03 = 0.311;
	double               data_04 = -1314.743;
	int                  data_05 = 0xc4ddd7d3;
	char*                stri_01 = "nzydnhxlqmdj";
	char*                pint_01 = NULL;
	char*                pint_02 = "abc";
//	long long            data_06 = 0xc4ddd7d3c4ddd7d3;

	/* % basic */
	/*
	%c, %s, 字符和字符串
	%d, %u, 整形十进制计数法
	%hd，%hu，输出短整型
	%ld，%lu，输出长整形
	%f, %F, 浮点数十进制计数法，默认6位小数
	%g, %G, 根据浮点数自动选择%f或%e计数法,根据宽度较小的方式选择
	%e, %E, 浮点数e计数法，默认6位小数
	%x, %X, 十六进制计数法
	%%, %p, %和指针

	*/
	printf("==========================================================\n");
	printf("char_01 == %c(%%c)\n", char_01);
	printf("data_01 == %d(%%d)\n", data_01);
	printf("data_02 == %d(%%d), %u(%%u)\n", data_02, data_02);
	printf("data_03 == %f(%%f), data_04 == %f(%%f), %e(%%e)\n", data_03, data_04, data_04);
	printf("data_03 == %F(%%F), data_04 == %F(%%F), %E(%%E)\n", data_03, data_04, data_04);
	printf("data_03 == %g(%%g), data_04 == %g(%%g)\n", data_03, data_04);
	printf("data_03 == %G(%%G), data_04 == %G(%%G)\n", data_03, data_04);
	printf("data_05 == 0x%x(%%x), 0X%X(%%X)\n", data_05, data_05);
	printf("stri_01 == %s(%%s)\n", stri_01);
	printf("pint_01 == %p(%%p)\n", pint_01);
	printf("pint_02 == %p(%%p)\n", pint_02);
	printf("data_05 == %hd(%%hd)\n", data_05);
	printf("data_05 == %ld(%%ld)\n", data_05);
//	printf("data_06 == %ld(%%ld)\n", data_06);
	printf("==========================================================\n");
	/* flags */
	/*
	-，左对齐，右边填充空格
	+，在数字前加+或者-表示正负
	n，宽度为n，如果实际多于n按实际输出，不足补齐空格
	0n，宽度为n，不足补齐0
	.n，表示输出的小数点后的位数，或者字符串的字符个数
	#，只能用于x，X，o，在数字前加上0x，0X，o
	*/
	printf("==========================================================\n");
	printf("data_03 == %-f, %-e\n", data_03, data_03);
	printf("data_04 == %-f, %-e\n", data_04, data_04);
	printf("data_03 == %+-f, %-+e\n", data_03, data_03);
	printf("data_04 == %+-f, %-+e\n", data_04, data_04);
	printf("data_04 == %15f, %015e\n", data_04, data_04);
	printf("data_04 == %15.1f, %015.1e\n", data_04, data_04);
	printf("stri_01 == %.5s\n", stri_01);
	printf("data_05 == %#x, %#X\n", data_05, data_05);
	printf("==========================================================\n");
	/* advanced */
	/*
	\a，振铃
	\r，回车
	\n，换行
	*/


	return 0;
}

/*
输出结果
==========================================================
char_01 == n(%c)
data_01 == 1991(%d)
data_02 == -1991(%d), 4294965305(%u)
data_03 == 0.311000(%f), data_04 == -1314.743000(%f), -1.314743e+03(%e)
data_03 == 0.311000(%F), data_04 == -1314.743000(%F), -1.314743E+03(%E)
data_03 == 0.311(%g), data_04 == -1314.74(%g)
data_03 == 0.311(%G), data_04 == -1314.74(%G)
data_05 == 0xc4ddd7d3(%x), 0XC4DDD7D3(%X)
stri_01 == nzydnhxlqmdj(%s)
pint_01 == (nil)(%p)
pint_02 == 0x8048755(%p)
data_05 == -10285(%hd)
data_05 == -992094253(%ld)
==========================================================
==========================================================
data_03 == 0.311000, 3.110000e-01
data_04 == -1314.743000, -1.314743e+03
data_03 == +0.311000, +3.110000e-01
data_04 == -1314.743000, -1.314743e+03
data_04 ==    -1314.743000, -001.314743e+03
data_04 ==         -1314.7, -00000001.3e+03
stri_01 == nzydn
data_05 == 0xc4ddd7d3, 0XC4DDD7D3
==========================================================
*/
