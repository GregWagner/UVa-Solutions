/*
 * Problems 10284 - Chessboard in FEN
 */
#include <iostream>
#include <sstream>
#include <cctype>

char board[10][10];

void checkBlackPawn(int x, int y)
{
	if (board[x + 1][y - 1] == '.') {
		board[x + 1][y - 1] = '#';
	}
	if (board[x + 1][y + 1] == '.') {
		board[x + 1][y + 1] = '#';
	}
}

void checkWhitePawn(int x, int y)
{
	if (board[x - 1][y - 1] == '.') {
		board[x - 1][y - 1] = '#';
	}
	if (board[x - 1][y + 1] == '.') {
		board[x - 1][y + 1] = '#';
	}
}

void checkRook(int x, int y)
{
	// check to the right
	int index = y + 1;
	bool done {false};
	while (!done) {
		if (board[x][index] == '.' || board[x][index] == '#') {
			board[x][index] = '#';
		} else {
			done = true;
		}
		if (++index > 9) {
			done = true;
		}
	}

	// check to the left
	done = false;
	index = y - 1;
	while (!done) {
		if (board[x][index] == '.' || board[x][index] == '#') {
			board[x][index] = '#';
		} else {
			done = true;
		}
		if (--index <= 0) {
			done = true;
		}
	}

	// check up
	done = false;
	index = x - 1;
	while (!done) {
		if (board[index][y] == '.' || board[index][y] == '#') {
			board[index][y] = '#';
		} else {
			done = true;
		}
		if (--index <= 0) {
			done = true;
		}
	}

	// check down
	done = false;
	index = x + 1;
	while (!done) {
		if (board[index][y] == '.' || board[index][y] == '#') {
			board[index][y] = '#';
		} else {
			done = true;
		}
		if (++index > 9) {
			done = true;
		}
	}
}

void checkKnight(int x, int y)
{
	if (x >= 2) {
		if (board[x - 2][y + 1] == '.') {
			board[x - 2][y + 1] = '#';
		}
		if (board[x - 2][y - 1] == '.') {
			board[x - 2][y - 1] = '#';
		}
	}

	if (y >= 2) {
		if (board[x + 1][y - 2] == '.') {
			board[x + 1][y - 2] = '#';
		}
		if (board[x - 1][y - 2] == '.') {
			board[x - 1][y - 2] = '#';
		}
	}

	if (x < 8) {
		if (board[x + 2][y - 1] == '.') {
			board[x + 2][y - 1] = '#';
		}
		if (board[x + 2][y + 1] == '.') {
			board[x + 2][y + 1] = '#';
		}
	}

	if (y < 8) {
		if (board[x + 1][y + 2] == '.') {
			board[x + 1][y + 2] = '#';
		}

		if (board[x - 1][y + 2] == '.') {
			board[x - 1][y + 2] = '#';
		}
	}
}

void checkBishop(int x, int y)
{
	// check up and to the left
	bool done = false;
	int xIndex = x - 1;
	int yIndex = y - 1;
	while (!done) {
		if (board[xIndex][yIndex] == '.' || board[xIndex][yIndex] == '#') {
			board[xIndex][yIndex] = '#';
		} else {
			done = true;
		}
		if (--xIndex <= 0) {
			done = true;
		}
		if (--yIndex <= 0) {
			done = true;
		}
	}

	// check up and to the right
	done = false;
	xIndex = x + 1;
	yIndex = y - 1;
	while (!done) {
		if (board[xIndex][yIndex] == '.' || board[xIndex][yIndex] == '#') {
			board[xIndex][yIndex] = '#';
		} else {
			done = true;
		}
		if (++xIndex > 9) {
			done = true;
		}
		if (--yIndex <= 0) {
			done = true;
		}
	}

	// check down and to the left
	done = false;
	xIndex = x - 1;
	yIndex = y + 1;
	while (!done) {
		if (board[xIndex][yIndex] == '.' || board[xIndex][yIndex] == '#') {
			board[xIndex][yIndex] = '#';
		} else {
			done = true;
		}
		if (--xIndex <= 0) {
			done = true;
		}
		if (++yIndex > 9) {
			done = true;
		}
	}

	// check down and to the right
	done = false;
	xIndex = x + 1;
	yIndex = y + 1;
	while (!done) {
		if (board[xIndex][yIndex] == '.' || board[xIndex][yIndex] == '#') {
			board[xIndex][yIndex] = '#';
		} else {
			done = true;
		}
		if (++xIndex > 9) {
			done = true;
		}
		if (++yIndex > 9) {
			done = true;
		}
	}
}

void checkQueen(int x, int y)
{
	// queen acts like a rook and a bishop
	checkRook(x, y);
	checkBishop(x, y);
}

void checkKing(int x, int y)
{
	if (board[x - 1][y - 1] == '.') {
		board[x - 1][y - 1] = '#';
	}
	if (board[x - 1][y] == '.') {
		board[x - 1][y] = '#';
	}
	if (board[x - 1][y + 1] == '.') {
		board[x - 1][y + 1] = '#';
	}
	if (board[x][y - 1] == '.') {
		board[x][y - 1] = '#';
	}
	if (board[x][y + 1] == '.') {
		board[x][y + 1] = '#';
	}
	if (board[x + 1][y - 1] == '.') {
		board[x + 1][y - 1] = '#';
	}
	if (board[x + 1][y] == '.') {
		board[x + 1][y] = '#';
	}
	if (board[x + 1][y + 1] == '.') {
		board[x + 1][y + 1] = '#';
	}
}

void intializeBoard()
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			board[i][j] = '.';
		}
	}
}

void printBoard() 
{
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			std::cout << board[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

void checkBoard()
{
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			switch (board[i][j]) {
				case 'p':
					checkBlackPawn(i, j);
					break;

				case 'P':
					checkWhitePawn(i, j);
					break;

				case 'n':
				case 'N':
					checkKnight(i, j);
					break;

				case 'b':
				case 'B':
					checkBishop(i, j);
					break;

				case 'r':
				case 'R':
					checkRook(i, j);
					break;

				case 'q':
				case 'Q':
					checkQueen(i, j);
					break;

				case 'k':
				case 'K':
					checkKing(i, j);
					break;
			}
		}
	}
}

int countEmpty()
{
	int count {0};

	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (board[i][j] == '.') {
				++count;
			}
		}
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::ostringstream output;

	std::string s;
	while (std::cin >> s) {
		intializeBoard();
		int row {1};
		int col {1};
		for (unsigned i = 0; i < s.length(); ++i) {
			if (std::isdigit(s[i])) {
				col += std::atoi(&s[i]);
			} else if (s[i] == '/') {
				++row;
				col = 1;
			} else {
				board[row][col++] = s[i];
			}
		}
		checkBoard();
		printBoard();
		output << countEmpty() << '\n';;
	}
	std::cout << output.str();
}
