#include <iostream>
#include <string>
class Entity {
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name):m_Name(name),m_Age(-1){}
	explicit Entity(int age):m_Name("Unknown"),m_Age(age){}
};
void PrintEntity(const Entity& entity) {
	//Printing
}
int main() {
	PrintEntity(22);
	PrintEntity(Entity("Cherno"));

	Entity a = "Cherno";
	Entity b = 22;
	std::cin.get();
}