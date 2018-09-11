#include <stdio.h>
#include <stdlib.h>

void HeapAdjust(int array[], int i, int nLength)
//�����������ǣ���������array���������
{
	int nChild;
	int nTemp;
	for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild)
	{
		// �ӽ���λ��=2*(�����λ�ã�+ 1
		nChild = 2 * i + 1;
		// �õ��ӽ���нϴ�Ľ��
		if (nChild < nLength - 1 && array[nChild + 1] > array[nChild])
			++nChild;
			// ����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ�,�滻���ĸ����
		if (nTemp < array[nChild])
		{
			array[i]= array[nChild];
		}
		else
		// �����˳�ѭ��
			break;
		{
		}
		// ������Ҫ������Ԫ��ֵ�ŵ����ʵ�λ��
		array[nChild]= nTemp;
	}
}

// �������㷨
void HeapSort(int array[], int length)
{
	// �������е�ǰ�벿��Ԫ��,������֮���һ��Ԫ�������е�����Ԫ��
	for (int i = length / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(array, i, length);
	}
	// �����һ��Ԫ�ؿ�ʼ�����н��е���,���ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (int i = length - 1; i > 0; --i)
	{
		// �ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ���, 
		// ��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
		Swap(&array[0], &array[i]);
		// ������С����heap�ķ�Χ,ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
		HeapAdjust(array, 0, i);
	}
} 


int main()
{
	int i;
	int data[7] = {10, 9, 8, 7, 6, 5, 4};

	HeapSort(data, 7);

	for (i = 0; i < 7; i++)
	{
		printf("%d  ", data[i]);
	}
	printf("\n");

	return 0;
}
