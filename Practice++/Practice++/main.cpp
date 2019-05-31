#include <iostream>
#include <string>
#include <stdlib.h>

class Entity {
private:
	int m_X, m_Y;
	mutable int variable;
public:
	int GetX() const{
		variable = 1;
		return m_X;
	}

	int GetX() {
		return m_X;
	}

	void SetX(int x) {
		m_X = x;
	}
};

void PrintEntity(const Entity& e) {

	std::cout << e.GetX() << std::endl;
}

int main() {

	Entity* e;
	PrintEntity(*e);

	const int MAX_AGE = 90;
	const int* const a = new int;
	
	std::cout << *a << std::endl;

	std::cin.get();
}