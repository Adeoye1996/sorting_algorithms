#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers,
 * in ascending order.
 * using the insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)

	{
		prev_node = current->prev;
		next_node = current->next;

		while (prev_node != NULL && prev_node->n > current->n)

		{
			/* Swap current node with its previous node */
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;
			current->prev = prev_node->prev;
			prev_node->next = next_node;

			if (next_node != NULL)
				next_node->prev = prev_node;
			current->next = prev_node;
			prev_node->prev = current;

			print_list(*list);
			prev_node = current->prev;
		}

		current = next_node;
	}
}
