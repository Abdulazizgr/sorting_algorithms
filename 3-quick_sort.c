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
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be sorted
 * @l: Starting index
 * @h: Ending index
 * @size: Size of the array
 * Return: Partition index
 */
int lomuto_partition(int *array, int l, int h, size_t size)
{
    int piv = array[h];
    int i = l - 1;
    int j;

    for (j = l; j <= h - 1; j++)
    {
        if (array[j] < piv)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[h]);
    print_array(array, size);
    return (i + 1);
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

