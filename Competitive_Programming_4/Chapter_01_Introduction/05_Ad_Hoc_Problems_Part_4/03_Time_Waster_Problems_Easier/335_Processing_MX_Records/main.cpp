#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

static bool isLive(const std::map<std::string, bool>& status,
                   const std::string& machine) {
    auto it = status.find(machine);
    return it != status.end() && it->second;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }
    std::cin.ignore(1000000, '\n');

    std::map<std::string, std::multimap<int, std::string>> records;
    std::map<std::string, bool> status;
    std::string lastDomain;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string tok;
        while (iss >> tok) tokens.push_back(tok);

        std::string domain, host;
        int preference = 0;

        if (tokens.size() >= 3) {
            domain = tokens[0];
            preference = std::stoi(tokens[1]);
            host = tokens[2];
            lastDomain = domain;
        } else if (tokens.size() == 2) {
            domain = lastDomain;
            preference = std::stoi(tokens[0]);
            host = tokens[1];
        } else {
            continue;
        }

        records[domain].insert(std::make_pair(preference, host));
        status[domain] = true;
        status[host] = true;
    }

    std::string output;
    std::string line;
    while (std::getline(std::cin, line)) {
        // Skip blank lines.
        std::string trimmed = line;
        // Find first non-space.
        std::size_t pos = trimmed.find_first_not_of(" \t\r");
        if (pos == std::string::npos) continue;
        if (trimmed[pos] == 'X') break;

        char option = trimmed[pos];
        std::istringstream iss(trimmed.substr(pos));
        std::string machine;
        if (option == 'U' || option == 'D') {
            iss >> option >> machine;
            if (status.find(machine) != status.end()) {
                status[machine] = (option == 'U');
            } else if (status.find("*." + machine) != status.end()) {
                status["*." + machine] = (option == 'U');
            }
        } else if (option == 'A') {
            iss >> option >> machine;

            output += machine;
            output += " =>";

            bool found = false;
            int minPreference = 0;
            std::string destination;

            auto itExact = records.find(machine);
            if (itExact != records.end()) {
                for (const auto& rec : itExact->second) {
                    if (isLive(status, rec.second)) {
                        minPreference = rec.first;
                        destination = rec.second;
                        found = true;
                        break;
                    }
                }
            }

            auto itStar = records.find("*");
            if (itStar != records.end()) {
                for (const auto& rec : itStar->second) {
                    if (!isLive(status, rec.second)) continue;
                    if (!found) {
                        minPreference = rec.first;
                        destination = rec.second;
                        found = true;
                    } else if (rec.first < minPreference) {
                        minPreference = rec.first;
                        destination = rec.second;
                    }
                }
            }

            for (std::string::size_type start = machine.find('.', 0);
                 start != std::string::npos;
                 start += 1, start = machine.find('.', start)) {
                std::string suffix = machine.substr(start);
                std::string key = "*" + suffix;
                auto itWc = records.find(key);
                if (itWc == records.end()) continue;
                for (const auto& rec : itWc->second) {
                    if (!isLive(status, rec.second)) continue;
                    if (!found) {
                        minPreference = rec.first;
                        destination = rec.second;
                        found = true;
                    } else if (rec.first < minPreference) {
                        minPreference = rec.first;
                        destination = rec.second;
                    }
                }
            }

            if (found) {
                output += " ";
                output += destination;
            }
            output += "\n";
        }
    }

    std::cout << output;
    return 0;
}