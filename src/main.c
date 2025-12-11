#include <stdio.h>
#include "cvector.h"

int main() {
    CVector *v = vector_create(sizeof(int));

    printf("Enter integers (type -1 to stop):\n");

    while (1) {
        int x;
        scanf("%d", &x);
        if (x == -1) break;
        vector_push_back(v, &x);
    }

    printf("\nStored values:\n");
    for (size_t i = 0; i < vector_size(v); i++) {
        int *value = vector_get(v, i);
        printf("%d ", *value);
    }

    printf("\n\nFinal size = %zu\n", vector_size(v));
    printf("Final capacity = %zu\n", vector_capacity(v));

    vector_destroy(v);
    return 0;
}
