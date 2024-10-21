#include <iostream>
#include <vector>


int main() {
    size_t n;
    std::cin >> n;
    if (!(n%4==0 || (n+1)%4==0)) {
        std::cout << "NO\n";
        return 0;
    }
    std::vector<size_t> s1;
    std::vector<size_t> s2;

    size_t x = 1;
    if (n%4 != 0) {
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
        x = 4;
    }
    while (x <= n) {
        s1.push_back(x++);
        s2.push_back(x++);
        s2.push_back(x++);
        s1.push_back(x++);
    }

    std::cout << "YES\n";
    std::cout << s1.size() << "\n";
    for (auto val : s1) std::cout << val << " ";
    std::cout << "\n" << s2.size() << "\n";
    for (auto val : s2) std::cout << val << " ";
    std::cout << "\n";
}