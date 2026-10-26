// 10033 Interpreter
#include <array>
#include <iostream>
#include <sstream>
#include <string>

constexpr int kRegCount{10};
constexpr int kMemSize{1000};
constexpr int kModulo{1000};

struct Machine {
    std::array<int, kRegCount> reg{};
    std::array<int, kMemSize> ram{};
    int pc{};
};

// Executes the instruction at m.pc, then advances or jumps m.pc.
void execute(Machine& m, int instruction) {
    ++m.pc;

    // op = hundreds digit, x = tens digit, y = units digit
    const int op = instruction / 100;
    const int x = (instruction / 10) % 10;
    const int y = instruction % 10;

    switch (op) {
    case 0:
        if (m.reg[y] != 0) {
            m.pc = m.reg[x];
        }
        break;
    case 2:
        m.reg[x] = y;
        break;
    case 3:
        m.reg[x] = (m.reg[x] + y) % kModulo;
        break;
    case 4:
        m.reg[x] = (m.reg[x] * y) % kModulo;
        break;
    case 5:
        m.reg[x] = m.reg[y];
        break;
    case 6:
        m.reg[x] = (m.reg[x] + m.reg[y]) % kModulo;
        break;
    case 7:
        m.reg[x] = (m.reg[x] * m.reg[y]) % kModulo;
        break;
    case 8:
        m.reg[x] = m.ram[m.reg[y]];
        break;
    case 9:
        m.ram[m.reg[y]] = m.reg[x];
        break;
    default:
        // 100 (halt) is handled by run(); other opcodes never occur.
        break;
    }
}

// Runs the loaded program, returning instructions executed incl. the halt.
auto run(Machine& m) -> int {
    int count{};
    while (m.ram[m.pc] != 100) {
        execute(m, m.ram[m.pc]);
        ++count;
    }
    return count + 1;
}

// Loads one program: 3-digit words (one or more per line), up to and
// including any words after the halt -- the official sample pads the program
// with 000s. The program ends at a blank line or at end of input.
void load(Machine& m) {
    int index = 0;
    bool started = false;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream words(line);
        int word = 0;
        bool hasWord = false;
        while (words >> word) {
            if (index < kMemSize) {
                m.ram[index++] = word;
            }
            hasWord = true;
        }
        if (!hasWord) {
            if (started) {
                break;  // blank line: end of this program
            }
            continue;   // blank line before it, i.e. after the case count
        }
        started = true;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }

    for (int tc = 0; tc < testCases; ++tc) {
        Machine m;

        load(m);

        // execute
        const int count = run(m);
        if (tc) {
            output << '\n';
        }
        output << count << '\n';
    }

    std::cout << output.str();
}
