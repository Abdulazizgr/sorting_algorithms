#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation
 * @array: Array to be sorted
 * @l: Index of the first element
 * @h: Index of the last element
 * @size: Size of the array
 * Return: Position of the last element sorted
 */
int lomuto_partition(int *array, int l, int h, int size)
{
    int pivot = array[h];
    int curr = l, i;

    for (i = l; i <= h - 1; i++)
    {
        if (array[i] < pivot)
        {
            if (array[curr] != array[i])
            {
                swap(&array[curr], &array[i]);
                print_array(array, size);
            }
            curr++;
        }
    }
    if (array[curr] != array[h])
    {
        swap(&array[curr], &array[h]);
        print_array(array, size);
    }
    return (curr);
}


/**
 * qck_sort - Quick sort function
 * @array: Array to be sorted
 * @l: Starting index
 * @h: Ending index
 * @size: Size of the array
 */
void qck_sort(int *array, int l, int h, size_t size)
{
    int pi = 0;

    if (l < h)
    {
        pi = lomuto_partition(array, l, h, size);

        qck_sort(array, l, pi - 1, size);
        qck_sort(array, pi + 1, h, size);
    }
}

/**
 * quick_sort - Sorts an array of integers with quick sort algorithm
 * using the Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    qck_sort(array, 0, size - 1, size);
}

