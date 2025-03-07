#include <iostream>
#include <algorithm>
#include <cmath>

int sticks[200001];


int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> sticks[i];
    }

    std::sort(sticks, sticks+n);

    int target_length = sticks[n/2];

    long long cost = 0;

    for (int i = 0; i < n; ++i) {
        cost += std::abs(target_length-sticks[i]);
    }

    std::cout << cost << "\n";
}