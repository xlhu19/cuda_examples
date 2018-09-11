#include <stdio.h>
#include <malloc.h>

void print_prime(unsigned long size);

int main()
{
    print_prime(1000000);
}
/*������size-----���С��size����������*/
void print_prime(unsigned long size)
{//�������ɸѡ���ó�С��size����������
 //����size��С���ڴ棬��Ϊ�������Ǻ����ı�־��
 //Ȼ����������μ��㣬����Ǻ����ͼ�Ϊ0
 //���������е�����
 //���ַ����ܼ���������������ڴ��й�
 //һ����Ժܿ����100�����µ���������
    unsigned long i;
    unsigned long j;
    char* p = (char*)malloc(size);
    memset(p,1,size);
    
    for( i=2; i<size; i++ )
    {
        if(i*i>size)
            break;
        for( j=i; j<size; j++)
        {
            if(i*j>size)
                break;
            memset((p+i*j),0,1);
        }
    }
    
    for( i=2; i<size; i++ )
    {
        if(*(p+i)!=0)
            printf("%d  ", i);
    }
     printf("\n");
}
