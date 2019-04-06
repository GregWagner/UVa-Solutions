/*
 * Problem 12554 - A Special "Happy Birthday"
 */
#include <iostream>
#include <sstream>

int main()
{
	std::string names[110];
	std::string song[] = {"Happy", "birthday" , "to", "you",
		"Happy", "birthday" , "to", "you",
		"Happy", "birthday" , "to", "Rujia",
		"Happy", "birthday" , "to", "you"};

	std::ios::sync_with_stdio(false);
	std::ostringstream output;

	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i) {
		std::cin >> names[i];
	}

	int timesThrough = 16 * ((count / 16) + 1);
	for (int i = 0; i < timesThrough; ++i) {
		output << names[i % count] << ": " << song[i % 16] << '\n';
	}
	std::cout << output.str();
}
