#include "sort.h"
/**
 * selection_sort - sorts an array using the selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int smallest, temp;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (smallest != j)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);
		}
	}
}
