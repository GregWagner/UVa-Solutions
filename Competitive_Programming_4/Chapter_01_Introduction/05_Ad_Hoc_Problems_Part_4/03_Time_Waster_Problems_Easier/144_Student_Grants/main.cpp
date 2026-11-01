// 144 Student Grants
#include <iostream>
#include <iomanip>
#include <queue>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfStudents, limit;
    while (std::cin >> numberOfStudents >> limit && numberOfStudents != 0 &&
           limit != 0) {

        std::queue<int> studentIds;
        for (int i{1}; i <= numberOfStudents; ++i) {
            studentIds.push(i);
        }

        std::vector<int> amountCollected(numberOfStudents + 1, 0);
        int store{};
        int nextGrant{1};

        while (!studentIds.empty()) {
            if (store == 0) {
                store = nextGrant;
                ++nextGrant;
                if (nextGrant > limit) {
                    nextGrant = 1;
                }
            }

            int student{studentIds.front()};
            studentIds.pop();

            int amountNeeded{40 - amountCollected[student]};

            if (store <= amountNeeded) {
                amountCollected[student] += store;
                store = 0;

                if (amountCollected[student] == 40) {
                    output << std::setw(3) << student;
                } else {
                    studentIds.push(student);
                }
            } else { // store > needed
                amountCollected[student] = 40;
                store -= amountNeeded;
                output << std::setw(3) << student;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}