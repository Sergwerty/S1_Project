#include "cvector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

CVector* vector_create(size_t elem_size) {
    CVector *vec = malloc(sizeof(CVector));
    vec->elem_size = elem_size;
    vec->size = 0;
    vec->capacity = 2; // start small
    vec->data = malloc(vec->capacity * elem_size);
    return vec;
}

void vector_destroy(CVector *vec) {
    free(vec->data);
    free(vec);
}

size_t vector_size(CVector *vec) {
    return vec->size;
}

size_t vector_capacity(CVector *vec) {
    return vec->capacity;
}

// Internal: grow capacity
static void vector_grow(CVector *vec) {
    vec->capacity *= 2;
    vec->data = realloc(vec->data, vec->capacity * vec->elem_size);
}

void vector_push_back(CVector *vec, void *element) {
    if (vec->size == vec->capacity) {
        vector_grow(vec);
    }
    void *target = (char*)vec->data + vec->size * vec->elem_size;
    memcpy(target, element, vec->elem_size);
    vec->size++;
}

void vector_pop_back(CVector *vec) {
    if (vec->size > 0) {
        vec->size--;
    }
}

void* vector_get(CVector *vec, size_t index) {
    if (index >= vec->size) return NULL;
    return (char*)vec->data + index * vec->elem_size;
}

void vector_set(CVector *vec, size_t index, void *element) {
    if (index >= vec->size) return;
    memcpy((char*)vec->data + index * vec->elem_size, element, vec->elem_size);
}
