#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void qck_sort(int *array, int l, int h, size_t size);
int lomuto_partition(int *array, int l, int h, size_t size);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *nd, listint_t **list);

#endif /* SORT_H */
