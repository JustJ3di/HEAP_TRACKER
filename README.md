# HEAP_TRACKER
I want to create an allocator that can keep track of allocated memory, which can eventually be used as a gc by a user. 

## the memory info block

```c
struct metablock{

    int free;
    size_t size;
    struct metablock *next;

}; 
```
the block contains all the info that i need.
Free is a bool that indicates if the block is free or not.
Size is the size of memory of this block.
I handle it as a simple linked list so i need to a pointer at next.
For my compiler this structure has the size of 24 bytes, maybe in yours it will be different depends on the structure padding or the processor you use.
In any case it does not matter , I exploit the sizeof() macro to handle this kind of problem.

```c
#define SIZE_BLOCK sizeof(struct metablock)
```

Whenever there is a need for a new allocation, it is done with the syscall malloc from the standard library.
I initially thought of using sbrk, however some compilers like clang do not like it very much so I preferred to avoid it.

```c
struct metablock *new = malloc(SIZE_METABLOCK + size);
```

To the user I return only the next pointer to the structure, which is the one actually requested by him.
```c
void *ret = (struct metablock *)(new + 1);
return ret;
```

### Features
Anywhere in your programs you can call the ```get_size()``` function on a preallocated pointer with get_memory(size) to find out the size of the memory used.
To this size of course must be added the size of the struct previously described.
You can also print all the info about the block with the function ```give_me_info(void *)```
At the and of you programs call the funcion ``` free_all_memory()```, so in this way
all the memory that you use are free like garbage collecion.

### example
Can be good to write code allocating memory this way, since each allocation is part of a unique linked list that can then be memory freed at the end of your programs.
```c
#include "garbage.h"
#include <string.h>

typedef struct proof{int a;int *v;}P;

int main()
{   

    int *m = get_memory(SIZE_INT);


    *m = 10;
    printf("%d\n", *m);

    char *c = get_memory(strlen("ciao")+1);
    strcpy(c,"ciao");

    give_me_info(c);

    P *n = get_memory(sizeof(P));
    n->a =10;
    n->v = get_memory(SIZE_INT);

    give_me_info(n);
    give_me_info(n->v);

    int *vect = get_memory(SIZE_INT*1000);

    for (size_t i = 0; i < 1000; i++)
    {
        vect[i] = i+3;
    }
    
    give_me_info(vect);

    float *a = get_memory(SIZE_FLOAT);

    give_me_info(a);

    set_free(a);

    give_me_info(a);

    char *ms = get_memory(SIZE_CHAR);

    give_me_info(ms);

    char *saaa = NULL;
    set_free(saaa);

    free_all_memory();

    return 0;
}
```