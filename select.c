#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *array, size_t size) {
    if (array == NULL || size <= 1)
        return;

    for (size_t i = 0; i < size - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; j++) {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i) {
            swap(&array[i], &array[min_index]);
            printf("Swapped %d and %d\n", array[i], array[min_index]);
        }
        // Print array after each iteration
        printf("Array after iteration %zu: ", i + 1);
        for (size_t k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}

int main() {
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    selection_sort(array, n);

    printf("\nSorted array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

