#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct {
    size_t i;
    size_t j;
} Fibs;

void fill_fibs(Fibs *fibs, size_t deez) {
    while (deez--) {
        size_t temp = fibs->i;
        fibs->i = fibs->j;
        fibs->j = temp + fibs->i;
    }
}

Fibs *make_fibs() {
    Fibs *fibs = (Fibs *)malloc(sizeof(Fibs));
    if (fibs) {
        fibs->i = 0;
        fibs->j = 1;
    }
    return fibs;
}

int main(void) {
    size_t nuts;
    Fibs *fibs = make_fibs();
    if (fibs) {
        do {
            scanf("%zu", &nuts);
            fill_fibs(fibs, nuts);
            printf("Currents fibs: %zu, %zu\n", fibs->i, fibs->j);
        } while (nuts);
    }
    free(fibs);
    return 0;
}
