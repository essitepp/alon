#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    size_t count = 0;
    for (size_t l = 1; l <= k; ++l) {
        count += n-l+1;
    }

    std::vector<size_t> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    std::map<size_t, size_t> counts;
    std::set<size_t> values;
    for (size_t l = k+1; l <= n; ++l) {
        bool valid = true;
        for (size_t i = 0; i < l; ++i) {
            size_t value = array[i];
            counts[value]++;
            values.insert(value);
            if (values.size() > k) {
                valid = false;
            }
        }
        if (valid) ++count;
        for (size_t i = l; i < n; ++i) {
            size_t remove = array[i-l];
            counts[remove]--;
            if (counts[remove] == 0) {
                values.erase(remove);
            }
            size_t add = array[i];
            counts[add]++;
            values.insert(add);
            valid = values.size() <= k;
            if (valid) ++count;
        }
        counts.clear();
        values.clear();
    }

    std::cout << count << "\n";
}