#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nd;

	if (list == NULL || (*list)->next == NULL)
		return;
	nd = (*list)->next;
	while (nd)
	{
		while ((nd->prev) && (nd->prev->n > nd->n))
		{
			nd = swap_node(nd, list);
			print_list(*list);
		}
		nd = nd->next;
	}
}

/**
 * swap_node - swap a node for its previous one
 * @nd: node
 * @list: node list
 * Return: return a pointer to a node which was entered
 */
listint_t *swap_node(listint_t *nd, listint_t **list)
{
	listint_t *prv = nd->prev, *cur = nd;

	prv->next = cur->next;
	if (cur->next)
		cur->next->prev = prv;
	cur->next = prv;
	cur->prev = prv->prev;
	prv->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return cur;
}
