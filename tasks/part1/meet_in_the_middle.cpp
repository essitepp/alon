#include <iostream>
#include <vector>
#include <algorithm>

int arr[41];


void subset_sums(long long sum, int i, int n, int arr[], std::vector<long long>& sums) {
    if (i == n) {
        sums.push_back(sum);
    } else {
        subset_sums(sum, i+1, n, arr, sums);
        subset_sums(sum+arr[i], i+1, n, arr, sums);
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<long long> sums1;
    std::vector<long long> sums2;

    subset_sums(0, 0, n/2, arr, sums1);
    subset_sums(0, n/2, n, arr, sums2);

    std::sort(sums1.begin(), sums1.end());
    std::sort(sums2.rbegin(), sums2.rend());

    size_t result = 0;

    size_t i = 0;
    size_t j = 0;
    while (i < sums1.size()) {
        size_t count1 = 1;
        while (i+count1 < sums1.size() && sums1[i+count1] == sums1[i]) ++count1;
        while (j < sums2.size() && sums1[i] + sums2[j] > x) ++j;
        size_t count2 = 0;
        while (j+count2 < sums2.size() && sums1[i] + sums2[j+count2] == x) {
            ++count2;
        }
        result += count1*count2;
        i += count1;
    }

    std::cout << result << "\n";
}