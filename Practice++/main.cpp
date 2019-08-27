#include <iostream>
#include "Practice++/Common.h"

// Swaps two values in memory
// Takes locations "a" and "b" as arguments

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Performs insertion sort on "array"
// Takes an array, and it's length as arguments

void insertion_sort(int* array, int n) {
	// Keep track the key and value of the current minimum
	int min_key;
	// Skip tirival last iteration (only 1 element left to sort)
	for (int i = 0; i < n - 1; i++) {
		// Set current index to be minimum
		min_key = i;
		// Loop over remaining elements
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[min_key])
				min_key = j;
		}
		// Swap for the min element
		std::cout << "Swapping index " << i << " with index " << min_key << std::endl;
		print_swap(array, i, min_key, n);
		swap(&array[i], &array[min_key]);
		print_array(array, n);
	}
}

int main() {
	// Create an array of size N
	const int n = 10;
	int array[n];

	srand(0);

	// Fill our array with random numbers
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 100;
	}

	// Sort the array
	insertion_sort(array, n);
}