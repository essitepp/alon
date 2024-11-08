#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<size_t> coins(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());

    size_t smallest_missing = 1;
    for (size_t coin : coins) {
        if (coin > smallest_missing) {
            break;
        }
        smallest_missing += coin;
    }
    std::cout << smallest_missing << "\n";
}