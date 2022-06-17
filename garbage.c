#include "garbage.h"

struct metablock{

    int free;
    size_t size;
    struct metablock *next;

};

static void *general_head = NULL;

void *give_me_memory(size_t size)
{
    struct metablock *new = malloc(SIZE_METABLOCK + size);
    assert(new != NULL);
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

    printf("Hi im a block of size = %ld, \
    i am in the address %p and my next point is %p .\
    is it free ? (%d) \n", align(me)->size, align(me), align(me)->next, align(me)->free);

}

size_t get_size_block(void *me){

    return align(me)->size;

}

static struct metablock *get_free(size_t size){

    struct metablock *head = general_head;

    while (head)
    {
        if (head->size == size && head->free == 1)
        {
            break;
        }
        head = head->next;
    }
    if (head)
    {   
        
        return head;
    }
    else
    {
        return NULL;
    }

    return NULL;
    
}

void set_free(void *me){

    if(me)
    {
        struct metablock *to_free = align(me);
        to_free->free = 1;
    }    
    else{
        printf("Give me a pointer that is alredy allocated with get_memory(size) !\n");
        return;
    }

}

void *get_memory(size_t size){

    struct metablock *new = get_free(size);

    if(new)
    {
        new->free = 0;
        return ((void *)((struct metablock *)(new+1)));
    }
    else
    {
        return give_me_memory(size);
    }
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