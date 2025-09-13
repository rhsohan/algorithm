#include <stdio.h>

// Function prototype for partition
int partition(int arr[], int low, int high);

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partition index, arr[pi] is at correct position
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the first element as pivot
    int i = low;
    int j = high;

    while (i < j) {
        // Move i to the right while arr[i] <= pivot
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        // Move j to the left while arr[j] > pivot
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        // Swap arr[i] and arr[j] if i < j
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot at its correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // Return pivot index
}

int main() {
    int n;

    // Read number of elements
    printf("Total number of elements: ");
    scanf("%d", &n);

    int a[n];

    // Read array elements
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call Quick Sort
    quickSort(a, 0, n - 1);

    // Print sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
