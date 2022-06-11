#ifndef GC
#define GC

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


#ifndef SIZE_INT
    #define SIZE_INT sizeof(int32_t)
#endif

#ifndef SIZE_FLOAT
    #define SIZE_FLOAT sizeof(float)
#endif

#ifndef SIZE_CHAR 
    #define SIZE_CHAR sizeof(char)
#endif

#ifndef SIZE_METABLOCK
    #define SIZE_METABLOCK sizeof(struct metablock)
#endif 

static void *general_head = NULL;

void *give_me_memory(size_t size);


void give_me_info(void *);

struct metablock *give_me_free_block(size_t size);

size_t get_size_block(void *);

void free_all_memory();

void *free_memory(void *);


#endif