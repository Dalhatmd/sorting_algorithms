#include "sort.h"
/**
 * shell_sort - sorts an array using the shell sort algorithm (Knuth sequence)
 *
 * @array: input array
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;
	int temp;

	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
