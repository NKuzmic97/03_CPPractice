#include "Stack.h"

void Stack::Push(int val) {
	linkedList.Add(val);
	size++;
}

int Stack::Pop() {
	if (size > 0) {
		size--;
		return linkedList.Remove();
	}
	return -1;
}

int Stack::Size() const {
	return size;
}

bool Stack::Empty() const {
	return size == 0;
}