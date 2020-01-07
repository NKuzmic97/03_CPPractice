#include <iostream>
#include <string>
#include <vector>

class Cat {
public:
	Cat() {
		std::cout << "Constructing a Cat" << std::endl;
	}
	Cat(Cat&&) noexcept {
		// cats wont be moved but instead copied if move constructor is not marked as noexcept
		std::cout << "Moving a Cat" << std::endl;
	}

	Cat(const Cat&) {
		std::cout << "Copying a Cat" << std::endl;
	}
};

class Annoucer {
public:
	Annoucer(std::string name_)
	:
	name(name_)

	{
		std::cout << "Annoucer " << name << " created." << std::endl;
	}
	~Annoucer() noexcept {
		std::cout << "Annoucer " << name << " deleted." << std::endl;
		
		//throw std::runtime_error("This program is dead");
		// never throw exceptions from destructors
	}
private:
	std::string name;
};

int sum(int a,int b) {
	Annoucer j("j");
	Annoucer k("k");


	// this will get deleted by RAII when thrown exception
	auto p = std::make_unique<Annoucer>("p");

	// Line below leaks memory in case of exception thrown.
	//auto p = new Annoucer("p");
	
	if(a==70) {
		throw std::runtime_error("<a> is bad number!");
	}

	if(b==450) {
		throw std::logic_error("<b> is bad number!");
	}

	Annoucer c("c");
	
	return a + b;
}

int f(int x,int y,int z) {
	try {
		return sum(x, y) * sum(y, z);
	}
	catch (const std::runtime_error& err) {
		std::cout << "Caught a std::runtime_error in f: " << err.what() << std::endl;
		throw;
	}
}

int main() {
	
	try {
		std::cout << f(70,75,450) << std::endl;
	}
	catch(const std::runtime_error& err) {
		std::cout << "Caught a std::runtime_error in main: " << err.what() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "Caught an std::exception in main: " << e.what() << std::endl;
	}
	catch(...) {
		std::cout << "Caught *something* in main. " << std::endl;
	}

	std::cout << "-------------------------------------------"<< std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	
	std::vector<Cat> cats;
	
	std::cout << std::endl;
	cats.emplace_back();
	
	std::cout << std::endl;
	cats.emplace_back();
	
	std::cout << std::endl;
	cats.emplace_back();
	
	std::cout << std::endl;

	std::cin.get();
	return 0;
} 
