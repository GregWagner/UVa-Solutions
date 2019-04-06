/*
 * Prolem 255 - Correct Move
 */
#include <iostream>
#include <sstream>

struct Pair {
	int x;
	int y;
};

Pair m[64];
int board[8][8];

bool isMoveBlocked(int move) {
    Pair mLocation = m[move];
    return (board[mLocation.x][mLocation.y] == 0 ? false : true);
}

bool isStopped(int k, int q) {
    if (k == 0 && q == 9) {
        return true;
    }
    if (k == 7 && q == 14) {
        return true;
    }
    if (k == 56 && q == 49) {
        return true;
    }
    if (k == 63 && q == 54) {
        return true;
    }
    return false;
}

bool isLegalMove(int k, int q, int move) {
    if ((q == move) || (k == move)) {
        return false;
    }

    Pair qLoc = m[q];
    Pair mLoc = m[move];
    Pair kLoc = m[k];

    if ((qLoc.x != mLoc.x) && (qLoc.y != mLoc.y)) {
        return false;
    }

    if (qLoc.x == kLoc.x) {
        if ((qLoc.y > kLoc.y) && (mLoc.y < kLoc.y)) {
            return false;
        }
        if ((qLoc.y < kLoc.y) && (mLoc.y > kLoc.y)) {
            return false;
        }
    } else if (qLoc.y == kLoc.y) {
        if ((qLoc.x > kLoc.x) && (mLoc.x < kLoc.x)) {
            return false;
        }
        if ((qLoc.x < kLoc.x) && (mLoc.x > kLoc.x)) {
            return false;
        }
    }
    return true;;
}

void initialize() {
    for (int i = 0; i < 64; ++i) {
        Pair pair;
        pair.x = i / 8;
        pair.y = i % 8;
        m[i] = pair;
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = 0;
        }
    }
}

void setupBlock(int k) {
    Pair p = m[k];
    board[p.x][p.y] = 2;
    if (p.x > 0) {
        board[p.x - 1][p.y] = 1;
    }
    if (p.x < 7) {
        board[p.x + 1][p.y] = 1;
    }
    if (p.y > 0) {
        board[p.x][p.y - 1] = 1;
    }
    if (p.y < 7) {
        board[p.x][p.y + 1] = 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int king, queen, move;
    while (std::cin >> king >> queen >> move) {
        initialize();
        setupBlock(king);

        if (king == queen) {
            // pieces are in the same place
            output << "Illegal state\n";

        } else if (!isLegalMove(king, queen, move)) {
            // queens move is illegal
            output << "Illegal move\n";

        } else if (isMoveBlocked(move)) {
            output << "Move not allowed\n";
        } else if (isStopped(king, move)) {
            output << "Stop\n";
        } else {
            output << "Continue\n";
        }
    }
    std::cout << output.str();
}
