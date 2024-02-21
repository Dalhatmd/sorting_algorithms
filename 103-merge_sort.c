#include "sort.h"
void merge(int *array, int *temp, size_t left_start, size_t left_end, size_t right_end);
void merge_sort_helper(int *array, int *temp, size_t start, size_t end);
void merge_sort(int *array, size_t size);

void merge(int *array, int *temp, size_t left_start, size_t left_end, size_t right_end)
{
	size_t right_start = left_end + 1;
	size_t temp_index = left_start;
	size_t left_index = left_start;
	size_t right_index = right_start;
	size_t i;

	while (left_index <= left_end && right_index <= right_end)
	{
		if (array[left_index] <= array[right_index])
		{
			temp[temp_index++] = array[left_index++];
		}
		else
		{
			temp[temp_index++] = array[right_index++];
		}
	}

	while (left_index <= left_end)
	{
		temp[temp_index++] = array[left_index++];
	}

	while (right_index <= right_end)
	{
		temp[temp_index++] = array[right_index++];
	}

	for (i = left_start; i <= right_end; i++)
	{
		array[i] = temp[i];
	}
}

void merge_sort_helper(int *array, int *temp, size_t start,
 size_t end)
{
	size_t mid;
	size_t i;

	if (start >= end)
		return;
	mid = start + (end - start) / 2;
	merge_sort_helper(array, temp, start, mid);
	merge_sort_helper(array, temp, mid + 1, end);
	merge(array, temp, start, mid, end);

	printf("Merging: ");
	for (i = start; i <= end; i++)
	{
		if (i == end)
			printf("%d", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("\n");
}


void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size <= 2)
		return;
	temp = (int *) malloc(size * sizeof(int));
	if (temp == NULL)
		exit(EXIT_FAILURE);

	merge_sort_helper(array, temp, 0, size - 1);
	free(temp);
}
