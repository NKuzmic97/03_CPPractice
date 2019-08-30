#include <iostream>
#include <vector>
#include "Practice++/Common.h"

// Swaps two values in memory
// Takes locations "a" and "b" as arguments

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Initialize a vector with random numbers
void init_vector(vector<int> &vec, const unsigned n) {
	for (unsigned i = 0; i < n; i++) vec.push_back(rand() % 100);
}

// Helper function for printing a vector
void print_vector(const vector<int> &vec) {
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\t";
	}
	cout << endl;
}


// Helper function to print out sub-list with original vector
void print_range(const vector<int> &vec, unsigned start, unsigned end) {
	for (unsigned i = start; i < end + 1; i++) {
		cout << vec[i] << endl;
	}
	cout << endl;
}

// Helper function to print intermediate results
void print_sub_vectors(const vector<int> &v1,const vector<int> &v2) {
	for (unsigned i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << "\t";
	for (unsigned i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}

// Merges to sorted sub-lists
void merge(vector<int> &vec, unsigned start, unsigned middle, unsigned end) {
	cout << "Call merge for Start = " << start << ", End = " << end << endl;
	// Not sorting in place. Use two temp vectors
	// Initialize left-hand elements
	unsigned elements_left = middle - start + 1;
	vector<int> tmp_left;
	for (unsigned i = 0; i < elements_left; i++) tmp_left.push_back(vec[start + i]);
	// Initialize right-hand elements
	unsigned elements_right = end - middle;
	vector<int> tmp_right;
	for (unsigned i = 0; i < elements_right; i++) tmp_right.push_back(vec[middle + 1 + i]);

	print_sub_vectors(tmp_left, tmp_right);

	// Compare vectors and add elements to the final result
	unsigned i = 0;
	unsigned j = 0;
	int pos = start;
	while ((i < tmp_left.size()) && (j < tmp_right.size())) {
		// Add left-hand element if its smaller
		// Otherwise add right-hand elements
		if (tmp_left[i] <= tmp_right[j]) vec[pos] = tmp_left[i++];
		else vec[pos] = tmp_right[j++];
		pos++;
	}
	// Clean up remaining left-hand elements
	while (i < tmp_left.size()) vec[pos++] = tmp_left[i++];
	// Clean up remaining right-hand elements
	while (j < tmp_right.size()) vec[pos++] = tmp_right[j++];

	print_range(vec, start, end);
}

// Recursive function for sorting the array
void merge_sort(vector<int> &vec, unsigned left, unsigned right) {
	cout << "Merge sort for Left = " << left << " Right = " << right << endl;
	// Merge until we are left with a single element
	if (left < right) {
		// Calculate mid-point of vector
		int mid = (left + right) / 2;

		// Sort the sub-vectors
		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);

		// Merge the two sub-lists
		merge(vec, left, mid, right);
	}
}

int main() {
	// Vector that we will sort
	vector<int> vec;

	// Initialize a vecotr with "n" elements
	unsigned n = 7;
	init_vector(vec, n);

	// Print the vectors before sorting
	cout << "Original vector " << endl;
	print_vector(vec);

	merge_sort(vec, 0, vec.size() - 1);
	// Print out he result
	cout << "Final vector" << endl;
	print_vector(vec);

	return 0;
}