#include <iostream>

int main() {
	void* ptr = new int(5);
	std::cout <<"ptr points to: " << ptr << std::endl;
	std::cout <<"address of ptr pointer: " << &ptr << std::endl;
	std::cout <<"size of void pointer: " << sizeof(ptr) << std::endl;
	//std::cout << *ptr << std::endl; // Doesn't work. Unable to dereference void pointers.
	std::cout <<"casted void* to int*: " << static_cast<int*>(ptr) << std::endl;
	std::cout <<"dereferenced casted void* to int*: " << *static_cast<int*>(ptr) << std::endl;
	std::cin.get();
}