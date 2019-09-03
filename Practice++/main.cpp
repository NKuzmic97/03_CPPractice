#include <iostream>
#include <vector>
#include "Practice++/Common.h"
#include <assert.h>

struct Node {
	// Pointers to left and right nodes
	Node* left;
	Node* right;

	// Data
	int m_data;

	// Constructor
	Node(int data) {
		m_data = data;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
public:
	// Root node of the tree
	Node* root;
	
	// Simple constructor sets the root to NULL
	BinarySearchTree() { root = nullptr; }

	// Simple method for inserting a node
	Node* insert_node(Node* node, int data);

	// Search for a node with m_data "data"
	Node* search(int data);
};

// Resursively traverse the tree until the node is nullptr
// (insertion point)
Node* BinarySearchTree::insert_node(Node* node, int data) {
	// Case that we are inserting the node here
	if (node == nullptr) {
		std::cout << "X" << std::endl;
		return new Node(data);
	}
	else if (data < node->m_data) {
		std::cout << "L";
		node->left = insert_node(node->left, data);
	}
	else if (data > node->m_data) {
		std::cout << "R";
		node->right = insert_node(node->right, data);
	}
	// In case we have duplicate entries (illegal)
	else {
		assert(false);
	}
	// If this node was not nullptr, return it unchanged
	return node;
}

Node* BinarySearchTree::search(int data) {
	// Temporary node to use for traversal (init. to root)
	Node* temp = root;

	// Keep traversing the tree until the node is found (maybe not)
	while (temp != nullptr) {
		// Return the node we are looking for
		if (data == temp->m_data) {
			std::cout << "X" << std::endl;
			return temp;
		}
		// Go down to the left path
		else if(data < temp->m_data){
			std::cout << "L" << std::endl;
			temp = temp->left;
		}
		// Go down to the right path
		else {
			std::cout << "R";
			temp = temp->right;

		}
	}
	// We didn't find the node..
	return nullptr;
}


int main() {
	// Create a new binary search tree
	BinarySearchTree bst;

	// Set the random seed 
	srand(12345);

	// Insert 10 random nodes
	int data;
	vector<int> data_vec;
	for (int i = 0; i < 10; i++) {
		// Random number between 0-999
		data = rand() % 1000;
		data_vec.push_back(data);
		std::cout << "Inserting node with data " << data << std::endl;
		
		// Insert the node (save the root if it's the first insert)
		bst.root = bst.insert_node(bst.root, data);
	}
	std::cout << std::endl;

	// Search for each of the inserted nodes
	for (int i : data_vec) {
		std::cout << "Searching for node with data " << i << std::endl;
		bst.search(i);
	}
	return 0;
}