#include "pshm_buf.h"

void errExit(const char* msg) {
	do {
		perror(msg);
		exit(EXIT_FAILURE);
	} while(0);
}
