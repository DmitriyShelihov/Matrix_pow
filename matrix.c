#include "matrix.h"

void _multiply(ALL_MATRIX* mats, ELEM_T* mul);

ALL_MATRIX* create_matrix(size_t size)
{
    ALL_MATRIX* mats = (ALL_MATRIX*)malloc(sizeof(ALL_MATRIX));

    mats->base_matrix = (ELEM_T*)calloc(size * size, sizeof(ELEM_T));

    ELEM_T cur_number = -1;

    for (int i = 0; i < size * size; i++)
    {
        scanf(FORM_T, &cur_number);

        mats->base_matrix[i] = cur_number;
    }

    mats->mat_size = size;

    mats->cur_matrix = mats->base_matrix;

    return mats;
}

void _multiply(ALL_MATRIX* mats, ELEM_T* mul)
{
    size_t size = mats->mat_size;

    ELEM_T* res = (ELEM_T*)calloc(size * size, sizeof(ELEM_T));

    int sum = -1;

    int n_string = -1;
    int n_column = -1;

    for (int n_summand = 0; n_summand < size * size; n_summand++)
    {
        sum = 0;

        n_string = n_summand / size;
        n_column = n_summand - n_string * size;

        for (int elem = 0; elem < size; elem++)
        {
            sum += mats->cur_matrix[n_string * size + elem] * mul[size * elem + n_column];
        }

        res[n_summand] = sum;
    }

    mats->cur_matrix = res;
}

void multiply(int degree, ALL_MATRIX* mats)
{

    while (degree > 1)
    {
        if (degree % 2 == 0)
        {
            _multiply(mats, mats->cur_matrix);
            degree /= 2;
        }
        else
        {
            _multiply(mats, mats->base_matrix);
            degree -= 1;
        }

    }
}

void matrix_dump(ALL_MATRIX* mats)
{
    size_t size = mats->mat_size;

    for (int i = 0; i < size * size; i++)
    {
        printf(FORM_T "     ", mats->cur_matrix[i]);

        if (i % size == size - 1)
            printf("\n");
    }
}

int main()
{
    printf(BLUE "Input size of matrix: " END_OF_COLOUR);
    size_t size = -1;
    scanf("%d", &size);

    ALL_MATRIX* mats = create_matrix(size);

    int degree = -1;
    printf(BLUE "Input degree of matrix: " END_OF_COLOUR);

    scanf("%d", &degree);

    multiply(degree, mats);

    matrix_dump(mats);

    return 0;
}
