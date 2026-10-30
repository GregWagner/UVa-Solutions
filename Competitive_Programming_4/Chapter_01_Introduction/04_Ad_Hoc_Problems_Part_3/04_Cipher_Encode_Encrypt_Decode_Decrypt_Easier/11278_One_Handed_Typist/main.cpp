// 11278 - One Handed Typist
#include <iostream>
#include <sstream>

// Standard QWERTY string
const std::string QWERTY = " `1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";

// Corresponding Dvorak string
const std::string DVORAK = " `123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    char mapTable[256];
    for (int i{}; i < 256; ++i) {
        mapTable[i] = static_cast<char>(i);
    }

    for (std::size_t i{}; i < QWERTY.size(); ++i) {
        mapTable[static_cast<unsigned char>(QWERTY[i])] = DVORAK[i];
    }

    std::string input;
    while (std::getline(std::cin, input)) {
        for (char c : input) {
            output << mapTable[static_cast<unsigned char>(c)];
        }
        output << '\n';
    }

    std::cout << output.str();
}
