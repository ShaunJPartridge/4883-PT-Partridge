// Counting sort in C++ programming
// https://www.programiz.com/dsa/counting-sort
#include <iostream>
#include <vector>

namespace CountSort {

  using namespace std;

  void countSort(vector<int>&arr,int size,int m){
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int max = *max_element(arr.begin(), arr.end());
    //int min = *min_element(arr.begin(), arr.end());
    vector<int>count(max+1), output(arr.size()+1);
  

    // Initialize count array with all zeros.
    //for (int i = 0; i <= count.size(); ++i) {
      //count[i] = 0;
      //output.push_back(0);
    //}

    // Store the count of each element
    for (int i = 0; i < arr.size(); i++) {
      count[arr[i]]++;
    }
  
    // Store the cummulative count of each array
    for (int i = 1; i < count.size(); i++) {
      count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = arr.size() - 1; i >= 0; i--) {
      output[count[arr[i]] - 1] = arr[i];
      count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = output[i];
      //cout << arr[i] << " ";
    }
  }
}  // namespace Count