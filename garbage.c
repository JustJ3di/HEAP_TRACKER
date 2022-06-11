#include "garbage.h"


void *give_me_memory(size_t size)
{
    struct metablock *new = malloc(SIZE_METABLOCK + size);
    new->free = 0;
    new->size = size;
    new->next = general_head;
    general_head = new;
    void *ret = (struct metablock *)(new + 1);
    return ret;
}


static  struct metablock *align(void *me){
    return ((struct metablock *)me - 1);
}

void give_me_info(void *me){

    printf("Hi im a block of size = %d, i am in the address %p and my next point is %p\n", align(me)->size, align(me), align(me)->next);

}



void free_all_memory(){
    
    struct metablock *head = general_head;
    struct metablock *current = head;

    while(head)
    {
        head = current->next;
        free(current);
        current = head;
    }

}