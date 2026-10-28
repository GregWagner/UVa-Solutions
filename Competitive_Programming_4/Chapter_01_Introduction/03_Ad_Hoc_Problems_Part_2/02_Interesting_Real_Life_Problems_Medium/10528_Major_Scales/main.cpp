#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const std::vector<std::string> NOTES = {"C",  "C#", "D",  "D#", "E",  "F",
                                        "F#", "G",  "G#", "A",  "A#", "B"};

const std::vector<int> SCALE_OFFSETS = {0, 2, 4, 5, 7, 9, 11};

auto getMajorScale(int root) -> std::set<std::string> {
    std::set<std::string> scale;
    for (int offset : SCALE_OFFSETS) {
        scale.insert(NOTES[(root + offset) % 12]);
    }
    return scale;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    // precompute all 12 major scales
    std::vector<std::set<std::string>> keyScales(12);
    for (int i{}; i < 12; ++i) {
        keyScales[i] = getMajorScale(i);
    }

    std::string input;
    while (std::getline(std::cin, input) && input != "END") {
        std::stringstream ss(input);
        std::string note;
        std::vector<std::string> inputNotes;

        while (ss >> note) {
            inputNotes.push_back(note);
        }

        std::vector<std::string> validKeys;
        for (int i{}; i < 12; ++i) {
            bool valid{true};
            for (const std::string& n : inputNotes) {
                if (keyScales[i].find(n) == keyScales[i].end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                validKeys.push_back(NOTES[i]);
            }
        }
        for (size_t i{}; i < validKeys.size(); ++i) {
            output << validKeys[i] << (i + 1 == validKeys.size() ? "" : " ");
        }
        output << '\n';
    }

    std::cout << output.str();
}
