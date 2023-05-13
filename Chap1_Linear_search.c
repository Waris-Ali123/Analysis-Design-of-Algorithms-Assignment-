#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;  // Target found, return the index
    }
    
    return -1;  // Target not found
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;
    
    int index = linearSearch(arr, n, target);
    
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    
    return 0;
}
