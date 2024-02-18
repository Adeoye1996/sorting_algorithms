#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partition a subset of an array,
 * according to Lomuto's scheme.
 * @array: The array to partition.
 * @size: The size of the array.
 * @left: The left index of the partition.
 * @right: The right index of the partition.
 *
 * Return: The index of the partition.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++)

	{
		if (array[j] < pivot)

		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[right]);
	print_array(array, size);

	return (i + 1);
}

/**
 * lomuto_sort - Sorts an array using the Lomuto partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 * @left: The left index of the partition.
 * @right: The right index of the partition.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)

	{
		int part_index = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, part_index - 1);
		lomuto_sort(array, size, part_index + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers using quicksort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
