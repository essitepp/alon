#include <iostream>
#include <limits>

int cuts[501][501];


int main() {
    int a1,b1;
    std::cin >> a1 >> b1;

    if (a1 == b1) {
        std::cout << 0 << "\n";
        return 0;
    }

    if (a1 > b1) std::swap(a1, b1);

    for (int a = 1; a <= a1; ++a) {
        for (int b = a; b <= b1; ++b) {
            if (a == b) continue;

            int best = std::numeric_limits<int>::max();

            for (int i = 1; i < a; ++i) {
                int count = 1 + cuts[i][b] + cuts[a-i][b];
                best = std::min(best, count);
            }
            for (int j = 1; j < b; ++j) {
                int count = 1 + cuts[a][j] + cuts[a][b-j];
                best = std::min(best, count);
            }

            cuts[a][b] = best;
            cuts[b][a] = best;
        }
    }

    std::cout << cuts[a1][b1];
}