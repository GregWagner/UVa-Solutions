/*
 * Problem 947 - Master Mind Helper
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

bool used[32];

std::vector<int> code;
std::vector<int> guess;
std::vector<int> guessCopy;

void restoreGuess(int n)
{
    for (int i = 0; i < n; ++i) {
        guess[i] = guessCopy[i];
    }
}

void checkCode(int &strong, int &weak)
{
    int n = code.size();
    strong = 0;
    weak = 0;
    for (int i = 0; i < n; ++i) {
        if (code[i] == guess[i]) {
            ++strong;
            guess[i] = 0;
            used[i] = true;
        }
    }

    for (int g = 0; g < n; ++g) {
        for (int c = 0; c < n; ++c) {
            if (used[c]) {
                ;
            } else if (guess[g] == code[c]) {
                ++weak;
                used[c] = true;
                break;
            }
        }
    }
}

bool setupCode(int theCode, int n)
{
    code.clear();
    for (int i = 0; i < n; ++i) {
        used[i] = false;

        code.push_back(theCode % 10);
        theCode /= 10;
        if (code[i] == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int n;
    std::cin >> n;
    for (int test = 0; test < n; ++test) {

        std::string inGuess;
        std::cin >> inGuess;
        guessCopy.clear();

        unsigned inputSize = inGuess.size();
        for (unsigned i = 0; i < inputSize; ++i) {
            char ch = inGuess[i] ;
            guess.push_back(ch - '0');
            guessCopy.push_back(ch - '0');
        }

        int strong {0};
        int weak {0};
        std::cin >> strong >> weak;

        // find starting number
        int startingCode = 1;
        int endingCode = 9;
        unsigned count = 1;
        while  (count < inputSize) {
            ++count;
            startingCode *= 10;
            startingCode += 1;
            endingCode *= 10;
            endingCode += 9;
        }

        int numStrong {0};
        int numWeak {0};
        int numberOfMatches {0};

        for (int number = startingCode; number <= endingCode; ++number) {
            bool valid = setupCode(number, inputSize);
            if (valid) {
                restoreGuess(inputSize);
                checkCode(numStrong, numWeak);
                if ((numStrong == strong) && (numWeak == weak)) {
                    ++numberOfMatches;
                }
            }
        }
        output << numberOfMatches << '\n';
    }
    std::cout << output.str();
}
