#include "sort.h"
/**
 * counting_sort - sorts an array using the counting sort algorithm
 *
 * @array: input array
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	size_t i, j, max;

	if (size <= 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
		{
			max = array[i];
		}
	}
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	print_array(count, max + 1);
	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[j++] = i;
			count[i]--;
		}
	}
	free(count);
}
