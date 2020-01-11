#include <conio.h>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>

void Fifty(){
	std::cout << "50" << std::endl;
};

void Fortytwo() {
	std::cout << "42" << std::endl;
};

int DoubleNum(int x) {
	return x * 2;
}

int TripleNum(int x) {
	return x * 3;
}

int main() {
	 std::unordered_map<std::string, std::function<void()>> sw;

	 sw["fifty"] = []()
	 {
		 std::cout << "50" << std::endl;
	 };
	
	 sw["forty-two"] = Fortytwo;

	 sw["forty-two"]();

	/* int(*pFunc)(int);

	pFunc = DoubleNum;

	std::cout << pFunc(3) << std::endl;

	pFunc = TripleNum;
	std::cout << pFunc(3) << std::endl;
	*/

	while (!_kbhit());
	return 0;
}