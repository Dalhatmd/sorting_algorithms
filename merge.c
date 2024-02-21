#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *temp, size_t left_start, size_t left_end, size_t right_end) {
    size_t right_start = left_end + 1;
    size_t temp_index = left_start;
    size_t left_index = left_start;
    size_t right_index = right_start;

    // Merge the two sorted subarrays into the temp array
    while (left_index <= left_end && right_index <= right_end) {
        if (array[left_index] <= array[right_index]) {
            temp[temp_index++] = array[left_index++];
        } else {
            temp[temp_index++] = array[right_index++];
        }
    }

    // Copy the remaining elements from the left subarray
    while (left_index <= left_end) {
        temp[temp_index++] = array[left_index++];
    }

    // Copy the remaining elements from the right subarray
    while (right_index <= right_end) {
        temp[temp_index++] = array[right_index++];
    }

    // Copy the merged elements back to the original array
    for (size_t i = left_start; i <= right_end; i++) {
        array[i] = temp[i];
    }
}

void merge_sort_helper(int *array, int *temp, size_t start, size_t end) {
    if (start >= end) {
        return; // Base case: array size is 0 or 1
    }

    // Divide the array into two halves
    size_t mid = start + (end - start) / 2;
    merge_sort_helper(array, temp, start, mid); // Sort the left half
    merge_sort_helper(array, temp, mid + 1, end); // Sort the right half

    // Merge the sorted halves
    merge(array, temp, start, mid, end);

    // Print the current state of the array after merging
    printf("Merging: ");
    for (size_t i = start; i <= end; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge_sort(int *array, size_t size) {
    if (size <= 1) {
        return; // No need to sort if the array has 0 or 1 element
    }

    // Allocate memory for a temporary array
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Call the helper function to perform merge sort
    merge_sort_helper(array, temp, 0, size - 1);

    // Free dynamically allocated memory
    free(temp);
}

// Example usage:
int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    merge_sort(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

