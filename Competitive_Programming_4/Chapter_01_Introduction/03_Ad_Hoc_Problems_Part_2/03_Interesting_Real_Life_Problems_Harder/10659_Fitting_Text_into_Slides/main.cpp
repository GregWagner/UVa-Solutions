#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Paragraph {
    std::vector<std::string> words;
};

// Simulation function to check if text fits with a given font size
auto checkFit(int fontSize, int boxWidth, int boxHeight,
              const std::vector<Paragraph>& paragraphs) -> bool {
    int lineHeight{fontSize};

    int totalHeight{};
    int currentLineWidth{};

    for (const auto& para : paragraphs) {
        totalHeight += lineHeight;
        if (totalHeight > boxHeight) {
            return false;
        }
        currentLineWidth = 0;

        for (const auto& word : para.words) {
            int wordWidth{static_cast<int>(word.size()) * fontSize};

            if (wordWidth > boxWidth) {
                return false;
            }

            if (currentLineWidth == 0) {
                currentLineWidth = wordWidth;
            } else {
                if (currentLineWidth + fontSize + wordWidth <= boxWidth) {
                    currentLineWidth += fontSize + wordWidth;
                } else {
                    totalHeight += lineHeight;
                    if (totalHeight > boxHeight) {
                        return false;
                    }
                    currentLineWidth = wordWidth;
                }
            }
        }
    }
    return totalHeight <= boxHeight;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }

    std::ostringstream output;

    while (testCases--) {
        int p;
        std::cin >> p;
        std::cin.ignore();

        std::vector<Paragraph> paragraphs(p);
        for (int i{}; i < p; ++i) {
            std::string line;
            std::getline(std::cin, line);
            std::stringstream ss(line);
            std::string word;
            while (ss >> word) {
                paragraphs[i].words.push_back(word);
            }
        }

        int boxWidth, boxHeight;
        std::cin >> boxWidth >> boxHeight;

        int bestSize{-1};
        for (int font{28}; font >= 8; --font) {
            if (checkFit(font, boxWidth, boxHeight, paragraphs)) {
                bestSize = font;
                break;
            }
        }

        if (bestSize != -1) {
            output << bestSize << "\n";
        } else {
            output << "No solution\n";
        }
    }
    std::cout << output.str();
}