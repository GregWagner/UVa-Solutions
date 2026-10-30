// 11946 - Code Number
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    // Build static mapping table
    char map_table[256];
    for (int i{}; i < 256; ++i) {
        map_table[i] = static_cast<char>(i);
    }

    // Leetspeak substitutions
    map_table['3'] = 'E';
    map_table['6'] = 'G';
    map_table['1'] = 'I';
    map_table['0'] = 'O';
    map_table['9'] = 'P';
    map_table['8'] = 'B';
    map_table['5'] = 'S';
    map_table['7'] = 'T';
    map_table['2'] = 'Z';
    map_table['4'] = 'A';

    int testCases;
    std::cin >> testCases;
    std::string line;
    std::getline(std::cin, line); // consume end of line
    bool firstCase = true;
    while (testCases--) {
        // skip leading blank lines
        while (std::getline(std::cin, line)) {
            if (!line.empty()) break;
        }
        if (std::cin.eof() && line.empty()) break;
        if (!firstCase) output << "\n";
        firstCase = false;
        // process first non-empty line and the following lines until blank
        while (true) {
            for (char& c : line) {
                c = map_table[static_cast<unsigned char>(c)];
            }
            output << line << "\n";
            if (!std::getline(std::cin, line)) break;
            if (line.empty()) break;
        }
    }

    std::cout << output.str();
}