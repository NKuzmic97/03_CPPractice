#include <iostream>
#include <string>
#include <conio.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

int main() {
	/* USAGE OF STD::MAP */
	
	/* std::string response;
	std::string command;

	std::map<std::string, std::string> map;

	//init

	map.emplace("aaaaa", "bbbb");
	map.insert({ "crabdance", "crab people, crab people!" });
	map.insert({ "cashme","owsigh, hawbadah?" });
	map.insert({ "so", "some dumb text bla bla" });

	// remove_if doesn't work with associative containers
	//std::remove_if(map.begin(), map.end(), [](auto& el) { return el.first.size() > 2; });


	for(auto i=map.begin();i!=map.end();) {
		if(i->first.size() > 2) {
			i = map.erase(i);
		}
		else {
			++i;
		}
	}

	for(auto& key : map) {
		std::cout << key.first << std::endl;
		//key.first = "100"; // unallowed
	}
	
	std::cin >> command;

	std::cout << map[command] << std::endl;

	*/

	
	std::vector<int> input = { 1,3,1,1,3,5,0,3,9,6,4,4,7,6,4,5,6,1,0 };
	std::set<int> seen;

	for(int in : input) {
		auto result = seen.insert(in);
		if(result.second) {
			std::cout << in << " ";
		}
	}

	std::cout << std::endl;

	while (!_kbhit());
	return 0;
}
