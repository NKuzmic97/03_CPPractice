#include <iostream>
#include <string>

class Entity {
	std::string m_Name;
	int m_Age;
public:
	 Entity(const std::string& name):m_Name(name){}
	 Entity(int age):m_Name("Unknown"),m_Age(age){}
};

void PrintEntity(const Entity& entity) {

}

int main() {
	PrintEntity(22);
	PrintEntity(std::string("Cherno"));
	Entity a = "Cherno";
	Entity b =(Entity) 22;
	std::cin.get();
}