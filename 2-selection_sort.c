#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order,
 * using the selection sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts the given array in ascending,
 * order using the selection sort algorithm.
 * It prints the array after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	size_t i, j;

	for (i = 0; i < size - 1; i++)

	{
		size_t min_index = i;

		for (j = i + 1; j < size; j++)

		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)

		{
			int tmp = array[i];

			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
