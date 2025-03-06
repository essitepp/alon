#include <iostream>

long long mod = 1e9+7;

int tests[101];
long long towers1[1000001]; //towers with width 1 blocks at bottom
long long towers2[1000001]; //towers with width 2 blocks at bottom

int main() {
    int t;
    std::cin >> t;

    int max_height = 0;
    for (int i = 0; i < t; ++i) {
        std::cin >> tests[i];
        max_height = std::max(max_height, tests[i]);
    }

    towers1[1] = 1;
    towers2[1] = 1;
    for (int h = 2; h <= max_height; ++h) {
        towers2[h] = (2*towers2[h-1]+towers1[h-1])%mod;
        towers1[h] = (towers2[h-1]+4*towers1[h-1])%mod;
    }

    for (int i = 0; i < t; ++i) {
        std::cout << (towers1[tests[i]]+towers2[tests[i]])%mod << "\n";
    }
}