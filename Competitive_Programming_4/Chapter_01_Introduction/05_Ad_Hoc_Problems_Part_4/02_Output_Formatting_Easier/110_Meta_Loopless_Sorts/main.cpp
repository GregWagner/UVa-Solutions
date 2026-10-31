#include <iostream>
#include <vector>

int n;

auto printIndent(int depth) -> void {
    for (int i{}; i < depth; ++i) {
        std::cout << "  ";
    }
}

auto printWriteln(const std::vector<char>& v) -> void {
    printIndent(static_cast<int>(v.size()));
    std::cout << "writeln(";
    for (size_t i{}; i < v.size(); ++i) {
        if (i) std::cout << ',';
        std::cout << v[i];
    }
    std::cout << ")\n";
}

void generateCode(std::vector<char>& perm, int k) {
    if (k == n) {
        printWriteln(perm);
        return;
    }
    char c = static_cast<char>('a' + k);
    int sz = static_cast<int>(perm.size());
    for (int i = sz - 1; i >= 0; --i) {
        if (i == sz - 1) {
            printIndent(sz);
            std::cout << "if " << perm[i] << " < " << c << " then\n";
        } else {
            printIndent(sz);
            std::cout << "else if " << perm[i] << " < " << c << " then\n";
        }
        std::vector<char> nextPerm = perm;
        nextPerm.insert(nextPerm.begin() + i + 1, c);
        generateCode(nextPerm, k + 1);
    }
    printIndent(sz);
    std::cout << "else\n";
    std::vector<char> nextPerm;
    nextPerm.push_back(c);
    nextPerm.insert(nextPerm.end(), perm.begin(), perm.end());
    generateCode(nextPerm, k + 1);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) return 0;
    while (testCases--) {
        std::cin >> n;
        std::cout << "program sort(input,output);\nvar\n";
        for (int i{}; i < n; ++i) {
            std::cout << char('a' + i);
            if (i + 1 < n) std::cout << ',';
        }
        std::cout << " : integer;\nbegin\n  readln(";
        for (int i{}; i < n; ++i) {
            std::cout << char('a' + i);
            if (i + 1 < n) std::cout << ',';
        }
        std::cout << ");\n";
        if (n == 1) {
            printIndent(1);
            std::cout << "writeln(a)\n";
        } else {
            std::vector<char> init;
            init.push_back('a');
            generateCode(init, 1);
        }
        std::cout << "end.\n";
        if (testCases > 0) std::cout << "\n";
    }
}
