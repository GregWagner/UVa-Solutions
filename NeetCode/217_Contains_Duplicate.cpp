#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
  // Brute Force Solution
  bool hasDuplicate1(std::vector<int>& numbers) {
    for (int i{}; i < numbers.size(); i++) {
      for (int j{i + 1}; j < numbers.size(); j++) {
        if (numbers[i] == numbers[j]) {
          return true;
        }
      }
    }
    return false;
  }

  // Sort and Check
  bool hasDuplicate2(std::vector<int>& numbers) {
    std::sort(numbers.begin(), numbers.end());
    for (int i{}; i < numbers.size() - 1; i++) {
      if (numbers[i] == numbers[i + 1]) {
        return true;
      }
    }
    return false;
  }

  // Using a hashset
  bool hasDuplicate3(std::vector<int>& numbers) {
    std::unordered_set<int> hasSeen;
    for (auto number : numbers) {
      if (hasSeen.find(number) != hasSeen.end()) {
        return true;
      }
      hasSeen.insert(number);
    }
    return false;
  }

  // Using a hashset length
  bool hasDuplicate(std::vector<int>& numbers) {
    return numbers.size() != std::unordered_set<int>(numbers.begin(), numbers.end()).size();
  }
};