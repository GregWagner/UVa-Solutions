#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct RouteEntry {
    std::string nextHop;
    std::string c;
    std::string admd;
    std::string prmd;
    std::string o;
};

struct Message {
    std::string origMta;
    std::string c;
    std::string admd;
    std::string prmd;
    std::string o;
};

inline bool matchesEntry(const RouteEntry& e, const Message& m) {
    if (e.c != "*" && e.c != m.c)
        return false;
    if (e.admd != "*" && e.admd != m.admd)
        return false;
    if (e.prmd != "*" && e.prmd != m.prmd)
        return false;
    if (e.o != "*" && e.o != m.o)
        return false;
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int mCount;
    int scenario = 1;
    while (std::cin >> mCount) {
        std::map<std::string, std::vector<RouteEntry>> routing;
        for (int i = 0; i < mCount; ++i) {
            std::string mtaName;
            int entries;
            std::cin >> mtaName >> entries;
            std::vector<RouteEntry> vec;
            vec.reserve(entries);
            for (int j = 0; j < entries; ++j) {
                RouteEntry e;
                std::cin >> e.nextHop >> e.c >> e.admd >> e.prmd >> e.o;
                vec.push_back(std::move(e));
            }
            routing[mtaName] = std::move(vec);
        }
        int msgCount;
        if (!(std::cin >> msgCount))
            break;

        std::cout << "Scenario # " << scenario++ << "\n";
        for (int i = 1; i <= msgCount; ++i) {
            Message msg;
            std::cin >> msg.origMta >> msg.c >> msg.admd >> msg.prmd >> msg.o;
            std::string current = msg.origMta;
            std::vector<std::string> visited;
            std::string resultMta;
            enum class Status { Delivered, Loop, Unable };
            Status status = Status::Unable;

            while (true) {
                // circular detection
                if (std::find(visited.begin(), visited.end(), current) !=
                    visited.end()) {
                    status = Status::Loop;
                    resultMta = current;
                    break;
                }
                visited.push_back(current);

                auto it = routing.find(current);
                if (it == routing.end()) {
                    status = Status::Unable;
                    resultMta = current;
                    break;
                }
                const auto& table = it->second;
                bool found = false;
                std::string nextHop;
                for (const auto& e : table) {
                    if (matchesEntry(e, msg)) {
                        nextHop = e.nextHop;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    status = Status::Unable;
                    resultMta = current;
                    break;
                }
                if (nextHop == current) {
                    status = Status::Delivered;
                    resultMta = current;
                    break;
                }
                current = nextHop;
            }

            std::cout << i << " -- ";
            if (status == Status::Delivered) {
                std::cout << "delivered to " << resultMta << "\n";
            } else if (status == Status::Loop) {
                std::cout << "circular routing detected by " << resultMta
                          << "\n";
            } else {
                std::cout << "unable to route at " << resultMta << "\n";
            }
        }
        std::cout << "\n";
    }
}
