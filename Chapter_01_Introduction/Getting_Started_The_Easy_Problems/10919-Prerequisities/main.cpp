/*
 * Problem 10919 - Prerequistes?
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int numberOfCourses;
    while (std::cin >> numberOfCourses && numberOfCourses != 0) {
        bool valid {true};
        int courses[105];
        int numberOfCategories;
        std::cin >> numberOfCategories;
        for (int i = 0; i < numberOfCourses; ++i) {
            std::cin >> courses[i];
        }
        for (int i = 0; i < numberOfCategories; ++i) {
            int required;
            int coursesInCategory;
            std::cin >> coursesInCategory >> required;
            for (int j = 0; j < coursesInCategory; ++j) {
                int course;
                std::cin >> course;
                for (int k = 0; k < numberOfCourses; ++k) {
                    if (courses[k] == course) {
                        --required;
                    }
                }
            }
            if (required > 0) {
                valid = false;
            }
        }
        output << (valid ? "yes" : "no") << '\n';
    }
    std::cout << output.str();
}
