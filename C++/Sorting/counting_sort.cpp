// Counting Sort in C++
// Contributed for Hacktoberfest 2025

#include <iostream>
using namespace std;

// Function to perform counting sort
void countSort(int array[], int size) {
  int output[10]; // Output array to store sorted elements
  int count[10];  // Count array to store frequency
  int max = array[0];

  // Find the maximum element in the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with 0
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store cumulative count
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Place elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy sorted elements back to original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Main function
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);

  cout << "Original Array: ";
  printArray(array, n);

  countSort(array, n);

  cout << "Sorted Array: ";
  printArray(array, n);

  return 0;
}
