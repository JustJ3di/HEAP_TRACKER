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

    set_free(vect);

    float *a = get_memory(SIZE_FLOAT);

    give_me_info(a);

    set_free(a);

    give_me_info(a);

    char *ms = get_memory(SIZE_CHAR);



    give_me_info(ms);


    char *saaa = NULL;
    set_free(saaa);

    vect = get_memory(SIZE_INT*1000);

    for (size_t i = 0; i < 1000; i++)
    {
        vect[i] = i*2 + i;
    }
    

    give_me_info(vect);



    set_free(vect);

    

    free_all_memory();

    return 0;
}
