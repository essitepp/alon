#include <iostream>
#include <stack>

int arr[200001];
int res[200001];

int main() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
    }

    //<value, idx>
    std::stack<std::pair<int, int>> s;

    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = 0;
        } else {
            res[i] = s.top().second;
        }
        s.push({arr[i], i});
    }
    
    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";
}