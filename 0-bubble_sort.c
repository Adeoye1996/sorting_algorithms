#include "sort.h"
#include <stdbool.h>

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
 * bubble_sort - Sorts an array of integers in ascending order.
 * using the bubble sort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;

	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (!sorted)

	{
		sorted = true;

		for (i = 0; i < len - 1; i++)

		{
			if (array[i] > array[i + 1])

			{
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				sorted = false;
			}
		}
		len--;
	}
}
