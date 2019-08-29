#include <iostream>
#include "Practice++/Common.h"

// Swaps two values in memory
// Takes locations "a" and "b" as arguments

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Performs insertion sort
// Takes an array and its length as arguments
void insertion_sort(int* array, int n) {
	// Place each element at the end of the sorted sub-list
	// into the list (first element is implicitly sorted)
	int temp;
	for (int i = 1; i < n; i++) {
		cout << "Inserting index " << i << endl;
		print_swap(array, i, i, n);
		// Save the ith element because shifiting overwrites it
		temp = array[i];

		// Amount to shift elements by
		int j = i - 1;
		// Shift over elements until we find insertion point
		while ((j >= 0) && (array[j] > temp)) {
			array[j + 1] = array[j];
			j--;
		}

		// .. and insert the value at that spot
		cout << "Inserting at position " << j + 1 << endl << endl;
		array[j + 1] = temp;
		print_array(array, n);
	}
}

int main() {
	// Allocate an array of n size
	const int n = 8;
	int array[n];

	for (int i = 0; i < n; i++) array[i] = rand() % 100;
	insertion_sort(array, n);

}