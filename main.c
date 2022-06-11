#include "garbage.h"

typedef struct prova{int a;int *v;}P;

int main(int argc, char const *argv[])
{
    int *m = give_me_memory(SIZE_INT);

    *m = 10;
    printf("%d\n", *m);

    char *c = give_me_memory(strlen("ciao")+1);
    strcpy(c,"ciao");

    give_me_info(c);

    float *a = give_me_memory(SIZE_FLOAT);

    give_me_info(a);

    P *n = give_me_memory(sizeof(P));
    n->a =10;
    n->v = give_me_memory(SIZE_INT);

    give_me_info(n);
    give_me_info(n->v);

    free_all_memory();

    return 0;
}
