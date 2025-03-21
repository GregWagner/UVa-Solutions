/*
 * 12554 A Speccial Happy Birthday
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> song = {
        "Happy", "birthday" , "to", "you",
		"Happy", "birthday" , "to", "you",
		"Happy", "birthday" , "to", "Rujia",
		"Happy", "birthday" , "to", "you"};

    std::ostringstream output;
    int numberOfPeople {};
    std::cin >> numberOfPeople;
    std::vector<std::string> names(numberOfPeople);
    for (int i {}; i < numberOfPeople; ++i) {
        std::cin >> names[i];
    }
    int loopCount = 1 + std::ceil(numberOfPeople / song.size());

    int nameIndex {};
    int songIndex {};
    for (int i {}; i < loopCount; ++i) {
        for (size_t j {}; j < song.size(); ++j) {
            output << names[nameIndex] << ": " << song[songIndex] << '\n';
            nameIndex = (nameIndex + 1) % numberOfPeople;
            songIndex = (songIndex + 1) % song.size();
        }
    }
    std::cout << output.str();
}
