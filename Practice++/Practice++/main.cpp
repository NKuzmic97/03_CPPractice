#include <iostream>
#include <string>

class Entity {
public:
	int X, Y;
	void Print(){}
public:
	Entity() {
		X = 0;
		Print();
	}
};

class Player :public Entity {
	Player() {
		X = 2;
		Print();
	}
};

int main() {
	Entity e;
	e.Print();
	e.X = 2;
	std::cin.get();
}