#include <unordered_map>
#include "Vec2.h"
#include <iostream>
#include <string>

struct HashVec2 {
	template<typename T>
	size_t operator()(const Vec2_<T>& vec) const {
		std::hash<T> hasher;
		auto hashx = hasher(vec.x);
		auto hashy = hasher(vec.y);

		hashx ^= hashy + 0x9e3779b9 + (hashx << 6) + (hashx >> 2);
		return hashx;
	}
};

int main() {
	std::unordered_map<Vei2, std::string, HashVec2> map({
		{{23,40},"twenty three"},
		{{99,7000},"ninety nine"},
		{{1000000,59},"milion"},
		{{1337,420}, "elite"}

		});

	std::cout << map[{23, 40}] << std::endl;

	std::cin.get();
	return 0;
}