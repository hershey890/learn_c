#ifndef PSHM_BUF_H
#define PSHM_BUF_H

#include <fcntl.h>		/* For O_* constants */
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

//#define errExit(msg)	do { perror(msg); exit(EXIT_FAILURE); } while(0)
void errExit(const char* msg);

#define BUF_SIZE 1024	/* Maximum size for exchanged string */

struct shmbuf {
	sem_t 	sem1;
	sem_t 	sem2;
	size_t 	cnt;
	char	buf[BUF_SIZE];
};

#ifdef __cplusplus
}
#endif
#endif // PSHM_BUF_H
