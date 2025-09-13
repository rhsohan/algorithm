#include <stdio.h>

// Function to sort array using Counting Sort
void countingSort(int arr[], int n) {
    int i;

    // Step 1: Find the maximum element in the array
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array (to store frequency) and output array
    int count[max + 1];
    int output[n];

    // Step 3: Initialize count array with 0
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Step 4: Count frequency of each element
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 5: Update count[i] to store the actual position of elements in output[]
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 6: Build the output array (process elements from end for stable sort)
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; // Decrease count for next occurrence
    }

    // Step 7: Copy sorted elements back to original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call Counting Sort
    countingSort(arr, n);

    // Print sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
