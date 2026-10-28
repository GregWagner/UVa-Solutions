// 11223 Ou ah dah dah
#include <iostream>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, char> morseMap = {
    {".-", 'A'},     {"-...", 'B'},   {"-.-.", 'C'},   {"-..", 'D'},
    {".", 'E'},      {"..-.", 'F'},   {"--.", 'G'},    {"....", 'H'},
    {"..", 'I'},     {".---", 'J'},   {"-.-", 'K'},    {".-..", 'L'},
    {"--", 'M'},     {"-.", 'N'},     {"---", 'O'},    {".--.", 'P'},
    {"--.-", 'Q'},   {".-.", 'R'},    {"...", 'S'},    {"-", 'T'},
    {"..-", 'U'},    {"...-", 'V'},   {".--", 'W'},    {"-..-", 'X'},
    {"-.--", 'Y'},   {"--..", 'Z'},   {"-----", '0'},  {".----", '1'},
    {"..---", '2'},  {"...--", '3'},  {"....-", '4'},  {".....", '5'},
    {"-....", '6'},  {"--...", '7'},  {"---..", '8'},  {"----.", '9'},
    {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'}, {".----.", '\''},
    {"-.-.--", '!'}, {"-..-.", '/'},  {"-.--.", '('},  {"-.--.-", ')'},
    {".-...", '&'},  {"---...", ':'}, {"-.-.-.", ';'}, {"-...-", '='},
    {".-.-.", '+'},  {"-....-", '-'}, {"..--.-", '_'}, {".-..-.", '\"'},
    {".--.-.", '@'}};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int messageNumber{1};
    int testCases;
    std::cin >> testCases;
    std::string dummy;
    std::getline(std::cin, dummy); // consume newline after test cases count
    while (testCases--) {
        std::string message;
        std::getline(std::cin, message);
        // if message is empty (blank line), try to read again
        if (message.empty()) {
            std::getline(std::cin, message);
        }

        if (messageNumber > 1) {
            output << '\n';
        }
        output << "Message #" << messageNumber++ << '\n';

        std::string decodedMessage{};
        std::string currentToken{};
        for (size_t i{}; i < message.size(); ) {
            if (message[i] == ' ') {
                size_t j = i;
                while (j < message.size() && message[j] == ' ') {
                    ++j;
                }
                int spaceCount = static_cast<int>(j - i);
                if (!currentToken.empty()) {
                    if (morseMap.count(currentToken)) {
                        decodedMessage += morseMap[currentToken];
                    }
                    currentToken.clear();
                }
                if (spaceCount >= 2) {
                    decodedMessage += ' ';
                }
                i = j;
            } else {
                currentToken += message[i];
                ++i;
            }
        }
        if (!currentToken.empty()) {
            if (morseMap.count(currentToken)) {
                decodedMessage += morseMap[currentToken];
            }
            currentToken.clear();
        }
        output << decodedMessage << '\n';
    }
    std::cout << output.str();
}
