#include <iostream>
#include <string>
#include <conio.h>
#include <random>

class Dice {
public:
	int Roll(int nDice) {
		int total = 0;
		for (int n = 0; n < nDice; n++) {
			total += d6(rng);
		}
		return total;
	}
private:
	std::uniform_int_distribution<int> d6 = std::uniform_int_distribution<int>(1, 6);
	std::mt19937 rng = std::mt19937(std::random_device{}());
};

class MemeFighter {
public:
	void Punch (MemeFighter& other) const {
		if(IsAlive() && other.IsAlive()) {
			std::cout << name << " punches " << other.GetName()
				<< "!\n";
			ApplyDamageTo(other, power + Roll(2));
		}
	}
	void TakeDamage(MemeFighter& other) {
		hp -= other.power;
		std::cout << name << " has taken " << other.power << " damage by " << other.name;
	}
	bool IsAlive() const {
		return hp > 0;
	}
	const std::string& GetName() const {
		return name;
	}
	int GetInitiative() const {
		return speed * Roll(2);
	}
	void Tick() {
		if(IsAlive()) {
			const int recovery = Roll();
			std::cout << name << " recovers " << recovery << " HP .\n";
			hp += recovery;
		}
	}
	
protected:
	MemeFighter(const std::string& name, int hp_, int speed_, int power_)
	:
	name(name),
	hp(hp_),
	speed(speed_),
	power(power_)
	{
	std::cout << name << " enters the ring!\n";
	}
	int Roll(int nDice = 1) const {
		return dice.Roll(nDice);
	}
	static void ApplyDamageTo(MemeFighter& target, int damage) {
		target.hp -= damage;
	}
	
protected:
	std::string name = "Default";
	int hp;
	int power;
	int speed;
	
private:
	mutable Dice dice;
};

class MemeFrog : public MemeFighter {
public:
	MemeFrog(const std::string& name)
		:
		MemeFighter(name,69,7,14)
	{
		//
	}
	void SpecialMove(MemeFighter& other) const {
		if(IsAlive() && other.IsAlive()) {
			if(Roll() > 4) {
				std::cout << GetName() << " attacks " << other.GetName() << " with rainbow beam!\n";
				ApplyDamageTo(other, Roll(3) + 20);
			}
			else {
				std::cout << GetName() << " falls off his unicycle.\n";
			}
		}
	}
	void Tick() {
		if (IsAlive()) {
			std::cout << GetName() << " is hurt by the bad AIDS!\n";
			ApplyDamageTo(*this, Roll());
			MemeFighter::Tick();
		}
	}
};

class MemeStoner : public MemeFighter {
public:
	MemeStoner(const std::string& name)
		:
	MemeFighter(name,80,40,10)
	{
		//
	}
	void SpecialMove() {
		if(IsAlive()) {
			if(Roll() > 3) {
				std::cout << GetName() << " smokes the dank sticky icky, becoming " << "SUPER " << GetName() << "\n";
				name = "Super " + name;
				speed += 3;
				power = (power * 69) / 42;
				hp += 10;
			}
			else {
				std::cout << GetName() << " spaces out.\n";
			}
		}
	}

};



void Engage(MemeFighter& f1, MemeFighter& f2) {
	// pointers for sorting purposes
	auto* p1 = &f1;
	auto* p2 = &f2;
	// determine attack order
	if (p1->GetInitiative() < p2->GetInitiative()) {
		std::swap(p1, p2);
	}
	// execute attacks
	p1->Punch(*p2);
	p2->Punch(*p1);
}

int main() {
	MemeFrog f1("Dat Boi");
	MemeStoner f2("Good Guy Greg");

	while (f1.IsAlive() && f2.IsAlive()) {
		// trade blows
		Engage(f1, f2);
		// special moves
		f2.SpecialMove();
		f1.SpecialMove(f2);
		// end of turn maintainence
		f1.Tick();
		f2.Tick();

		std::cout << "Press any key to continue...";
		while (!_kbhit());
		_getch();
		std::cout << std::endl << std::endl;
	}

	if (f1.IsAlive()) {
		std::cout << f1.GetName() << " is victorious!";
	}
	else {
		std::cout << f2.GetName() << " is victorious!";
	}
	while (!_kbhit());
	return 0;
}