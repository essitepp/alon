#include <iostream>
#include <vector>


int main() {
    size_t n;
    std::cin >> n;

    std::vector<size_t> collected(n+1, false);
    size_t loops = 0;
    size_t x;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> x;
        if (!collected[x-1]) ++loops;
        collected[x] = true;
    }

    std::cout << loops << "\n";
}