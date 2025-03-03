#include <iostream>
#include <vector>

size_t mod = 1e9+7;

int main() {
    size_t n;
    std::cin >> n;

    size_t sum = 0;
    for (size_t i = 1; i <= n; ++i) {
        sum += i;
    }
    if (sum % 2 != 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    size_t target = sum / 2;

    std::vector<size_t> counts(target+1, 0);
    counts[0] = 1;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = target; j > 0; --j) {
            if (j >= i) {
                counts[j] += counts[j-i];
                counts[j] %= (2*mod);
            }
        }
    }
    std::cout << (counts[target]/2)%mod << "\n";
}