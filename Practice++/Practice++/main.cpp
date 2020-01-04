#include <iostream>
#include <string>
#include <vector>

void nomnomnom(const std::string& str) {
	std::cout << "lval nom\n";
	auto copy = str;
	for(auto& c : copy) {
		c++;
	}
	std::cout << "Nom nom nom: " << copy << "\n";
}

void nomnomnom(std::string&& donor) {
	std::cout << "rval nom\n";
	for(auto& c : donor) {
		c++;
	}

	std::cout << "nom nom: " << donor << "\n";
}

int main() {
	std::string s = "This is just a temporary string.";
	nomnomnom(std::move(s));
	std::cout << "After nom: " << s << "\n";
	
	nomnomnom(std::string("another temporary string"));

	std::string a = "i am string a";
	std::string b = std::move(a);

	std::cout << "string a: " << a << std::endl << "string b: " << b << std::endl;
	
	std::cin.get();
	return 0;
}