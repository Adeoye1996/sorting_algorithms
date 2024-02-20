#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Ensures max heap property is maintained.
 * @array: Array to be heapified.
 * @size: Size of the array.
 * @root: Index of the root node.
 */
void max_heapify(int *array, size_t size, size_t root)
{

	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)

	{
		swap_ints(&array[root], &array[largest]);
		max_heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{

	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		max_heapify(array, size, i);

	/* Extract elements from heap one by one*/
	for (i = size - 1; i > 0; i--)

	{
		swap_ints(&array[0], &array[i]); /* Move current root to end */
		max_heapify(array, i, 0); /* Call max heapify on reduced heap*/
	}
}
