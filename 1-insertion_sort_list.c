#include "sort.h"

/**
 * swap_nodes - Swaps two nodes.
 * @list: Double pointer to the list to be sorted.
 * @node1: The first node.
 * @node2: The second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (!list || !*list || !node1 || !node2)
		return;
	if (node1 == node2)
		return;
	if (node1->next == node2)
	{
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;

		if (node1->next)
			node1->next->prev = node1;

		if (node2->prev)
			node2->prev->next = node2;
		else
			*list = node2;
		return;
	}
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->prev)
		node2->prev->next = node1;
	else
		*list = node1;

	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;
	node2->next->prev = node2;
	node1->next->prev = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Double pointer to the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	key = curr->next;
	while (key)
	{
		while (curr && curr->n > key->n)
		{
			swap_nodes(list, curr, key);
			print_list(*list);
			curr = key->prev;
		}
		curr = key;
		key = key->next;
	}
}
