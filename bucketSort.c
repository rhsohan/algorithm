#include <stdio.h>

//  Insertion Sort for floats 
void insertionSortFloat(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i]; // Element to insert
        int j = i - 1;

        // Move elements greater than key one step forward
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

//  Bucket Sort for floats (0 <= x < 1) 
void bucketSortFloat(float arr[], int n) {
    float buckets[n][n]; // Create n buckets
    int bucketCount[n];   // Store number of elements in each bucket

    // Initialize bucket counts to 0
    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;

    // Step 1: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (int)(arr[i] * n); // Map element to bucket
        if (bi == n) bi = n - 1;    // Handle edge case
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Step 2: Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0)
            insertionSortFloat(buckets[i], bucketCount[i]);
    }

    // Step 3: Concatenate buckets into original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

//  Insertion Sort for integers 
void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Element to insert
        int j = i - 1;

        // Move elements greater than key one step forward
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

//  Bucket Sort for integers (general case) 
void bucketSortInt(int arr[], int n) {
    int max = arr[0], min = arr[0];

    // Step 1: Find the minimum and maximum elements
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1; // Total range of values
    int buckets[n][n];         // Create n buckets
    int bucketCount[n];        // Count of elements in each bucket

    // Initialize bucket counts to 0
    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = (arr[i] - min) * n / range; // Map element to bucket
        if (bi == n) bi = n - 1;             // Handle edge case
        buckets[bi][bucketCount[bi]++] = arr[i];
    }

    // Step 3: Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0)
            insertionSortInt(buckets[i], bucketCount[i]);
    }

    // Step 4: Concatenate all buckets into original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

//  Main Function 
int main() {
    int choice, n;

    printf("Bucket Sort Program\n");
    printf("1. Sort Integers\n");
    printf("2. Sort Floats (0 <= x < 1)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (choice == 1) {
        int arr[n];

        // Input integers
        printf("Enter %d integers: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Call bucket sort for integers
        bucketSortInt(arr, n);

        // Print sorted array
        printf("After sorting:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } else if (choice == 2) {
        float arr[n];

        // Input floats
        printf("Enter %d floats (0 <= x < 1): ", n);
        for (int i = 0; i < n; i++) {
            scanf("%f", &arr[i]);
        }

        // Call bucket sort for floats
        bucketSortFloat(arr, n);

        // Print sorted array
        printf("After sorting:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2f ", arr[i]);
        }
        printf("\n");

    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
