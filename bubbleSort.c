#include <stdio.h>

// Function to sort an array using Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;

    // Loop for each pass
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // No swaps yet for this pass

        // Compare each pair of adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the left element is bigger
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1; // Mark that a swap happened
            }
        }

        // If no swaps happened, the array is already sorted
        if (swapped == 0)
            break;
    }
}

int main() {
    int n;

    // Ask user how many numbers
    printf("Total number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Ask user to enter the numbers
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the sorting function
    bubbleSort(arr, n);

    // Print the sorted numbers
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
