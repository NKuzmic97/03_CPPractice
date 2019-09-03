#include <iostream>
#include <stdlib.h>


static int QuickSortCalls = 0;

// Swaps the contents of two pointers
void swap(int* a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// Create a sub-array for elements "<=" and ">" than the pivot
// Takes an array, left index, and pivot index as arguments

int partition(int *array, int left, int pivot) {
	// Start with a sub-array that is empty
	int low = left - 1;

	// Compare all numbers before the pivot
	int high = pivot - 1;

	// Go over all elements in sub-array
	for (int j = left; j <= high; j++) {
		// Does this element go in the "<=" sub-array?
		if (array[j] <= array[pivot]) {
			// Move over marker of sub-array
			low++;
			// Swap the element into position
			// TODO I dont understand best this line
			swap(&array[low], &array[j]);
		}
	}
	// Move the pivot into the correct position
	swap(&array[low + 1], &array[pivot]);
	// Return the index of the element in the correct place
	return low + 1;
}

// Recursive function that partitions the array into "<=" and ">"
// sub-arrays and calls quicksort on them
void quicksort(int* array, int leftIndex, int pivotIndex) {
	QuickSortCalls++;
	// Recursively called until only a single element left
	if (leftIndex < pivotIndex) {
		// Partition the array into "<=" and ">" sub-arrays
		int newPivot = partition(array, leftIndex, pivotIndex);
		// Sort the sub-arrays via recursive calls
		// Sort the "<=" sub-array
		quicksort(array, leftIndex, newPivot - 1);
		// Sort the ">" sub-array
		quicksort(array, newPivot + 1, pivotIndex);
	}
}


int main() {
	// Numbers of elements to sort
	const int n = 10;

	// Set random number seed
	srand(12345);

	// Create an array of random numbers
	int* array = new int[n];
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 100;
	}
	// Print out the unsorted array
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;


	// Sort the array using quicksort
	quicksort(array, 0, n - 1);

	// Print out the sorted array
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << QuickSortCalls;

	return 0;
}