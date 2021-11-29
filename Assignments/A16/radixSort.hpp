// Radix Sort in C++ Programming
// https://www.programiz.com/dsa/radix-sort

#include <iostream>
#include <vector>

namespace RadixSort {
    using namespace std;

    // Function to get the largest element from an array
    int getMax(vector<int>&arr, int n) {// was array[]
        int max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // Using counting sort to sort the elements in the basis of significant places
    void countingSort(vector<int>&arr, int size, int place) {// was array[]
        const int max = 10;
        vector<int>output(size);
        vector<int>count(size);
        //int *output = new int[size];
        //int *count = new int[max];
        

        for (int i = 0; i < max; ++i)
            count[i] = 0;

        // Calculate count of elements
        for (int i = 0; i < size; i++)
            count[(arr[i] / place) % 10]++;

        // Calculate cumulative count
        for (int i = 1; i < max; i++)
            count[i] += count[i - 1];

        // Place the elements in sorted order
        for (int i = size - 1; i >= 0; i--) {
            output[count[(arr[i] / place) % 10] - 1] = arr[i];
            count[(arr[i] / place) % 10]--;
        }

        for (int i = 0; i < size; i++)
            arr[i] = output[i];
    }

    // Main function to implement radix sort
    void radixsort(vector<int>&arr, int size) {// was array[]
        // Get maximum element
        int max = getMax(arr, size);

        // Apply counting sort to sort elements based on place value.
        for (int place = 1; max / place > 0; place *= 10)
            countingSort(arr, size, place);
    }

}  // namespace RadixSort