#include <iostream>
#include <array>
class Entity {
	static const int size=5;
	int example[size];
	std::array<int, 5> another;
public:
	Entity()
	{
		for (int i = 0; i < another.size; i++)
		example[i] = 2;
	}
};

int main() {
	Entity e;
	std::cin.get();
}