/*
 * 156 - Ananagrams
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

bool comp(const std::string &a, const std::string &b) {
    std::string newA {};
    for (char c : a) {
        newA += std::tolower(c);
    }
    sort(newA.begin(), newA.end());
    std::string newB {};
    for (char c : b) {
        newB += std::tolower(c);
    }
    sort(newB.begin(), newB.end());
//    std::cout << newA << "; " << newB << '\t' << a << ": " << b <<'\n';
    return (newA == newB ? true : false);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::string> words;
    std::vector<std::string> a;

    std::ostringstream output;
    std::string word;
    while (std::cin >> word && word != "#") {
        if (word.size() == 1) {
            a.push_back(word);
        } else {
            words.push_back(word);
        }
    }
    for (size_t i {}; i < words.size() - 1; ++i) {
        for (size_t j {i+1}; j < words.size(); ++j) {
            if (comp(words[i], words[j])) {
                std::cout << "Adding " << words[i] << '\n';
                a.push_back(words[i]);
            }
        }
    }
    for (auto w : a) {
        auto i = std::find(a.begin(), a.end(), w);
        if (i != a.end()) {
            words.erase(i);
        }
    }
    sort(words.begin(), words.end());
    for (auto w : words) {
        output << w << '\n';
    }
    std::cout << output.str();
}
