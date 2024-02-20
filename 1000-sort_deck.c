#include "deck.h"
#include <stdlib.h>
#include <string.h>

int compare_cards(const void *a, const void *b);

/**
 * sort_deck - Sorts a deck of cards in,
 * ascending order by value and kind.
 * @deck: Pointer to the head of a,
 * doubly linked list of cards.
 */
void sort_deck(deck_node_t **deck)
{
	/* Create an array to store pointers to each card node */
	deck_node_t *node_array[52];
	deck_node_t *current = *deck;

	int i = 0;

	/* Populate the array with pointers to each node */
	while (current != NULL)
	{
		node_array[i++] = current;
		current = current->next;
	}

	/* Sort the array using qsort */
	qsort(node_array, 52, sizeof(deck_node_t *), compare_cards);

	/* Rebuild the linked list using the sorted array */
	for (i = 0; i < 51; i++)

	{
		node_array[i]->next = node_array[i + 1];
		node_array[i + 1]->prev = node_array[i];
	}

	/*  Update the head and tail pointers of the linked list */
	*deck = node_array[0];
	node_array[0]->prev = NULL;
	node_array[51]->next = NULL;
}

/**
 * compare_cards - Compare two cards.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 *
 * Return: Negative value if a < b,
 * 0 if a == b, positive value if a > b.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

    /* Compare kinds first */
	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	/*  If kinds are the same, compare values */
	return (strcmp(node_a->card->value, node_b->card->value));
}
