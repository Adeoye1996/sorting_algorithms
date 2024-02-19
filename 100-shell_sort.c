#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
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
 * shell_sort - Sorts an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the shell sort algorithm,
 * using the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	/* Dermine the initial gap using the Knuth sequence */
	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)

	{
/* Shift elements to the right until the correct position is found */

		for (i = gap; i < size; i++)

		{
			j = i;

			while (j >= gap && array[j - gap] > array[j])

			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}

		/* Output the current state of array */
		print_array(array, size
				);
	}
}
