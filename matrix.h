#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define ELEM_T double
#define FORM_T "%lf"

typedef struct _all_matrix
{
    ELEM_T* base_matrix;
    ELEM_T* cur_matrix;
    size_t mat_size;
}ALL_MATRIX;

#define RED           "\x1b[31;2m"
#define YELLOW        "\x1b[33;2m"
#define GREEN         "\x1b[32;2m"
#define BLUE          "\x1b[34;2m"
#define END_OF_COLOUR "\x1b[39;49m"

ALL_MATRIX* create_matrix(size_t size);

void matrix_dump(ALL_MATRIX* mats);

void multiply(int degree, ALL_MATRIX* mats);

ALL_MATRIX* create_matrix(size_t size);

#endif
