/*
 * No Duplicates
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }
    std::sort(words.begin(), words.end());
    
    std::string previous = "";
    bool repeat {};
    for (auto w : words) {
        if (w == previous) {
            repeat = true;
            break;
        }
        previous = w;
    }
    std::cout << (repeat ? "no" : "yes") << '\n';
}
