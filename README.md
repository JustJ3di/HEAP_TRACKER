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
In any case it does not matter , I exploit the sizeof() macro to handle this kind of problem