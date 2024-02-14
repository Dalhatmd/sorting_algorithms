#include "sort.h"
/**
 * bubble_sort - a function that sorts an array using the bubble sort algorithm
 *
 * @array: input array
 * @size: size of array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t tmp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}

