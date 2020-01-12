#include <conio.h>
#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

class StringSwitch {
public:
	std::function<void()>& Case(const std::string& str) {
		return map[str];
	}

	std::function<void()>& Default() {
		return def;
	}

	void operator[](const std::string& str) const {
		auto i = map.find(str);
		if(i!= map.end()) {
			i->second();
		}
		else {
			def();
		}
	}
	
private:
	std::unordered_map<std::string, std::function<void()>> map;
	std::function<void()> def = []() {};
};


int main() {

	int x = 70;
	
	StringSwitch sw;
	sw.Case("foo") = [&]() { std::cout << "you did a foo " << x << std::endl; };
	sw.Case("bar") = []() { std::cout << "you did a bar" << std::endl; };

	sw.Default() = []() {std::cout << "error" << std::endl; };

	sw["foo"];
	sw["nemanja"];
	
	while (!_kbhit());
	return 0;
}