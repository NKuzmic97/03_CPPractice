#include <conio.h>

void print(const char* msg) {
	for (; *msg != 0; msg++) {
		_putch(*msg);
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

int main() {
	print("Enter a number: ");
	char answer[69];
	read(answer, 69);

	print("\nFibonacci number <");
	print(answer);
	print("> is: ");

	const int fibNumber = fib(str2int(answer));

	int2str(fibNumber, answer, 69);

	print(answer);

	while (!_kbhit());
}
