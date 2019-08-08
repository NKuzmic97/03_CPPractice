#include <iostream>
using namespace std;
#define SIZE 10

class Stack {
private:
	int* array;
	int top;
	int size;
public:
	Stack() :top(-1), size(SIZE){
		array = new int[size];
	}
	Stack(int size) :top(-1), size(size) {
		array = new int[size];
	}
	~Stack() {
		cout << "Pozvan destruktor.\n";
		delete[] array;
	}
	bool isempty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	void push(int value) {
		if (top == size - 1)
			cout << "Stack is full!";
		else {
			top++;
			array[top] = value;
			cout << "Value pushed into stack: " << array[top] << "\n";
		}
	}
	void pop() {
		if (isempty()) {
			cout << "Stack is empty!";
		}
		else {
			cout << "Value poped from stack: " << array[top] << "\n";
			top--;
		}
	}
	void show_top() {
		if (isempty())
			cout << "Stack is empty!";
		else
			cout << "Element at top is: " << array[top] << "\n";
	}
	void displayStack() {
		if (isempty()) {
			cout << "Stack is empty!\n";
		}
		else {
			for (int i = 0; i <= top; i++) {
				cout << "Element at: INDEX " << i << " is: " << array[i] << "\n";
			}
		}
	}
};
int stack_simulation()
{
	//Kreiranje objekta stack klase Stack koristeci STACK memoriju.
	Stack stack;
	stack.push(2);
	stack.push(3);
	stack.displayStack();
	stack.pop();
	stack.push(5);
	stack.show_top();
	stack.displayStack();
	cout << "\n";
	//Kreiranje dinamickog objekta hstack klase Stack koristeci HEAP memoriju.
	Stack* hstack = new Stack();
	(*hstack).push(2);
	(*hstack).push(3);
	(*hstack).displayStack();
	(*hstack).pop();
	(*hstack).push(5);
	(*hstack).show_top();
	(*hstack).displayStack();
	delete hstack;
	hstack = nullptr;
	//Github
	return 0;
}