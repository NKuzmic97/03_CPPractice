#pragma once

#include <iostream>
#include <cstddef>
#include <assert.h>

// Simple node of the list
// Contains data and a pointer to the next node

struct Node {
	int data;
	Node* next;

	// Constructor
	Node(int d) {
		data = d;
		next = nullptr;
	}
};

class LinkedList {
private:
	// Pointer to list head
	Node* head;
public:
	// Constructor initalizing nullptrs
	LinkedList() {
		head = nullptr;
	}
	// Add node with data 'd' at head position
	void insert_head(int data);
	// Add node with data 'd' at position in the list 'p'
	void insert_position(int data, int position);
	// Add node with data 'd' at tail position
	void insert_tail(int data);
	// Print out the list
	void print_list();
	// Delete head node
	void delete_head();
	// Delete node at position 'p'
	void delete_position(int position);
	// Delete node at tail position
	void delete_tail();
};