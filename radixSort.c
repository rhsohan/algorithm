#include <stdio.h>

// Function to find the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort function for a specific digit (exp = 1, 10, 100, ...)
void countingSort(int arr[], int n, int exp) {
    int output[n];       // output array to store sorted values
    int count[10] = {0}; // count array for digits 0-9

    // Step 1: Count occurrences of each digit at current place (exp)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Step 2: Change count[i] so that it contains the actual position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Step 4: Copy output[] back to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n); // Find the maximum number to know number of digits

    // Do counting sort for every digit (exp = 1, 10, 100, ...)
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
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

    // Call Radix Sort
    radixSort(arr, n);

    // Print the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
