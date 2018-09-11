#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE * pFile;
    char buffer[] = { 'x' , 'y' , 'z' };
    pFile = fopen("/tmp/xlhu_test.dump", "a+");
    fwrite(buffer , sizeof(char), sizeof(buffer), pFile);
    fclose(pFile);
}
