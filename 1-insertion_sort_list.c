#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers,
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly linked list of integers.
 *
 * Description: This function sorts the doubly linked list,
 * in ascending order.
 * It swaps the nodes themselves to sort the list.
 * It prints the list after each swap operation.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)

	{
		temp = current->next;
		insertion = current->prev;

		while (insertion != NULL && current->n < insertion->n)

		{
			if (insertion->prev != NULL)
				insertion->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = insertion;
			insertion->next = current->next;
			current->prev = insertion->prev;
			current->next = insertion;
			insertion->prev = current;

			print_list((const listint_t *)*list);
		}
	}
}
