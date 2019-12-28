#pragma once
#include <iterator>

class Stack {
class Node {
	public:
		Node(int data, Node* pNext):
		data(data),
		next(pNext)
		{}

		Node(const Node& other):
		data(other.data)
		{
			if(other.next != nullptr) {
				next = new Node(*other.next);
			}
		}

		Node& operator=(const Node&) = delete;
		int GetData() const { return data; }
		
		Node* next = nullptr;
		int data;

		Node* Disconnect() {
			auto pTemp = next;
			next = nullptr;
			return pTemp;
		}
		int Count() {
			if(next != nullptr) {
				return next->Count() + 1;
			}
			else {
				return 1;
			}
		}

		~Node() {
			delete next;
			next = nullptr;
		}
	};
	
public:
public:
	class Iterator {
	public:
		Iterator() = default;

		Iterator(Node* pNode) :
			pNode(pNode) {
			//
		}

		Iterator& operator++() {
			pNode = pNode->next;
			return *this;
		}

		int& operator*() {
			return pNode->data;
		}

		bool operator!=(Iterator rhs) const {
			return pNode != rhs.pNode;
		}

	private:
		Node* pNode;
	};
	
	class ConstIterator {
	public:
		ConstIterator() = default;

		ConstIterator(Node* pNode) :
			pNode(pNode) {
			//
		}

		ConstIterator& operator++() {
			pNode = pNode->next;
			return *this;
		}

		const int& operator*() const {
			return pNode->data;
		}

		bool operator!=(ConstIterator rhs) const {
			return pNode != rhs.pNode;
		}

	private:
		Node* pNode;
	};
	Stack() = default;
	
	Stack(const Stack& other) {
		*this = other;
	}

	Stack& operator=(const Stack& other) {
		if(&other != this) {
			if(!Empty()) {
				delete headNode;
				headNode = nullptr;
			}
			if(!other.Empty()) {
				headNode = new Node(*other.headNode);
			}
		}

		return *this;
	}

	~Stack() {
		delete headNode;
		headNode = nullptr;
	}

	void Push(int value) {
		headNode = new Node(value, headNode);
	}
	int Pop() {
		if(!Empty()) {
			const int tempVal = headNode->GetData();
			auto pOldTop = headNode;
			headNode = headNode->Disconnect();
			delete pOldTop;
			return tempVal;
		}

		return -1;
	}

	int Size() const {
		if(!Empty()) {
			return headNode->Count();
		}
		else {
			return 0;
		}
	}

	bool Empty() const {
		return headNode == nullptr;
	}

	Iterator begin() {
		return { headNode };
	}

	Iterator end() {
		return {};
	}

	ConstIterator begin() const {
		return{headNode};
	}

	ConstIterator end() const {
		return {};
	}

private:
	Node* headNode = nullptr;
};



