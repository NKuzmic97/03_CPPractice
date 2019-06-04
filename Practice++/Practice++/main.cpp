#include <iostream>
#include <string>

using String = std::string;

class Entity {
private:
	String m_Name;
public:
	Entity() :m_Name("Unknown") { std::cout << "0"; }
	Entity(const String& name):m_Name(name){
		std::cout << "1";
	}
	const String& GetName() const { return m_Name; }
};


int main() {
	int a = 2;
	int* b = new int[50];

	Entity* entity = new(b) Entity();
	delete entity;
	delete[] b;
	std::cin.get();
}