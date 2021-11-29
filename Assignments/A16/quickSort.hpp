// Quick sort in C++
// https://www.programiz.com/dsa/quick-sort

#include <iostream>
#include<vector>

namespace QuickSort {

    using namespace std;

    // function to swap elements
    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // function to rearrange array (find the partition point)
    int partition(vector<int>& arr, int low, int high) {// was array[]
        // select the rightmost element as pivot
        int pivot = arr[high];

        // pointer for greater element
        int i = (low - 1);

        // traverse each element of the array
        // compare them with the pivot
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                // if element smaller than pivot is found
                // swap it with the greater element pointed by i
                i++;

                // swap element at i with element at j
                swap(&arr[i], &arr[j]);
            }
        }

        // swap pivot with the greater element at i
        swap(&arr[i + 1], &arr[high]);

        // return the partition point
        return (i + 1);
    }

    void quickSort(vector<int>& arr, int low, int high) {// was array[]
        if (low < high) {
            // find the pivot element such that
            // elements smaller than pivot are on left of pivot
            // elements greater than pivot are on righ of pivot
            int pi = partition(arr, low, high);

            // recursive call on the left of pivot
            quickSort(arr, low, pi - 1);

            // recursive call on the right of pivot
            quickSort(arr, pi + 1, high);
        }
    }
}  // namespace quick