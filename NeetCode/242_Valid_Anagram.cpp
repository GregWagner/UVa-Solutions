#include <bits/stdc++.h>

class Solution {
public:
  bool isAnagram1(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
  }

  // using hashmap
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::unordered_map<char, int> map;
    for (auto c : s) {
      map[c]++;
    }
    for (auto c : t) {
      map[c]--;
    }
    for (auto m : map) {
      if (m.second != 0) {
        return false;
      }
    }
    return true;
  }

  // using hashmap counts
  bool isAnagram3(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::unordered_map<char, int> countS;
    std::unordered_map<char, int> countT;
    for (int i{}; i < s.size(); ++i) {
      countS[s[i]]++;
      countT[t[i]]++;
    }
    return countS == countT;
  }

  // using array
  bool isAnagram4(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::vector<int> count(26, 0);
    for (int i{}; i < s.size(); ++i) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }

    for (int val : count) {
      if (val != 0) {
        return false;
      }
    }
    return true;
  }
};
