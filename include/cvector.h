#ifndef CVECTOR_H
#define CVECTOR_H

#include <stddef.h> // for size_t

typedef struct {
    void *data;         // Pointer to the allocated memory
    size_t elem_size;   // Size of each element (in bytes)
    size_t size;        // Number of elements currently stored
    size_t capacity;    // Allocated capacity (in elements)
} CVector;

// Create vector
CVector* vector_create(size_t elem_size);

// Destroy vector
void vector_destroy(CVector *vec);

// Return size and capacity
size_t vector_size(CVector *vec);
size_t vector_capacity(CVector *vec);

// Add element at the end
void vector_push_back(CVector *vec, void *element);

// Remove last element
void vector_pop_back(CVector *vec);

// Get pointer to element at index
void* vector_get(CVector *vec, size_t index);

// Set element at index
void vector_set(CVector *vec, size_t index, void *element);

#endif
