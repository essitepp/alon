#include <iostream>
#include <vector>



void find_next(size_t& i, size_t k, const std::vector<size_t>& removed) {
    size_t n = removed.size()-1;
    for (size_t j = 0; j < k+1; ++j) {
        ++i;
        if (i > n) i = 1;
        while(removed[i]) {
            ++i;
            if (i > n) i = 1;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);  
      
    size_t n, k;
    std::cin >> n >> k;

    std::vector<size_t> removed(n+1, false);
    size_t remaining = n;
    std::vector<size_t> result;

    size_t i = 0;
    while (true) {
        find_next(i, k, removed);
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