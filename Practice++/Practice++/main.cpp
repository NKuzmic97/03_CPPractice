#include <iostream>
#include <string>
#include <conio.h>
#include <random>
#include <algorithm>

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
	virtual void Tick() {
		if(IsAlive()) {
			const int recovery = Roll();
			std::cout << name << " recovers " << recovery << " HP .\n";
			hp += recovery;
		}
	}
	virtual void SpecialMove(MemeFighter& other) = 0;

	virtual ~MemeFighter() = default;
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
	void SpecialMove(MemeFighter& other) override {
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
	void Tick() override {
		if (IsAlive()) {
			std::cout << GetName() << " is hurt by the bad AIDS!\n";
			ApplyDamageTo(*this, Roll());
			MemeFighter::Tick();
		}
	}
	~MemeFrog() {
		std::cout << "Destroying MemeFrog " << name << "!\n";
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
	void SpecialMove(MemeFighter& other) override {
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
	
	~MemeStoner() {
		std::cout << "Destroying MemeStoner " << name << "!\n";
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

void DoSpecials(MemeFighter& f1,MemeFighter& f2) {
	// pointers for sorting purposes
	auto* p1 = &f1;
	auto* p2 = &f2;
	// determine attack order
	if(p1->GetInitiative() < p2->GetInitiative()) {
		std::swap(p1, p2);
	}
	// execute attacks
	p1->SpecialMove(*p2);
	p2->SpecialMove(*p1);
}

int main() {
	std::vector<MemeFighter*> t1 = {
		new MemeFrog("Dat Boi"),
		new MemeStoner("Good Guy Greg"),
		new MemeFrog("the WB frog")
	};
	
	std::vector<MemeFighter*> t2 = {
		new MemeStoner("Chong"),
		new MemeStoner("Scumbag Steve"),
		new MemeFrog("Pepe")
	};

	const auto alive_pred = [](MemeFighter* pf) { return pf->IsAlive(); };

	while (
		std::any_of(t1.begin(),t1.end(),alive_pred) &&
		std::any_of(t2.begin(),t2.end(),alive_pred)
		) {
		std::random_shuffle(t1.begin(), t1.end());
		std::partition(t1.begin(), t1.end(), alive_pred);
		std::random_shuffle(t2.begin(), t2.end());
		std::partition(t2.begin(), t2.end(), alive_pred);

		for(size_t i =0;i<t1.size();i++) {
			Engage(*t1[i], *t2[i]);
			DoSpecials(*t1[i], *t2[i]);
			std::cout << "-----------------------------------------\n";
		}
		std::cout << "========================================\n";

		for (size_t i = 0; i < t1.size(); i++) {
			t1[i]->Tick();
			t2[i]->Tick();
		}

		std::cout << "==================================\n";
		
		std::cout << "Press any key to continue...";
		while (!_kbhit());
		_getch();
		std::cout << std::endl << std::endl;
	}

	if (std::any_of(t1.begin(),t1.end(),alive_pred)) {
		std::cout << "Team ONE is victorious!\n";
	}
	else {
		std::cout << "Team TWO is victorious!\n";
	}

	for (size_t i = 0; i < t1.size(); i++) {
		delete t1[i];
		delete t2[i];
	}
	
	while (!_kbhit());
	return 0;
}