#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

static std::map<std::string, std::vector<std::string>> buildScales() {
    std::map<std::string, std::vector<std::string>> s;
    s["A"]  = {"A", "B", "C#", "D", "E", "F#", "G#"};
    s["Ab"] = {"Ab", "Bb", "C", "Db", "Eb", "F", "G"};
    s["B"]  = {"B", "C#", "D#", "E", "F#", "G#", "A#"};
    s["Bb"] = {"Bb", "C", "D", "Eb", "F", "G", "A"};
    s["C"]  = {"C", "D", "E", "F", "G", "A", "B"};
    s["D"]  = {"D", "E", "F#", "G", "A", "B", "C#"};
    s["Db"] = {"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"};
    s["E"]  = {"E", "F#", "G#", "A", "B", "C#", "D#"};
    s["Eb"] = {"Eb", "F", "G", "Ab", "Bb", "C", "D"};
    s["F"]  = {"F", "G", "A", "Bb", "C", "D", "E"};
    s["G"]  = {"G", "A", "B", "C", "D", "E", "F#"};
    s["Gb"] = {"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"};
    return s;
}

static std::string trim(const std::string& s) {
    std::size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    std::size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto scales = buildScales();
    std::ostringstream output;

    std::string key;
    while (true) {
        while (std::getline(std::cin, key)) {
            key = trim(key);
            if (!key.empty()) break;
        }
        if (!std::cin && key.empty()) break;
        if (key.empty()) break;

        std::string queriesLine;
        while (std::getline(std::cin, queriesLine)) {
            queriesLine = trim(queriesLine);
            if (!queriesLine.empty()) break;
        }
        if (queriesLine.empty()) break;

        output << "Key of " << key << "\n";

        std::vector<std::string> queries;
        std::istringstream qss(queriesLine);
        std::string part;
        while (std::getline(qss, part, ';')) {
            part = trim(part);
            if (!part.empty()) queries.push_back(part);
        }

        const auto& scale = scales[key];

        for (const auto& q : queries) {
            std::istringstream iss(q);
            std::string root, dir, degree;
            iss >> root >> dir >> degree;

            int rootIdx = -1;
            for (int i = 0; i < 7; ++i) {
                if (scale[i] == root) { rootIdx = i; break; }
            }
            if (rootIdx == -1) {
                output << root << ": invalid note for this key\n";
                continue;
            }

            int offset = 0;
            if (dir == "UP") {
                if (degree == "SECOND") offset = 1;
                else if (degree == "THIRD") offset = 2;
                else if (degree == "FOURTH") offset = 3;
                else if (degree == "FIFTH") offset = 4;
                else if (degree == "SIXTH") offset = 5;
                else if (degree == "SEVENTH") offset = 6;
                else if (degree == "OCTAVE") offset = 0;
            } else {
                if (degree == "SECOND") offset = -1;
                else if (degree == "THIRD") offset = -2;
                else if (degree == "FOURTH") offset = -3;
                else if (degree == "FIFTH") offset = -4;
                else if (degree == "SIXTH") offset = -5;
                else if (degree == "SEVENTH") offset = -6;
                else if (degree == "OCTAVE") offset = 0;
            }

            int idx = ((rootIdx + offset) % 7 + 7) % 7;
            output << root << ": " << dir << " " << degree << " > " << scale[idx]
                   << "\n";
        }

        output << "\n";
    }

    std::cout << output.str();
    return 0;
}