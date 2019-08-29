#include <iostream>
#include "Practice++/Common.h"

// Swaps two values in memory
// Takes locations "a" and "b" as arguments

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Performs bubble sort
// Takes an array and its length as arguments
void bubble_sort(int *array, int n) {
	// Skips tirival last iteration
	for (int i = 0; i < n - 1; i++) {
		// Propagate largest remaining element to the top
		// Remove "i" sorted elements each iteration
		for (int j = 0; j < n - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				std::cout << "Swapping index" << j << " and " << j + 1 << std::endl;
				print_swap(array, j, j + 1, n);
				swap(&array[j], &array[j + 1]);
				print_array(array, n);
			}
		}
	}
}

int main() {
	// Allocate an array of n size
	const int n = 8;
	int array[n];

	for (int i = 0; i < n; i++) array[i] = rand() % 100;
	bubble_sort(array, n);
}