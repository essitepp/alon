#include <iostream>


int main() {
    size_t n;
    std::cin >> n;

    size_t moves = 0;
    size_t min_val = 1;
    size_t x;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> x;
        if (x < min_val) moves += min_val - x;
        min_val = std::max(min_val, x);
    }
    std::cout << moves << "\n";
}