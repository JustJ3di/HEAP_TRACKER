#ifndef GC
#define GC

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


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

size_t get_size_block(void *);

void free_all_memory();

void set_free(void *);

void *get_memory(size_t size);

void *get_free(size_t);


#endif