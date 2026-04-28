#include <iostream>
#include <vector>
#include <utility> // For std::swap

// Utility function to print a vector
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// This function implements the Hoare partition scheme. It partitions the
// array and returns the split point.
int partition(std::vector<int>& arr, int low, int high) {
    // Choose the first element as the pivot (key to this Hoare implementation)
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Find an element on the left side that should be on the right
        do {
            i++;
        } while (arr[i] < pivot);

        // Find an element on the right side that should be on the left
        do {
            j--;
        } while (arr[j] > pivot);

        // If the pointers have crossed, the partition is done
        if (i >= j) {
            return j;
        }

        // Swap the elements to place them on the correct side
        std::swap(arr[i], arr[j]);
    }
}

// The main recursive function that implements Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    // Base case: if the array has 1 or 0 elements, it's already sorted
    if (low < high) {
        // pi is the split point from the Hoare partition
        int pi = partition(arr, low, high);

        // Recursively sort the two partitions
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

// Main driver function
int main() {
    std::vector<int> data = {6, 5, 3, 1, 8, 7, 2, 4};
    std::cout << "Original array: ";
    printVector(data);

    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printVector(data);

    return 0;
}