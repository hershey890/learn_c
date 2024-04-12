#include <stdio.h>

#if __STDC_VERSION__ < 201112L || __STD_NO_ATOMICS__ == 1
#define HAS_ATOMICS 0
#else
printf("Program lacks atomics, exit\n");
#define HAS_ATOMICS 1
#endif


int main() {
	#ifdef HAS_ATOMICS
		printf("has atomics\n");
	#else
		printf("does not have atomics\n");
	#endif
}
