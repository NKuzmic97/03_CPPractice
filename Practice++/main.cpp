#include <conio.h>
#include <fstream>
#include <cassert>

void print(const char* msg) {
	for (; *msg != 0; msg++) {
		_putch(*msg);
	}
}

void printFixed(const char* msg, int width) {
	int n = 0;
	for (; *msg != 0; msg++) {
		n++;
		_putch(*msg);
	}
	for(; n < width;n++) {
		_putch(' ');
	}
}

void read(char* buffer, int maxSize) {
	const char* const pEnd = buffer + maxSize;
	for (char c = _getch(); c != 13 && (buffer + 1 < pEnd); c = _getch(), buffer++) {
		_putch(c);
		*buffer = c;
	}
	*buffer = 0;
}

int str2int(const char* buffer) {
	const char* p = buffer;
	for (; *p >= '0' && *p <= '9'; p++);
	p--;

	int val = 0;
	int place = 1;
	for (; p >= buffer; p--) {
		val += (*p - '0') * place;
		place *= 10;
	}

	return val;
}

int fib(int n) {
	if (n == 0 || n == 1 || n == 2) {
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

void revstr(char *pl) {
	char* pr = pl;
	for (; *pr != 0; pr++);
	pr--;

	for (; pl < pr; pl++, pr--) {
		const char temp = *pl;
		*pl = *pr;
		*pr = temp;
	}
}

void int2str(int number, char* buffer, int size) {
	char* const pStart = buffer;
	char* const pEnd = buffer + size;

	for (; number > 0 && (buffer + 1 < pEnd); number /= 10, buffer++) {
		*buffer = '0' + number % 10;
	}
	*buffer = 0;
	revstr(pStart);
}

void stringcopy(const char* pSrc, char* pDst, int maxBufferSize) {
	int n = 0;
	for(; *pSrc != 0 && (n+1 < maxBufferSize);pSrc++,pDst++,n++) {
		*pDst = *pSrc;
	}
	*pDst = 0;
}

class Database {
private:
	class Entry {
	public:
		Entry() = default;
		Entry(const char* name,int value):value(value) {
			stringcopy(name, this->name,sizeof(this->name));
		}
		void Print() const {
			printFixed(name, nameBufferSize - 1);
			_putch('|');
			for(int i=0;i<value;i++) {
				_putch('=');
			}
			_putch('\n');
		}
		void Serialize(std::ofstream& out) const {
			out.write(name, sizeof(name));
			out.write(reinterpret_cast<const char*>(&value), sizeof(value));
		}
		void Deserialize(std::ifstream& in) {
			in.read(name, sizeof(name));
			in.read(reinterpret_cast<char*>(&value), sizeof(value));
		}
		
	private:
		static constexpr int nameBufferSize = 10;
		char name[nameBufferSize];
		int value;
	};
public:
	void Load(const char* filename) {
		std::ifstream in(filename, std::ios::binary);
		in.read(reinterpret_cast<char*>(&curNumberEntries), sizeof(curNumberEntries));
		for (int i = 0; i < curNumberEntries; i++) {
			entries[i].Deserialize(in	);
		}
	}
	void Save(const char* filename) const {
		std::ofstream out(filename, std::ios::binary);
		out.write(reinterpret_cast<const char*>(&curNumberEntries), sizeof(curNumberEntries));
		for (int i = 0; i < curNumberEntries; i++) {
			entries[i].Serialize(out);
		}
	}
	void Print() const {
		for(int i=0;i<curNumberEntries;i++) {
			entries[i].Print();
		}
	}
	void Add(const char* name, int value) {
		assert(curNumberEntries < maxNumberEntries);
		entries[curNumberEntries++] = { name,value };
	}
private:
	static constexpr int maxNumberEntries = 16;
	Entry entries[maxNumberEntries];
	int curNumberEntries = 0;
};


int main() {
	Database db;
	char buffer[256];
	char buffer2[256];
	bool quit = false;

	do {
		print("(L)oad (S)ave (A)dd or (P)rint ? (Q)uit");
		char response = _getch();
		switch (response) {
			
		case 'l':
			print("\nEnter file name: ");
			read(buffer, sizeof(buffer));
			db.Load(buffer);
			_putch('\n');
			break;

		case 's':
			print("\nEnter file name: ");
			read(buffer, sizeof(buffer));
			db.Save(buffer);
			_putch('\n');
			break;
			
		case 'a':
			print("\nEnter name: ");
			read(buffer, sizeof(buffer));
			print("\nEnter value: ");
			read(buffer2, sizeof(buffer2));
			db.Add(buffer, str2int(buffer2));
			_putch('\n');
			break;

		case 'p':
			print("\n       Beautiful Chart Bitches!");
			print("\n       ------------------------\n\n");
			db.Print();
			_putch('\n');
			break;

		case 'q':
			quit = true;
			break;
		}	
	} while (!quit);
	
	return 0;
}
