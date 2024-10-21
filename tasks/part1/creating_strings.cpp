#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());

    std::vector<std::string> res;
    res.push_back(s);

    int n = s.length();

    while (true) {
        int i = n-1;
        while (i >= 0 && !(s[i] < s[i+1])) --i;
        if (i < 0) break;

        int j = n-1;
        while (!(s[j] > s[i])) --j;

        std::swap(s[i], s[j]);

        ++i;
        j = n-1;
        while (i < j) {
            std::swap(s[i], s[j]);
            ++i; --j;
        }
        res.push_back(s);
    }
    std::cout << res.size() << "\n";
    for (auto s : res) {
        std::cout << s << "\n";
    }
}
