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
	Entity* eptr;
	{
		Entity* entity = new Entity("Cherno");
		eptr = entity;
		std::cout << eptr->GetName() << std::endl;
	}
	std::cin.get();
	delete eptr;
}