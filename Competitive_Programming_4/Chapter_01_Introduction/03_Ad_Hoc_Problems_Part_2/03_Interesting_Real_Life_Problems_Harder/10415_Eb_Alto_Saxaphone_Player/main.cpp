// 10415 Eb Alto Saxaphone Player
#include <iostream>
#include <sstream>
#include <vector>

auto needsFinger(char note, int finger) -> bool {
    switch (note) {
    case 'c':
        return (finger >= 2 && finger <= 4) || (finger >= 7 && finger <= 10);
    case 'd':
        return (finger >= 2 && finger <= 4) || (finger >= 7 && finger <= 9);
    case 'e':
        return (finger >= 2 && finger <= 4) || (finger == 7 || finger == 8);
    case 'f':
        return (finger >= 2 && finger <= 4) || (finger == 7);
    case 'g':
        return (finger >= 2 && finger <= 4);
    case 'a':
        return (finger == 2 || finger == 3);
    case 'b':
        return (finger == 2);
    case 'C':
        return (finger == 3);
    case 'D':
        return (finger >= 1 && finger <= 4) || (finger >= 7 && finger <= 9);
    case 'E':
        return (finger >= 1 && finger <= 4) || (finger == 7 || finger == 8);
    case 'F':
        return (finger >= 1 && finger <= 4) || (finger == 7);
    case 'G':
        return (finger >= 1 && finger <= 4);
    case 'A':
        return (finger >= 1 && finger <= 3);
    case 'B':
        return (finger == 1 || finger == 2);
    default:
        return false;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    std::string dummy;
    std::getline(std::cin, dummy);
    while (testCases--) {
        std::string song;
        std::getline(std::cin, song);

        std::vector<int> counts(11, 0);
        std::vector<bool> isfingerDown(11, false);

        for (auto note : song) {
            for (int finger{1}; finger <= 10; ++finger) {
                bool shouldBeDown = needsFinger(note, finger);
                if (shouldBeDown && !isfingerDown[finger]) {
                    ++counts[finger];
                    isfingerDown[finger] = true;
                } else if (!shouldBeDown && isfingerDown[finger]) {
                    isfingerDown[finger] = false;
                }
                // if state matches, do nothing
            }
        }
        for (int finger{1}; finger <= 10; ++finger) {
            output << counts[finger] << (finger == 10 ? "" : " ");
        }
        output << '\n';
    }
    std::cout << output.str();
}
