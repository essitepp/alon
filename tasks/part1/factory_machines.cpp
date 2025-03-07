#include <iostream>
#include <limits>

long long times[200001];

long long products(long long time, int n) {
    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        count += time/times[i];
    }
    return count;
}

int main() {
    int n, t;
    std::cin >> n >> t;

    long long fastest_time = std::numeric_limits<long long>::max();
    for (int i = 1; i <= n; ++i) {
        std::cin >> times[i];
        fastest_time = std::min(fastest_time, times[i]);
    }

    long long time = 0;
    long long m = fastest_time*t;
    for (long long b = m; b >= 1; b /= 2) {
        while (products(time+b, n) < t) time += b;
    }

    std::cout << time+1 << "\n";
}