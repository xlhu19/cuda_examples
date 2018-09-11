#include <stdio.h>   
unsigned long int crc32_table[256];   
unsigned long int ulPolynomial=0x04c11db7;   
unsigned   long int  GenerateCRC32(char*   DataBuf,unsigned   long    int len);
unsigned long int UPDC32(char octet,unsigned long int crc) ;
unsigned long int crc32_loader(char *sp,unsigned long int len) ;
cal_crc32_table()
{
	int i;
	for(i=0;i<256;i++)
	{
		unsigned long int crc32;
		crc32=i;		
		crc32=crc32<<24;
		//printf("crc32:%x\t",crc32);
		int j;
		for(j=0;j<8;j++)
		{
			if((crc32&0x80000000)==0)
			{
				crc32=crc32<<1;
			}
			else
			{
				crc32=(crc32<<1)^ulPolynomial;
			}
		}
		crc32_table[i]=crc32;   
	}	
} 

int main()
{
		//init_crc32_table();
		cal_crc32_table();
		int i;
		for(i=0;i<256;i++)
		{
			printf("%8x\t",crc32_table[i]);
			if((i+1)%4==0)
				printf("\n");
		}
		char test[114]={
			0x50,
			0x44,
			0x33,
			0x22,
			0x11,
			0xee,
			0x22,
			0x33,
			0x44,
			0x55,
			0x66,
			0xaa,
			0x00,
			0x64,
			0x00,
			0x01,
			0x00,
			0x01,
			0x02,
			0x03,
			0x04,
			0x05,
			0x06,
			0x07,
			0x08,
			0x09,
			0x0a,
			0x0b,
			0x0c,
			0x0d,
			0x0e,
			0x0f,
			0x10,
			0x11,
			0x012,
0x013,
0x014,
0x015,
0x016,
0x017,
0x018,
0x019,
0x01a,
0x01b,
0x01c,
0x01d,
0x01e,
0x01f,
0x020,
0x021,
0x022,
0x023,
0x024,
0x025,
0x026,
0x027,
0x028,
0x029,
0x02a,
0x02b,
0x02c,
0x02d,
0x02e,
0x02f,
0x030,
0x031,
0x032,
0x033,
0x034,
0x035,
0x036,
0x037,
0x038,
0x039,
0x03a,
0x03b,
0x03c,
0x03d,
0x03e,
0x03f,
0x040,
0x041,
0x042,
0x043,
0x044,
0x045,
0x046,
0x047,
0x048,
0x049,
0x04a,
0x04b,
0x04c,
0x04d,
0x04e,
0x04f,
0x050,
0x051,
0x052,
0x053,
0x054,
0x055,
0x056,
0x057,
0x058,
0x059,
0x05a,
0x05b,
0x05c,
0x05d,
0x05e,
0x05f,
0x060,
0x061};
		printf("\n******%x******\n",GenerateCRC32(test,114));
		printf("\n******%x******\n",crc32_loader(test,114));
}



unsigned   long int  GenerateCRC32(char*   DataBuf,unsigned   long    int len)   
 {   
  unsigned   long   oldcrc32;   
  unsigned   long   crc32;   
  unsigned   long   oldcrc;   
  unsigned     int   charcnt;   
                  char   c,t;   
  oldcrc32=0x00000000;   //初值为0   
  charcnt=0;   
  while(len--)   
  {   
    t=(oldcrc32   >>   24)   &   0xFF;       //要移出的字节的值   
  	oldcrc=crc32_table[t];                   //根据移出的字节的值查表   
    c=DataBuf[charcnt];                     //新移进来的字节值   
    oldcrc32=   (oldcrc32   <<   8)   |   c;       //将新移进来的字节值添在寄存器末字节中   
    oldcrc32=oldcrc32^oldcrc;           //将寄存器与查出的值进行xor运算   
    charcnt++;   
  }   
    crc32=oldcrc32;   
    return   crc32;   
 } 
 
 
 unsigned long int UPDC32(char octet,unsigned long int crc) 
{
     return (crc32_table[((crc)^(octet))&0xff]^((crc)>>8));
}


unsigned long int crc32_loader(char *sp,unsigned long int len) 
{
   	unsigned long int oldcrc32,crc32;
    unsigned long int i;

    oldcrc32=0xFFFFFFFF;
    for(i=0;i<len;i++)
    {
           oldcrc32 = UPDC32( *(sp++),oldcrc32 );
    }
     crc32 = ~oldcrc32; 
     return crc32; 
}
