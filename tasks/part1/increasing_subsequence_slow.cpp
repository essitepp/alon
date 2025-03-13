#include <iostream>

int arr[200001];
int l[200001];

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
    }

    
    l[1] = 1;
    int longest = 1;

    for (int i = 2; i <= n; ++i) {
        l[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]) {
                l[i] = std::max(l[i], l[j]+1);
            }
        }
        longest = std::max(longest, l[i]);
    }

    std::cout << longest << "\n";
}