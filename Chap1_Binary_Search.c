#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;  // Target not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int index = binarySearch(arr, 0, n - 1, target);
    
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    
    return 0;
}
