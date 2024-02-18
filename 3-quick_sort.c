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
 * lomuto_partition - Partitions the array using the Lomuto scheme.
 * @array: The array to be partitioned.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Index of the pivot after partitioning.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)

	{
		if (array[j] < pivot)

		{
			i++;

			if (i != j)

			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])

	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Sorts the array using the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)

	{
		int pi = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, pi - 1);
		lomuto_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in,
 * ascending order using quicksort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
