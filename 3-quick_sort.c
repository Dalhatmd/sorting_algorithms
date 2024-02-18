#include "sort.h"
/**
 * swap - swaps two elements in an array
 * @a: first element to swap
 * @b: second element to swap
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto - lomuto partition function
 *
 * @array: input array
 * @size: size of the array
 * @left: left of the partition
 * @right: right of the partition
 *
 * Return: the pivot
 */
int lomuto(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort_helper - helper function for quicksort
 *
 * @array: input array
 * @size: size of the array
 * @left: left of the pivot
 * @right: right of the pivot
 *
 */
void quick_sort_helper(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto(array, size, left, right);
		quick_sort_helper(array, size, left, part - 1);
		quick_sort_helper(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts an array using the quick sort algorith
 *
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}
