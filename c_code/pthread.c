/*
  Date: 2018-08-14
  Version: 1.0

  # How to compile
    gcc -o pthread pthread.c -lpthread

  # Some definitons
    typedef unsigned long int pthread_t;

    int pthread_create(pthread_t *restrict tidp,
                       const pthread_attr_t *restrict attr,
                       void *(start_rtn)(void),
                       void *restrict arg);
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void lthread1(void) {
    int i;
    for(i = 0; i < 10; i++) {
        printf("This is a pthread1 %d.\n", i);
        sleep(1);
    }
}

void lthread2(void) {
    int i;
    for(i = 0; i < 10; i++) {
        printf("This is a pthread2 %d.\n", i);
        sleep(1);
    }
}

void lthread3(void* arg) {
    int* num;
    num = (int *)arg;

    printf("This is a pthread3 %d.\n", *num);
}


int main(void) {
	pthread_t id1, id2, id3;
	if (pthread_create(&id1, NULL, (void*) lthread1, NULL) != 0) {
		printf ("Create pthread1 error!\n");
		exit (1);
	}

	if (pthread_create(&id2, NULL, (void*) lthread2, NULL) != 0) {
		printf ("Create pthread2 error!\n");
		exit (1);
	}

    int val = 5;
	if (pthread_create(&id3, NULL, (void*) lthread3, (void*)(&val)) != 0) {
		printf ("Create pthread2 error!\n");
		exit (1);
	}

	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);

	return (0);
}

