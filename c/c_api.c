#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
  Name      : aligned_alloc
  Header    : stdlib.h
  Definition: void* aligned_alloc(size_t alignment, size_t size);
  Function  : 1. Allocate size bytes of uninitialized storage whose alignment is specified by alignment.
              2. The size parameter must be an integral multiple of alignment.
*/
void aligned_alloc_test() {
    int len = 1024;
    void* buf = aligned_alloc(0x1000, len);
    printf("buf == %p \n", buf);
    for (int i = 0; i < len; i++)
        printf(" %02x ", *((char*) buf + i));
    printf("\n");
}

/*
  Name      : fgetc
  Header    : stdio.h
  Definition: int fgetc(FILE* stream);
  Function  : 1. Read a char and return the char
              2. Cursor moves forward
*/
void fgetc_test() {
}


/*
  Name      : rand
  Header    : stdio.h
  Definition: int rand();
  Function  : 1. Create a random int
*/
void rand_test() {
    srand(time(NULL));
    for (int i = 0; i < 10; i ++)
        printf("%d ", rand());
    printf("\n");
}

void main() {
    aligned_alloc_test();
    rand_test();
}

