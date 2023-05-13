#include <stdio.h>

void merge(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0;  // Index for arr1
    int j = 0;  // Index for arr2
    int k = 0;  // Index for result array

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy the remaining elements of arr1, if any
    while (i < n1) {
        result[k++] = arr1[i++];
    }

    // Copy the remaining elements of arr2, if any
    while (j < n2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[8];
    merge(arr1, n1, arr2, n2, merged);

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
