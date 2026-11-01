#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto noteToInt(const std::string& noteString) -> int {
    std::string s{noteString};
    for (char& c : s) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    if (s.empty()) {
        return -1;
    }
    char note{s[0]};
    int base{-1};
    switch (note) {
    case 'c':
        base = 0;
        break;
    case 'd':
        base = 2;
        break;
    case 'e':
        base = 4;
        break;
    case 'f':
        base = 5;
        break;
    case 'g':
        base = 7;
        break;
    case 'a':
        base = 9;
        break;
    case 'b':
        base = 11;
        break;
    default:
        return -1;
    }
    int acc{0};
    if (s.size() > 1) {
        if (s[1] == '#') {
            acc = 1;
        } else if (s[1] == 'b') {
            acc = -1;
        }
    }
    int v = (base + acc) % 12;
    if (v < 0) {
        v += 12;
    }
    return v;
}

auto getNoteName(int val) -> std::string {
    val = (val % 12 + 12) % 12;
    static const std::string names[] = {"C",  "C#", "D",  "D#", "E",  "F",
                                        "F#", "G",  "G#", "A",  "A#", "B"};
    return names[val];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string first, second, third;
    while (std::cin >> first >> second >> third) {
        int n1{noteToInt(first)};
        int n2{noteToInt(second)};
        int n3{noteToInt(third)};
        std::vector<int> notes{n1, n2, n3};

        bool isMajor{};
        bool isMinor{};
        std::string rootNote;

        for (int i{}; i < 3; ++i) {
            int root{notes[i]};
            int majThird{(root + 4) % 12};
            int minThird{(root + 3) % 12};
            int fifth{(root + 7) % 12};
            int s2{notes[(i + 1) % 3]};
            int s3{notes[(i + 2) % 3]};
            if ((s2 == majThird && s3 == fifth) ||
                (s2 == fifth && s3 == majThird)) {
                isMajor = true;
                rootNote = getNoteName(root);
                break;
            }
            if ((s2 == minThird && s3 == fifth) ||
                (s2 == fifth && s3 == minThird)) {
                isMinor = true;
                rootNote = getNoteName(root);
                break;
            }
        }

        output << first << ' ' << second << ' ' << third << " is ";
        if (isMajor) {
            output << "a " << rootNote << " Major chord.\n";
        } else if (isMinor) {
            output << "a " << rootNote << " Minor chord.\n";
        } else {
            output << "unrecognized.\n";
        }
    }
    std::cout << output.str();
}
