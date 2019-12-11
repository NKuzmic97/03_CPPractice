#pragma once

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

private:
	Node* headNode = nullptr;
};



