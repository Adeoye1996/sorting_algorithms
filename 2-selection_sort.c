#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order.
 * using the selection sort algorithm
 *@size:  An array of integers to sort.
 * @array: The size of array.
 *
 * Description: This function sorts the given array in ascending,
 * order using the selection sort algorithm. It prints the array
 * after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;
		for (index = i + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
