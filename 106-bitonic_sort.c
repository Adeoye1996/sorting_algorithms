/*
 * File: 106-bitonic_sort.c
 * Auth: [Your Name]
 */

#include "sort.h"
#include <stddef.h>  /*Include for size_t */

#define UP 1
#define DOWN 0

void swap_values(int *a, int *b);
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
		char direction);
void generate_bitonic(int *array, size_t size, size_t start, size_t seq,
		char direction);
void bitonic_sort(int *array, size_t size);

/**
 * swap_values - Swap two integer values.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * merge_bitonic - Sort a bitonic sequence in the array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the bitonic sequence.
 * @seq: The size of the bitonic sequence.
 * @direction: The direction to sort in.
 */
void merge_bitonic(int *array, size_t size, size_t start, size_t seq,
		char direction)
{
	size_t i, jump = seq / 2;

	if (seq > 1)

	{
		for (i = start; i < start + jump; i++)

		{
			if ((direction == UP && array[i] > array[i + jump]) ||
				(direction == DOWN && array[i] < array[i + jump]))
			{
				swap_values(&array[i], &array[i + jump]);
			}
		}
		merge_bitonic(array, size, start, jump, direction);
		merge_bitonic(array, size, start + jump, jump, direction);
	}
}

/**
 * generate_bitonic - Generate a bitonic sequence in the array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the bitonic sequence.
 * @seq: The size of the bitonic sequence.
 * @direction: The direction to sort the bitonic sequence.
 */
void generate_bitonic(int *array, size_t size, size_t start, size_t seq,
		char direction)
{
	size_t cut = seq / 2;

	if (seq > 1)

	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size,
				(direction == UP) ? "UP" : "DOWN");
		print_array(array + start, seq);

		generate_bitonic(array, size, start, cut, UP);
		generate_bitonic(array, size, start + cut, cut, DOWN);
		merge_bitonic(array, size, start, seq, direction);

		printf("Result [%lu/%lu] (%s):\n", seq, size,
				(direction == UP) ? "UP" : "DOWN");
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in,
 * ascending order using bitonic sort.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	generate_bitonic(array, size, 0, size, UP);
}
