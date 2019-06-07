#include <iostream>

class Osoba {
private:
	const char* ime;
	const char* prezime;
	int* godiste;
	static int br_osoba;
public:
	Osoba() :ime("Nema imena."), prezime("Nema prezimena."), godiste(new int(-1)){
		br_osoba++;
	}
	Osoba(const char* ime, const char* prezime, int godiste) :ime(ime), prezime(prezime), godiste(new int(godiste)) {
		br_osoba++;
	}
	~Osoba() {
		delete godiste;
		std:: cout << "Pozvan destruktor.";
	}
	const char* GetIme() const {
		return (*this).ime;
	}
	const char* GetPrezime() const {
		return (*this).prezime;
	}
	const int& GetGodiste() const {
		return *(this->godiste);
	}
	friend std::ostream& operator<<(std::ostream& stream, const Osoba& osoba);
};
int Osoba::br_osoba = 0;

class ScopedPtr {
private:
	Osoba* osoba;
public:
	ScopedPtr(const char* ime,const char* prezime, int godiste){

		osoba = new Osoba(ime, prezime, godiste);
	}
	~ScopedPtr() {
		std::cout << "Pozvan destruktor ScopedPtr" << std::endl;
		delete osoba;
	}
	const Osoba& GetOsoba() const {
		return *osoba;
	}
};

std::ostream& operator<<(std::ostream& stream,const Osoba& osoba) {
	stream << "Moje ime je: " << osoba.ime << " Prezime: " << osoba.prezime << " Godiste: " << osoba.GetGodiste() << std::endl;
	stream << "Broj osoba: " << Osoba::br_osoba << std::endl;
	return stream;
}

int main() {
	std::cout << "Zdravo svete." << std::endl;
	{
		ScopedPtr sp1("Nemanja", "Kuzmic", 1997);
		ScopedPtr sp2 = { "Milos", "Kuzmic", 2002 };
		std::cout << sp1.GetOsoba();
		std::cout << sp2.GetOsoba();
	}

	std::cin.get();
}