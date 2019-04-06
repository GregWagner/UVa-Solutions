/*
 * Skener
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int rows, columns, zRow, zColumn;
    std::cin >> rows >> columns >> zRow >> zColumn;
    char a[50][50];

    for (int i {}; i < rows; ++i) {
        for (int j {}; j < columns; ++j) {
            char temp;
            std::cin >> temp;
            a[i][j] = temp;
        }
    }

    for (int i {}; i < rows; ++i) {
        for (int j {}; j < zRow; ++j) {
            for (int k {}; k < columns; ++k) {
                for (int l {}; l < zColumn; ++l) {
                    output << a[i][k];
                }
            }
            output << '\n';
        }
    }
    std::cout << output.str();
}
