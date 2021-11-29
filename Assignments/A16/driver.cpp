#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "countSort.hpp"
#include "heapSort.hpp"
#include "quickSort.hpp"
#include "radixSort.hpp"

using namespace std;
using namespace std::chrono;

struct sortCompare {
    //int*             data;  // array of numbers
    vector<int> data;
    vector<int> copy;
    //int*             copy;  // copy of array to actually sort
    int              n=0;     // size or number of values to sort
    int              m=0;     // max number
    vector< string > sortNames;

    sortCompare(string filename) {
        m = 1073741824;
        loadData(filename);
        sortNames = {"countSort", "heapSort", "quickSort", "radixSort"};
    }

    // function to print the array
    void printArray() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void copyArray() {
        //copy = new int[n];
        copy.resize(n);

        for (int i = 0; i < n; i++) {
            copy[i] = data[i];
        }
    }

    void loadData(string fileName) {
        ifstream fin;
        fin.open(fileName);
        fin >> n;
        //data = new int[n];
        data.resize(n);
        for (int i = 0; i < n; i++) {
            fin >> data[i];
        }
    }

    void writeArray(vector<int> data, string name) {
        ofstream fout;
        fout.open(name);
        for (int i = 0; i < n; i++) {
            fout << data[i] << "\n";
        }
        fout.close();
    }

    void callSortMethod(string sortName) {
        cout << "Making copy of data: \n";
        copyArray();

        cout << "Performing " << sortName << "..." << endl;

        auto start = high_resolution_clock::now();

        if (sortName == "countSort") {
            CountSort::countSort(copy, n,m);
        } else if (sortName == "heapSort") {
            HeapSort::heapSort(copy, n);
        } else if (sortName == "quickSort") {
            QuickSort::quickSort(copy, 0, n - 1);
        } else if (sortName == "radixSort") {
            RadixSort::radixsort(copy, n);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast< microseconds >(stop - start);

        cout << "Duration: " << duration.count() << " microSeconds."<<endl;
        cout << "Writing " << sortName << ".out" << endl;
        
        writeArray(copy, sortName + ".out");

        //delete[] copy;
        copy.clear();
    }
};

// Driver code
int main() {
  // ints up to 10,000 work fine with all sorting algorithms
  // ints up to 1,000,000 struggle with quicksort and radixSort
  sortCompare SC("rnums5.dat");

  for (int i = 0; i < SC.sortNames.size(); i++) {
      SC.callSortMethod(SC.sortNames[i]);
  }
  
  return 0;
}