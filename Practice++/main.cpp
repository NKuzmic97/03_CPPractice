#include <iostream>
#include <string>

class Entity {
public:
	virtual void PrintName(){
		std::cout << "Hello! I'm entity.";
	}
};

class Player : public Entity {};

class Enemy:public Entity{};

int main() {
	Player* player = new Player();

	Entity* actuallyPlayer = player;
	Entity* actuallyEnemy = new Enemy();

	Player* p = dynamic_cast<Player*>(actuallyEnemy);
	std::cout << p << "\n";
	p = dynamic_cast<Player*>(actuallyPlayer);
	std::cout << p << "\n";
	
	p->PrintName();

	// End of program
	std::cin.get();
}