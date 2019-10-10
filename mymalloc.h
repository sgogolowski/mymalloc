#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4096
#define free(x) myfree(x, __FILE__, __LINE__)
#define malloc(x) mymalloc(x, __FILE__ , __LINE__)

static char mymemory[4096];

void* mymalloc(size_t size, char* file, int line);

void myfree(void* ptr), char* file, int line);



#endif
