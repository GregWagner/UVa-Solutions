/*
 * Problem 10919 - Prerequisities
 */

#include <iostream>
#include <sstream>
#include <map>

int main()
{
    std::ostringstream output;
    std::map<int, int> coursesTaken;
    int categoriesCount[110];

    int numberOfCourses, numberOfCategories;
    while (std::cin >> numberOfCourses) {       // 1 <= k 1 < 100
        if (numberOfCourses == 0)
            break;
        
        coursesTaken.clear();
        std::cin >> numberOfCategories;         // 0 <= m < 100

        int course;
        for (int i = 0; i < numberOfCourses; ++i) {
            std::cin >> course;
            coursesTaken[course] = 1;
        }

        bool met = true;
        for (int i = 0; i < numberOfCategories; ++i) {
            int  count, requirementCount = 0; 
            std::cin >> count;
            std::cin >> categoriesCount[i];      // save # required to take

            for (int j = 0; j < count; ++j) {
                std::cin >> course;
                if (coursesTaken[course] == 1)
                    ++requirementCount;
            }
            if (requirementCount < categoriesCount[i])
                met = false;
        }
        output << (met ? "yes\n" : "no\n");
    }
    std::cout << output.str();
}
