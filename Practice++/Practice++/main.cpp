#include <iostream>
#include <string>
#include <conio.h>
#include <unordered_map>

int main() {
	// create uo map and init

	std::unordered_map<std::string, int> map({
		
		{ "one",1 },
		{ "two",2 },
		{ "three",3 },
		{ "four",4 },
		{ "five",5 },
		{ "six",6 },
		{ "seven",7 },
		{"eight",8},
		{"nine",9},
		{"zero",0}
		
		}
	);

	std::string input;
	std::cin >> input;

	auto i = map.find(input);

	// print val if key exists
	if(i!= map.end()) {
		std::cout << i->second << std::endl;
	}
	else {
		std::cout << "Not found" << std::endl;
	}

	while (!_kbhit());
	return 0;
}