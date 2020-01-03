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

struct Attributes {
	int hp;
	int speed;
	int power;
};

class Weapon {
public:
	Weapon(const std::string& name, int rank):
	name(name),
	rank(rank)
	{
		//
	}
	
	const std::string& GetName() const {
		return name;
	}
	
	int GetRank() const {
		return rank;
	}
	
	virtual int CalculateDamage(const Attributes& attr, Dice& d) const = 0;
private:
	std::string name;
	int rank;
};


class MemeFighter {
public:
	void Attack (MemeFighter& other) const {
		if(IsAlive() && other.IsAlive()) {
			std::cout << name << " attacks " << other.GetName() << " with his " << pWeapon->GetName() << "!\n";
			ApplyDamageTo(other, pWeapon->CalculateDamage(attr,dice));
		}
	}
	
	void TakeDamage(MemeFighter& other) {
		attr.hp -= other.attr.power;
		std::cout << name << " has taken " << other.attr.power << " damage by " << other.name;
	}
	
	bool IsAlive() const {
		return attr.hp > 0;
	}
	
	const std::string& GetName() const {
		return name;
	}
	
	int GetInitiative() const {
		return attr.speed * Roll(2);
	}
	
	virtual void Tick() {
		if(IsAlive()) {
			const int recovery = Roll();
			std::cout << name << " recovers " << recovery << " HP .\n";
			attr.hp += recovery;
		}
	}
	
	virtual void SpecialMove(MemeFighter& other) = 0;

	void GiveWeapon(Weapon* pnWeap) {
		delete pWeapon;
		pWeapon = pnWeap;
	}

	Weapon* PilferWeapon() {
		auto pWep = pWeapon;
		pWeapon = nullptr;
		return pWep;
	}

	bool HasWeapon() const {
		return pWeapon != nullptr;
	}

	const Weapon& GetWeapon() const {
		return *pWeapon;
	}

	virtual ~MemeFighter() {
		delete pWeapon;
	}
	
protected:
	MemeFighter(const std::string& name, int hp_, int speed_, int power_, Weapon* pWeapon = nullptr)
		:
		name(name),
		attr({hp_,speed_,power_}),
		pWeapon(pWeapon)
	{
		std::cout << name << " enters the ring!\n";
	}
	
	int Roll(int nDice = 1) const {
		return dice.Roll(nDice);
	}
	
	static void ApplyDamageTo(MemeFighter& target, int damage) {
		target.attr.hp -= damage;
	}

protected:
	Attributes attr;
	std::string name = "Default";
private:
	Weapon* pWeapon = nullptr;
	mutable Dice dice;
};

class Fists : public Weapon {
public:
	Fists()
		:
	Weapon("fists",0)
	{
		//
	}
	int CalculateDamage(const Attributes& attr, Dice& d) const override {
		return attr.power + d.Roll(2);
	}
};

class Knife : public Weapon {
public:

	Knife()
		:
		Weapon("knife", 2)
	{
		//
	}
	int CalculateDamage(const Attributes& attr, Dice& d) const override {
		return attr.power * 3 + d.Roll(3);
	}
};

class Bat : public Weapon {
public:

	Bat()
		:
		Weapon("bat", 1) {
		//
	}
	int CalculateDamage(const Attributes& attr, Dice& d) const override {
		return attr.power * 2 + d.Roll(1);
	}
};

class MemeFrog : public MemeFighter {
public:
	MemeFrog(const std::string& name,Weapon* pWeapon = nullptr)
		:
		MemeFighter(name,69,7,14,pWeapon)
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
	MemeStoner(const std::string& name, Weapon* pWeapon = nullptr)
		:
	MemeFighter(name,80,40,10,pWeapon)
	{
		//
	}
	
	void SpecialMove(MemeFighter& other) override {
		if(IsAlive()) {
			if(Roll() > 3) {
				std::cout << GetName() << " smokes the dank sticky icky, becoming " << "SUPER " << GetName() << "\n";
				name = "Super " + name;
				attr.speed += 3;
				attr.power = (attr.power * 69) / 42;
				attr.hp += 10;
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

void TakeWeaponIfDead(MemeFighter& taker,MemeFighter& giver) {
	if(taker.IsAlive() && !giver.IsAlive() && giver.HasWeapon()) {
		
		if(giver.GetWeapon().GetRank() > taker.GetWeapon().GetRank()) {
			
			std::cout << taker.GetName() << " takes the " << giver.GetWeapon().GetName() <<
				" from " << giver.GetName() << "'s still-cooling corpse.\n";
			
			taker.GiveWeapon(giver.PilferWeapon());
		}
	}
}

void Engage(MemeFighter& f1, MemeFighter& f2) {
	// pointers for sorting purposes
	auto* p1 = &f1;
	auto* p2 = &f2;
	// determine attack order
	if (p1->GetInitiative() < p2->GetInitiative()) {
		std::swap(p1, p2);
	}
	// execute attacks
	p1->Attack(*p2);
	TakeWeaponIfDead(*p1, *p2);
	p2->Attack(*p1);
	TakeWeaponIfDead(*p2, *p1);
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
	TakeWeaponIfDead(*p1, *p2);
	p2->SpecialMove(*p1);
	TakeWeaponIfDead(*p2, *p1);
}

int main() {
	std::vector<MemeFighter*> t1 = {
		new MemeFrog("Dat Boi", new Fists),
		new MemeStoner("Good Guy Greg", new Bat),
		new MemeFrog("the WB frog", new Knife)
	};
	
	std::vector<MemeFighter*> t2 = {
		new MemeStoner("Chong", new Fists),
		new MemeStoner("Scumbag Steve", new Bat),
		new MemeFrog("Pepe", new Knife)
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