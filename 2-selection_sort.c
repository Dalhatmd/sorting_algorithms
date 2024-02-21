#include "sort.h"
void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
/**
 * swap - swaps two integers
 *
 * @a: first argument
 * @b: second argument
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array using the selection sort algorithm
 *
 * @array: input array
 * @size: input size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
