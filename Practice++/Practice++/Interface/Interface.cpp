#include "Interface.h"


using namespace std;

// Add node at head
void LinkedList::insert_head(int data) {
	// Create a new node with data value 'data'
	Node* new_head = new Node(data);
	// Insert at the front of the list
	new_head->next = head;
	head = new_head;

	cout << "Head insert with data: " << data << endl;
	print_list();
}

// Add node at position 'p' in list
// Position 'p' must exist in the list
void LinkedList::insert_position(int data, int position) {
	// Create a new node with data value 'data'
	Node* new_node = new Node(data);
	// Set head = new_node if list is empty and p == 0
	if (head == nullptr) {
		// Check if head insertion
		// Otherwise it is an invalid operation
		if( position == 0)
		{
			head = new_node;
		}
		else {
			assert(head == NULL && position == 0);
		}
	}
	else {
		// Walk the list to get to the entry point for new node
		Node* temp = head;
		Node* prev = nullptr;
		for (int i = 0; i < position; i++) {
			// Check if insertion point is past potential new tail
			assert(temp != nullptr);
			// Update previous node and current node
			prev = temp;
			temp = temp->next;
		}
		// Check if this is actually head insertion
		// Otherwise perform normal insertion
		if (prev == nullptr) {
			head = new_node;
			head->next = temp;
		}
		else {
			new_node->next = prev->next;
			prev->next = new_node;
		}
	}
	cout << "Position " << position << " insert with data: " << data << endl;
	print_list();
}

// Add node at tail
void LinkedList::insert_tail(int data) {
	// Create new node with value "data"
	Node* new_tail = new Node(data);

	// Handle case of empty list
	// Otherwise perform normal insertion
	if (head == nullptr) {
		head = new_tail;
	}
	else {
		// Create temp for walking the list
		Node* temp = head;
		// Walk the list until the next node is nullptr
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		// Assign previous tail's 'next' to be our new node
		temp->next = new_tail;
	}
	cout << "Tail insert with data: " << data << endl;
	print_list();
}

// Delete node at head of list
void LinkedList::delete_head() {
	// Check if list is empty
	assert(head != nullptr);
	// Set head->next as new head and free old one
	Node* temp = head;
	head = temp->next;
	delete temp;
	cout << "Head delete" << endl;
	print_list();
}

// Delete node at position 'p' in list
// Asuume 'p' is a valid location
void LinkedList::delete_position(int position) {
	// Check if list is empty
	assert(head != nullptr);
	// Walk the list to the position for deletion
	Node *temp = head;
	Node* prev = nullptr;
	for (int i = 0; i < position; i++) {
		// Check if deletion point is past the end of the list
		assert(temp != nullptr);
		prev = temp;
		temp = temp->next;
	}

	// Handle head deletion
	// Otherwise normal deletion
	if (prev == nullptr) {
		head = temp->next;
	}
	else {
		prev -> next = temp -> next;
	}
	delete temp;
}

void LinkedList::delete_tail() {
	// Check if list is empty
	assert(head != nullptr);
	// Walk the list and save the previous and current node
	Node* temp = head;
	Node* prev = nullptr;
	while (temp->next != nullptr) {
		prev = temp;
		temp = temp->next;
	}
	// Handle case where there is only 1 list item
	// Otherwise normal tail delete
	if (prev == nullptr) {
		head = nullptr;
	}
	else {
		prev->next = temp->next;
	}
	delete temp;
	cout << "Tail delete" << endl;
	print_list();
}

void LinkedList::print_list() {
	for (int i = 0; i < 72; i++) {
		cout << "-";
	}
	cout << endl;
	Node* temp = head;
	cout << "List\t";
	while (temp != nullptr) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
	for (int i = 0; i < 72; i++) {
		cout << "-";
	}
	cout << endl;
}