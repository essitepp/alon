#include <iostream>
#include <vector>
#include <map>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::vector<size_t> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    std::map<size_t, size_t> counts;

    //window [l, r]
    size_t l = 0;
    size_t r = 0;

    //start with first value added
    counts[array[0]] = 1;
    size_t values = 1;

    size_t count = 1;

    while (r < n-1) {
        //extend right side as far as possible
        while (r < n-1 && (values < k || counts[array[r+1]] > 0)) {
            ++r;  
            ++counts[array[r]];
            if (counts[array[r]] == 1) {
                ++values;
            }
            //count subarrays ending at r
            count += r-l+1;
        }
        //move left side until there is room for a new value
        while (values == k) {
            --counts[array[l]];
            if (counts[array[l]] == 0) {
                --values;
            }
            ++l;
        }
    }

    std::cout << count << "\n";
}