#include <iostream>
#include <set>
#include <vector>

int main() {
    size_t n, m;
    std::cin >> n >> m;

    std::multiset<int> tickets;
    int price;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> price;
        tickets.insert(-price);
    }
    std::vector<int> result;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> price;
        auto it = tickets.lower_bound(-price);
        if (it == tickets.end()) {
            result.push_back(-1);
        } else {
            result.push_back(-(*it));
            tickets.erase(it);
        }
    }
    for (auto val : result) {
        std::cout << val << "\n";
    }
}