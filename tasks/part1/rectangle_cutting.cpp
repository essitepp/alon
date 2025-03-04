#include <iostream>
#include <limits>

int moves[501][501];

int cut(int a, int b) {
    if (a == b) {
        moves[a][b] = 0;
        return 0;
    }
    if (a < b) {
        std::swap(a, b);
    }

    if (moves[a][b] < std::numeric_limits<int>::max()) {
        return moves[a][b];
    }

    for (int i = 1; i < a; ++i) {
        int count = 1 + cut(i, b) + cut(a-i, b);
        moves[a][b] = std::min(moves[a][b], count);
    }
    for (int j = 1; j < b; ++j) {
        int count = 1 + cut(a, j) + cut(a, b-j);
        moves[a][b] = std::min(moves[a][b], count);
    }
    return moves[a][b];
}

int main() {
    int a,b;
    std::cin >> a >> b;

    if (a < b) {
        std::swap(a,b);
    }

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            moves[i][j] = std::numeric_limits<int>::max();
        }
    }

    std::cout << cut(a,b) << "\n";
}