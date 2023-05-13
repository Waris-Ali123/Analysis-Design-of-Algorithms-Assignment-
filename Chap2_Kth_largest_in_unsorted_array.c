##include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int findKthLargest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, k - 1);
}

int main() {
    int arr[] = {5, 7, 2, 3, 1, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int kthLargest = findKthLargest(arr, size, k);
    printf("The %dth largest element is: %d\n", k, kthLargest);

    return 0;
}
