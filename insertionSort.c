#include <stdio.h>

// Function to sort an array using Insertion Sort
void insertionSort(int arr[], int n) {
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int temp = arr[i];  // Store current element
        int j = i - 1;

        // Move elements that are bigger than temp one step to the right
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place temp in its correct position
        arr[j + 1] = temp;
    }
}

int main() {
    int n;

    // Ask user for the number of elements
    printf("Total number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements from user
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the sorting function
    insertionSort(arr, n);

    // Print the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
