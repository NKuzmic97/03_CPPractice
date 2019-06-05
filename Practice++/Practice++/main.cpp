#include <iostream>
#include <string>

class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size+1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}
	~String() {
		delete[] m_Buffer;
	}
	char& operator[](unsigned int index) {
		return m_Buffer[index];
	}
	//String(const String& other) {
		//memcpy(this, &other, sizeof(String));
	String(const String& other):m_Size(other.m_Size) {
		std::cout << "Copy construcotr" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size+1);
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) {
	String copy = string;
	std::cout << copy << std::endl;
}

int main() {
	String string = "Cherno";
	std::cout << string << std::endl;
	String second = string;
	second[2] = 'a';
	PrintString(string);
	PrintString(second);
	std::cin.get();
}