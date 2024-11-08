#include <iostream>
#include <vector>

void find_next(size_t& i, const std::vector<size_t>& removed) {
    size_t n = removed.size()-1;
    ++i;
    if (i > n) i = 1;
    while(removed[i]) {
        ++i;
        if (i > n) i = 1;
    }
}

int main() {
    size_t n;
    std::cin >> n;

    std::vector<size_t> removed(n+1, false);
    size_t remaining = n;
    std::vector<size_t> result;

    size_t i = 0;
    while (true) {
        find_next(i, removed);
        find_next(i, removed);
        removed[i] = true;
        result.push_back(i);
        --remaining;
        if (remaining == 0) {
            break;
        }
    }
    for (size_t val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}