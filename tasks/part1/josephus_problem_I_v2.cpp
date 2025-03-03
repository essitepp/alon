#include <iostream>
#include <vector>


int main() {
    size_t n;
    std::cin >> n;

    std::vector<size_t> next(n+1);
    for (size_t i = 1; i < n; ++i) {
        next[i] = i+1;
    }
    next[n] = 1;

    std::vector<size_t> removed;
    size_t child = 1;

    
    while (removed.size() < n) {
        size_t next_child = next[child];
        next[child] = next[next_child];
        removed.push_back(next_child);
        child = next[child];
    }

    for (auto child : removed) {
        std::cout << child << " ";
    }
    std::cout << "\n";
}