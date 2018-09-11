#include <stdio.h>
#include <malloc.h>

void print_prime(unsigned long size);

int main()
{
    print_prime(1000000);
}
/*参数：size-----输出小于size的所有素数*/
void print_prime(unsigned long size)
{//按定义的筛选法得出小于size的所有素数
 //分配size大小的内存，作为素数还是合数的标志，
 //然后如果是依次计算，如果是合数就记为0
 //最后输出所有的素数
 //这种方法能计算的最大的素数跟内存有关
 //一般可以很快计算100万以下的所有素数
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
