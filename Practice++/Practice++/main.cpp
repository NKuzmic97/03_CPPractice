#include <iostream>
#include <string>

// Parametric polymorphism - Compile time polymorphism
template <class T>
T max(T& a, T& b) {
	return a > b ? a : b;
}
// Subtype runtime polymorphism - subclassess and virtual override functions
class Animal {
public:
	virtual void MakeNoise() = 0;
};
class Cat : public Animal {
public:
	void MakeNoise() override {
		std::cout << "Meow.\n";
	}
};
class Dog : public Animal {
public:
	void MakeNoise() override {
		std::cout << "Woof.\n";
	}
};
void Stroke(Animal* animal) {
	animal->MakeNoise();
}
// Ad-hoc polymorphysm - same function name different return type, different parameter list and different definiton
int PrintNumber(int number) {
	return number;
}
int PrintNumber(std::string str) {
	return str.size();
}

// Coercion polymorphism --- CASTING ----
class CrazyInt {
	int v;
public:
	CrazyInt(int i) : v(i) {}
	operator int() const { return v; } // conversion from CrazyInt to int
};
void print_int(int a) {
	std::cout << a << std::endl;
}

int main() {
	// Subtype runtime polymorphism - subclassess and virtual override functions
	// Not allowed - pure virtual function: Animal a;
	std::cout << "Subtype runtime polymorphism - subclassess and virtual override functions.\n";
	Dog dog;
	Cat cat;
	Stroke(&cat);
	Stroke(&dog);
	// Ad-hoc polymorphysm - same function name different return type, different parameter list and different definiton -- OVERLOADING --
	std::cout << "Ad-hoc polymorphysm - same function name different return type, different parameter list and different definiton\n";
	std::cout << PrintNumber(5) << "\n";
	std::cout << PrintNumber("Nemanja") << "\n";

	// Parametric polymorphism - Compile time polymorphism
	std::cout << "Parametric polymorphism - Compile time polymorphism\n";
	int a = 7, b = 3;
	std::cout << max(a, b) << "\n";
	std::string foo = "foo", bar = "bar";
	std::cout << max(foo, bar) << "\n";
	// Coercion polymorphism --- CASTING ----
	std::cout << "Coercion polymorphism --- CASTING ----\n";
	CrazyInt crazyInt = 123;
	print_int(653);
	print_int(crazyInt);
	// End of program
	std::cin.get();
}