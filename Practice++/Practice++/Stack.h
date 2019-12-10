#pragma once

class LinkedList {
	class Node {
	public:
		Node(int data):
		data(data),
		next(nullptr),
		prev(nullptr)
		{}
		
		Node* next = nullptr;
		Node* prev = nullptr;
		int data;
	};
	Node* headNode = nullptr;
	int size = 0;
public:

	LinkedList() = default;
	
	LinkedList(const LinkedList& other) {
			headNode = nullptr;
			Node* otherCurrentNode = other.headNode;
		
			while(otherCurrentNode->prev != nullptr) {
				otherCurrentNode = otherCurrentNode->prev;
			}

			while(otherCurrentNode != nullptr) {
				Add(otherCurrentNode->data);
				otherCurrentNode = otherCurrentNode->next;
			}
		
		}

	LinkedList& operator=(const LinkedList& other) {
		(*this).~LinkedList();
		
		headNode = nullptr;
		Node* otherCurrentNode = other.headNode;

		while (otherCurrentNode->prev != nullptr) {
			otherCurrentNode = otherCurrentNode->prev;
		}

		while (otherCurrentNode != nullptr) {
			Add(otherCurrentNode->data);
			otherCurrentNode = otherCurrentNode->next;
		}
		return *this;
	}

	~LinkedList() {
		while(headNode != nullptr) {
			Remove();
		}
		delete headNode;
	}

	void Add(int value) {
		if (headNode == nullptr) {
			headNode = new Node(value);
		}
		else {
			Node* prevTmp = headNode;
			headNode->next = new Node(value);
			headNode = headNode->next;
			headNode->prev = prevTmp;
		}
		size++;
	}
	int Remove() {
		if (headNode != nullptr) {
			int tempReturn = headNode->data;
			
			Node* tmp = headNode;
			
			headNode = headNode->prev;
			
			if (headNode != nullptr) {
				headNode->next = nullptr;
			}
			
			delete tmp;
			
			if (size == 0) {
				headNode = nullptr;
			}

			size--;
			
			return tempReturn;
		}

		return -1;
	}

	int GetSize() const {
		return size;
	}
};

class Stack {
private:
	LinkedList linkedList;
	int size = 0;
public:
	Stack() = default;
	
	Stack (const Stack& other):
	linkedList(other.linkedList){
		size = linkedList.GetSize();
	}

	~Stack() {
		while(size > 0) {
			Pop();
		}
	}

	
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;

};


