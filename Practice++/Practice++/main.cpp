#include <iostream>
#include <string>
#include <stdlib.h>

int main() {
	char name[] = "Cherno";
	name[2] = 'a';
	std::cout << name << std::endl;
	std::cin.get();
}